#include "GLWidget.h"

#include "GLWidgetSet.h"

//Min and max zoom ratio (relative)
const float GL_MAX_ZOOM = 50.f;
const float GL_MIN_ZOOM = 0.01f;

using namespace Cloud_;
using namespace std;

GLWidget::GLWidget(int idx, GLWidgetSet *theSet, const QGLWidget *shared) : QGLWidget(NULL,shared)
  , m_font(font())
  , m_bDrawMessages(true)
  , m_interactionMode(TRANSFORM_CAMERA)
  , m_bFirstAction(true)
  , m_params(ViewportParameters())
  , m_GLData(NULL)
  , m_bDisplayMode2D(false)
  , _frameCount(0)
  , _previousTime(0)
  , _currentTime(0)
  , _idx(idx)
  , _parentSet(theSet)
{
    resetRotationMatrix();

    _time.start();

    setFocusPolicy(Qt::StrongFocus);

    //drag & drop handling
    setAcceptDrops(true);

    m_glPosition[0] = m_glPosition[1] = 0.f;

    _mvmatrix   = new GLdouble[16];
    _projmatrix = new GLdouble[16];
    _glViewport = new GLint[4];

    setMouseTracking(true);   

    ConstructListMessages(m_bDrawMessages);
}

GLWidget::~GLWidget()
{
    delete [] _mvmatrix;
    delete [] _projmatrix;
    delete [] _glViewport;

    //m_GLData is deleted by Engine
}

void GLWidget::resizeGL(int width, int height)
{
    if (width==0 || height==0) return;

    m_glRatio  = (float) width/height;

    glViewport( 0, 0, width, height );
    glGetIntegerv (GL_VIEWPORT, _glViewport);

    if (hasDataLoaded() && !m_GLData->isImgEmpty())
        zoomFit();
}

//-------------------------------------------------------------------------
// Computes the frames rate
//-------------------------------------------------------------------------
void GLWidget::computeFPS(MessageToDisplay &dynMess)
{
    float       fps;

    //  Increase frame count
    _frameCount++;

    _currentTime = _time.elapsed();

    //  Compute elapsed time
    int deltaTime = _currentTime - _previousTime;

    if(deltaTime > 1000)
    {
        //  compute the number of frames per second
        fps = _frameCount * 1000.f / deltaTime;

        //  Set time
        _previousTime = _currentTime;

        //  Reset frame count
        _frameCount = 0;

        if (fps > 1e-3)
            dynMess.message = "fps: " + QString::number(fps,'f',1);

    }
}

void GLWidget::setGLData(cGLData * aData, bool showMessage, bool doZoom)
{
    m_GLData = aData;

    if (m_GLData != NULL)
    {
        clearPolyline();

        if (m_GLData->is3D())
        {
            m_bDisplayMode2D = false;

            if (doZoom) setZoom(m_GLData->getScale());

            resetTranslationMatrix();
        }

        if (!m_GLData->isImgEmpty())
        {
            m_bDisplayMode2D = true;

            if (doZoom) zoomFit();

            //position de l'image dans la vue gl
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();

            glGetDoublev (GL_MODELVIEW_MATRIX, _mvmatrix);

            m_bFirstAction = m_GLData->maskedImage._m_newMask;
        }

        glGetIntegerv (GL_VIEWPORT, _glViewport);

        ConstructListMessages(showMessage);

        update();
    }
}

void GLWidget::setBackgroundColors(const QColor &col0, const QColor &col1)
{
    _BGColor0 = col0;
    _BGColor1 = col1;
}

int GLWidget::renderLineText(MessageToDisplay messageTD, int x, int y, int sizeFont)
{
    qglColor(messageTD.color);

    m_font.setPointSize(sizeFont);

    renderText(x, y, messageTD.message,m_font);

    return (QFontMetrics(m_font).boundingRect(messageTD.message).height()*5)/4;
}

std::list<MessageToDisplay>::iterator GLWidget::GetLastMessage()
{
    std::list<MessageToDisplay>::iterator it = --m_messagesToDisplay.end();

    return it;
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //gradient color background
    drawGradientBackground();
    //we clear background
    glClear(GL_DEPTH_BUFFER_BIT);

    if (hasDataLoaded())
    {
        if (m_bDisplayMode2D)
        {
            // CAMERA BEGIN ======================
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            glPushMatrix();
            glMultMatrixd(_projmatrix);

            if(_projmatrix[0] != m_params.m_zoom)
            {
                GLint recal;
                GLdouble wx, wy, wz;

                recal = _glViewport[3] - (GLint) m_lastClickZoom.y() - 1.f;

                gluUnProject ((GLdouble) m_lastClickZoom.x(), (GLdouble) recal, 1.f,
                              _mvmatrix, _projmatrix, _glViewport, &wx, &wy, &wz);

                glTranslatef(wx,wy,0);
                glScalef(m_params.m_zoom/_projmatrix[0], m_params.m_zoom/_projmatrix[0], 1.f);
                glTranslatef(-wx,-wy,0);
            }

            glTranslatef(m_glPosition[0],m_glPosition[1],0.f);

            m_glPosition[0] = m_glPosition[1] = 0.f;

            glGetDoublev (GL_PROJECTION_MATRIX, _projmatrix);

            // CAMERA END ======================

            m_GLData->maskedImage.draw();

            glPopMatrix();
        }
        else if(m_GLData->is3D())
        {

            // CAMERA BEGIN ===================
            zoom();

            static GLfloat trans44[16], rot44[16], tmp[16];
            m33_to_m44( _g_rotationMatrix, rot44 );
            setTranslate_m3(  m_params.m_translationMatrix, trans44 );

            mult( rot44, trans44, tmp );
            transpose( tmp, _g_glMatrix );
            glLoadMatrixf( _g_glMatrix );

            // CAMERA END ===================

            m_GLData->draw();
        }

        if (m_bDisplayMode2D || (m_interactionMode == SELECTION)) drawPolygon();

        if (m_bDrawMessages && m_messagesToDisplay.size())
        {
            if (m_bDisplayMode2D)
            {
                GetLastMessage()->message = QString::number(m_params.m_zoom*100,'f',1) + "%";

                float px = m_lastMoveImage.x();
                float py = m_lastMoveImage.y();
                float w  = m_GLData->maskedImage._m_image->width();
                float h  = m_GLData->maskedImage._m_image->height();

                if  ((px>=0.f)&&(py>=0.f)&&(px<w)&&(py<h))
                    (--GetLastMessage())->message = QString::number(px,'f',1) + ", " + QString::number(h-py,'f',1) + " px";
            }
            else
                computeFPS(m_messagesToDisplay.back());
        }
    }

    if (!m_messagesToDisplay.empty())
    {
        int ll_curHeight = _glViewport[3] - m_font.pointSize()*m_messagesToDisplay.size(); //lower left
        int lr_curHeight = ll_curHeight;  //lower right
        int lc_curHeight = ll_curHeight;  //lower center
        int uc_curHeight = 10;            //upper center

        std::list<MessageToDisplay>::iterator it = m_messagesToDisplay.begin();
        while (it != m_messagesToDisplay.end())
        {
            QRect rect = QFontMetrics(m_font).boundingRect(it->message);
            switch(it->position)
            {
            case LOWER_LEFT_MESSAGE:
                ll_curHeight -= renderLineText(*it, 10, ll_curHeight);
                break;
            case LOWER_RIGHT_MESSAGE:
                lr_curHeight -= renderLineText(*it, _glViewport[2] - 120, lr_curHeight);
                break;
            case LOWER_CENTER_MESSAGE:
                lc_curHeight -= renderLineText(*it,(_glViewport[2]-rect.width())/2, lc_curHeight);
                break;
            case UPPER_CENTER_MESSAGE:
                uc_curHeight += renderLineText(*it,(_glViewport[2]-rect.width())/2, uc_curHeight+rect.height());
                break;
            case SCREEN_CENTER_MESSAGE:
                renderLineText(*it,(_glViewport[2]-rect.width())/2, (_glViewport[3]-rect.height())/2,12);
            }
            ++it;
        }
    }
}

void GLWidget::keyPressEvent(QKeyEvent* event)
{
    if(event->modifiers().testFlag(Qt::ControlModifier))
    {
        if(event->key() == Qt::Key_1)    zoomFactor(50);
        else if(event->key() == Qt::Key_2)    zoomFactor(25);
    }
    else
    {
        switch(event->key())
        {
        case Qt::Key_Escape:
            clearPolyline();
            break;
        case Qt::Key_1:
            zoomFactor(100);
            break;
        case Qt::Key_2:
            zoomFactor(200);
            break;
        case Qt::Key_4:
            zoomFactor(400);
            break;
        case Qt::Key_9:
            zoomFit();
            break;
        case Qt::Key_Plus:
            if (m_bDisplayMode2D)
            {
                m_lastClickZoom = m_lastPosWindow;
                setZoom(m_params.m_zoom*1.5f);
            }
            else
                m_params.ptSizeUp(true);
            break;
        case Qt::Key_Minus:
            if (m_bDisplayMode2D)
            {
                m_lastClickZoom = m_lastPosWindow;
                setZoom(m_params.m_zoom/1.5f);
            }
            else
                m_params.ptSizeUp(false);
            break;
        default:
            event->ignore();
            break;
        }
    }
    update();
}

void GLWidget::keyReleaseEvent(QKeyEvent* event)
{
    if ((event->key() == Qt::Key_Shift) && hasDataLoaded())
    {
        m_GLData->m_dihedron.clear();
        m_GLData->m_polygon.resetClick();
    }
}

bool GLWidget::hasDataLoaded()
{
    if(m_GLData == NULL)
        return false;
    else
        return m_GLData->isDataLoaded();
}

void GLWidget::dragEnterEvent(QDragEnterEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    if (mimeData->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

void GLWidget::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();

    if (mimeData->hasFormat("text/uri-list"))
    {
        QByteArray data = mimeData->data("text/uri-list");
        QStringList fileNames = QUrl::fromPercentEncoding(data).split(QRegExp("\\n+"),QString::SkipEmptyParts);

        for (int i=0;i<fileNames.size();++i)
        {
            fileNames[i] = fileNames[i].trimmed();

#if defined(_WIN32) || defined(WIN32)
            fileNames[i].remove("file:///");
#else
            fileNames[i].remove("file://");
#endif

#ifdef _DEBUG
            QString formatedMessage = QString("File dropped: %1").arg(fileNames[i]);
            printf(" %s\n",qPrintable(formatedMessage));
#endif
        }

        if (!fileNames.empty())
            emit filesDropped(fileNames);

        setFocus();

        event->acceptProposedAction();
    }

    event->ignore();
}

void GLWidget::displayNewMessage(const QString& message,
                                 MessagePosition pos)
{
    if (message.isEmpty())
    {
        m_messagesToDisplay.clear();

        return;
    }

    MessageToDisplay mess;
    mess.message = message;
    mess.position = pos;
    m_messagesToDisplay.push_back(mess);
}

void GLWidget::drawGradientBackground()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE,GL_ZERO);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int w = (_glViewport[2]>>1)+1;
    int h = (_glViewport[3]>>1)+1;
    glOrtho(-w,w,-h,h,-2.f, 2.f);

    const uchar BkgColor[3] = {(uchar) _BGColor0.red(),(uchar) _BGColor0.green(), (uchar) _BGColor0.blue()};
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //Gradient "texture" drawing
    glBegin(GL_QUADS);
    //user-defined background color for gradient start
    glColor3ubv(BkgColor);
    glVertex2f(-w,h);
    glVertex2f(w,h);
    //and the inverse of points color for gradient end
    glColor3ub(_BGColor1.red(),_BGColor1.green(),_BGColor1.blue());
    glVertex2f(w,-h);
    glVertex2f(-w,-h);
    glEnd();

    glDisable(GL_BLEND);
}

cPolygon GLWidget::PolyImageToWindow(cPolygon polygon)
{
    cPolygon poly = polygon;
    poly.clearPoints();
    for (int aK = 0;aK < polygon.size(); ++aK)
    {
        poly.add(ImageToWindow(polygon[aK]));
    }

    return poly;
}

void GLWidget::drawPolygon()
{
    // camera begin ==================
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,_glViewport[2],_glViewport[3],0,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // camera end  ======================

    if (m_bDisplayMode2D)
    {
        PolyImageToWindow(m_GLData->m_polygon).draw();
        PolyImageToWindow(m_GLData->m_dihedron).drawDihedron();
    }
    else if (m_GLData->is3D())
    {
        m_GLData->m_polygon.draw();
        m_GLData->m_dihedron.drawDihedron();
    }
}

// zoom in 3D mode
void GLWidget::zoom()
{
    if (m_GLData != NULL)
    {
        GLdouble zoom = m_params.m_zoom;

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        glOrtho(-zoom*m_glRatio,zoom*m_glRatio,-zoom, zoom,-2.f*m_GLData->getScale(), 2.f*m_GLData->getScale());

        glMatrixMode(GL_MODELVIEW);
    }
}

void GLWidget::setInteractionMode(INTERACTION_MODE mode, bool showmessage)
{
    // TODO !!!!!!!!!
    m_interactionMode = mode;

    if (hasDataLoaded())
    {
        switch (mode)
        {
        case TRANSFORM_CAMERA:
        {
            clearPolyline();
        }
            break;
        case SELECTION:
        {
            if(m_GLData->is3D()) //3D
                setProjectionMatrix();            
        }
            break;
        default:
            break;
        }
    }
    ConstructListMessages(showmessage);
}

void GLWidget::setView(VIEW_ORIENTATION orientation)
{
    makeCurrent();

    GLdouble eye[3] = {0.0, 0.0, 0.0};
    GLdouble top[3] = {0.0, 0.0, 0.0};
    GLdouble s[3]   = {0.0, 0.0, 0.0};
    GLdouble u[3]   = {0.0, 0.0, 0.0};

    switch (orientation)
    {glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    case TOP_VIEW:
        eye[2] = -1.0;
        top[1] =  1.0;
        break;
    case BOTTOM_VIEW:
        eye[2] =  1.0;
        top[1] = -1.0;
        break;
    case FRONT_VIEW:
        eye[1] = 1.0;
        top[2] = 1.0;
        break;
    case BACK_VIEW:
        eye[1] = -1.0;
        top[2] =  1.0;
        break;
    case LEFT_VIEW:
        eye[0] = 1.0;
        top[2] = 1.0;
        break;
    case RIGHT_VIEW:
        eye[0] = -1.0;
        top[2] =  1.0;
    }

    crossprod(eye, top, s);
    crossprod(s, eye, u);

    _g_rotationMatrix[0] = s[0];
    _g_rotationMatrix[1] = s[1];
    _g_rotationMatrix[2] = s[2];

    _g_rotationMatrix[3] = u[0];
    _g_rotationMatrix[4] = u[1];
    _g_rotationMatrix[5] = u[2];

    _g_rotationMatrix[6] = -eye[0];
    _g_rotationMatrix[7] = -eye[1];
    _g_rotationMatrix[8] = -eye[2];

    resetTranslationMatrix();
}

void GLWidget::onWheelEvent(float wheelDelta_deg)
{
    //convert degrees in zoom 'power'
    float zoomFactor = pow(1.1f,wheelDelta_deg *.05f);

    setZoom(m_params.m_zoom*zoomFactor);
}

void GLWidget::setZoom(float value)
{
    if (value < GL_MIN_ZOOM)
        value = GL_MIN_ZOOM;
    else if (value > GL_MAX_ZOOM)
        value = GL_MAX_ZOOM;

    m_params.m_zoom = value;

    update();
}

void GLWidget::zoomFit()
{
    if (hasDataLoaded())
    {
        float rw = (float)m_GLData->maskedImage._m_image->width()/ _glViewport[2];
        float rh = (float)m_GLData->maskedImage._m_image->height()/_glViewport[3];

        if(rw>rh)
            setZoom(1.f/rw); //orientation landscape
        else
            setZoom(1.f/rh); //orientation portrait

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glPushMatrix();
        glScalef(m_params.m_zoom, m_params.m_zoom, 1.f);
        glTranslatef(-rw,-rh,0.f);
        glGetDoublev (GL_PROJECTION_MATRIX, _projmatrix);
        glPopMatrix();

        m_GLData->maskedImage._m_image->setDimensions(2.f*rh,2.f*rw);
        m_GLData->maskedImage._m_mask->setDimensions(2.f*rh,2.f*rw);

        m_glPosition[0] = 0.f;
        m_glPosition[1] = 0.f;
    }
}

void GLWidget::zoomFactor(int percent)
{
    if (hasDataLoaded())
    {
        if (m_bDisplayMode2D)
        {
            m_lastClickZoom = m_lastPosWindow;
            setZoom(0.01f * percent);
        }
        else
            setZoom(m_GLData->getScale() / (float) percent * 100.f);
    }
}

void GLWidget::wheelEvent(QWheelEvent* event)
{
    if ((m_interactionMode == SELECTION)&&(!m_bDisplayMode2D))
    {
        event->ignore();
        return;
    }

    //see QWheelEvent documentation ("distance that the wheel is rotated, in eighths of a degree")
    float wheelDelta_deg = event->angleDelta().y() / 8.f;

    m_lastClickZoom = event->pos();

    onWheelEvent(wheelDelta_deg);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    if(hasDataLoaded())
    {
        m_lastPosWindow = event->pos();

        m_lastPosImage =  m_bDisplayMode2D ? WindowToImage(m_lastPosWindow) : m_lastPosWindow;

        if ( event->button() == Qt::LeftButton )
        {
            if (m_bDisplayMode2D || (m_interactionMode == SELECTION))
            {
                if(!m_GLData->m_polygon.isClosed())             // ADD POINT

                    m_GLData->AddPoint(m_lastPosImage);

                else if (event->modifiers() & Qt::ShiftModifier) // INSERT POINT

                    m_GLData->InsertPointPolygon();

                else if (m_GLData->m_polygon.idx() != -1)

                    m_GLData->m_polygon.clicked();
            }
        }
        else if (event->button() == Qt::RightButton)

           m_GLData->RemoveClosestPoint(m_lastPosImage);

        else if (event->button() == Qt::MiddleButton)

            m_lastClickZoom = m_lastPosWindow;
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if ( hasDataLoaded() && event->button() == Qt::LeftButton )
    {
        m_GLData->FinalMovePoint(m_lastPosImage);

        update();
    }
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (hasDataLoaded())
    {
        _parentSet->setCurrentWidgetIdx(_idx);

        QPointF pos    = m_bDisplayMode2D ?  WindowToImage(event->localPos()) : event->localPos();

        if (m_bDisplayMode2D)  m_lastMoveImage = pos;

        if (m_bDisplayMode2D || (m_interactionMode == SELECTION))

            m_GLData->RefreshHelperPolygon(pos,(event->modifiers() & Qt::ShiftModifier));

        if (m_interactionMode == TRANSFORM_CAMERA)
        {
            QPoint dPWin = event->pos() - m_lastPosWindow;

            if ( event->buttons() == Qt::LeftButton ) // rotation autour de X et Y
            {
                float d_angleX = m_params.m_speed * dPWin.y() / (float) _glViewport[3];
                float d_angleY = m_params.m_speed * dPWin.x() / (float) _glViewport[2];

                setRotateOx_m33( d_angleX, _g_rotationOx );
                setRotateOy_m33( d_angleY, _g_rotationOy );

                mult_m33( _g_rotationOx, _g_rotationMatrix, _g_tmpoMatrix );
                mult_m33( _g_rotationOy, _g_tmpoMatrix, _g_rotationMatrix );
            }
            else if ( event->buttons() == Qt::MiddleButton )
            {
                if (event->modifiers() & Qt::ShiftModifier)         // ZOOM VIEW
                {
                    if (dPWin.y() > 0) m_params.m_zoom *= pow(2.f, ((float)dPWin.y()) *.05f);
                    else if (dPWin.y() < 0) m_params.m_zoom /= pow(2.f, -((float)dPWin.y()) *.05f);
                }
                else if((_glViewport[2]!=0) || (_glViewport[3]!=0)) // TRANSLATION VIEW
                {
                    if (m_bDisplayMode2D)
                    {
                        QPointF dp = pos - m_lastPosImage;

                        m_glPosition[0] += m_params.m_speed * dp.x()/_glViewport[2];
                        m_glPosition[1] += m_params.m_speed * dp.y()/_glViewport[3];
                    }
                    else
                    {
                        m_params.m_translationMatrix[0] += m_params.m_speed*dPWin.x()*m_GLData->getScale()/_glViewport[2];
                        m_params.m_translationMatrix[1] -= m_params.m_speed*dPWin.y()*m_GLData->getScale()/_glViewport[3];
                    }
                }
            }
            else if (event->buttons() == Qt::RightButton)           // rotation autour de Z
            {
                float d_angleZ =  m_params.m_speed * dPWin.x() / (float) _glViewport[2];

                setRotateOz_m33( d_angleZ, _g_rotationOz );

                mult_m33( _g_rotationOz, _g_rotationMatrix, _g_tmpoMatrix );

                for (int i = 0; i < 9; ++i) _g_rotationMatrix[i] = _g_tmpoMatrix[i];
            }
        }

        m_lastPosWindow = event->pos();

        update();
    }
}

void GLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (hasDataLoaded() && m_GLData->Clouds.size())
    {
        QPointF pos = event->localPos();

        setProjectionMatrix();

        int idx1 = -1;
        int idx2;

        pos.setY(_glViewport[3] - pos.y());

        for (int aK=0; aK < m_GLData->Clouds.size();++aK)
        {
            float sqrD;
            float dist = FLT_MAX;
            idx2 = -1;
            QPointF proj;

            Cloud *a_cloud = m_GLData->Clouds[aK];

            for (int bK=0; bK < a_cloud->size();++bK)
            {
                getProjection(proj, a_cloud->getVertex( bK ).getPosition());

                sqrD = (proj.x()-pos.x())*(proj.x()-pos.x()) + (proj.y()-pos.y())*(proj.y()-pos.y());

                if (sqrD < dist )
                {
                    dist = sqrD;
                    idx1 = aK;
                    idx2 = bK;
                }
            }
        }

        if ((idx1>=0) && (idx2>=0))
        {
            //final center:
            Cloud *a_cloud = m_GLData->Clouds[idx1];
            Pt3dr Pt = a_cloud->getVertex( idx2 ).getPosition();

            m_GLData->setCenter(Pt);

            m_GLData->pBall->setPosition(Pt);
            m_GLData->pAxis->setPosition(Pt);
            m_GLData->pBbox->setPosition(Pt);

            for (int aK=0; aK < m_GLData->Clouds.size();++aK)
            {
                m_GLData->Clouds[aK]->setPosition(Pt);
            }

            resetTranslationMatrix();

            update();
        }
    }
}

void GLWidget::setProjectionMatrix()
{
    glMatrixMode(GL_MODELVIEW);
    glGetDoublev(GL_MODELVIEW_MATRIX, _mvmatrix);

    glMatrixMode(GL_PROJECTION);
    glGetDoublev(GL_PROJECTION_MATRIX, _projmatrix);

    glGetIntegerv(GL_VIEWPORT, _glViewport);
}

void GLWidget::getProjection(QPointF &P2D, Pt3dr P)
{
    GLdouble xp,yp,zp;
    gluProject(P.x,P.y,P.z,_mvmatrix,_projmatrix,_glViewport,&xp,&yp,&zp);
    P2D = QPointF(xp,yp);
}

QPointF GLWidget::WindowToImage(QPointF const &pt)
{
    QPointF res( pt.x()         - .5f*_glViewport[2]*(1.f+ _projmatrix[12]),
            -pt.y()  -1.f   + .5f*_glViewport[3]*(1.f- _projmatrix[13]));

    res /= m_params.m_zoom;

    return res;
}

QPointF GLWidget::ImageToWindow(QPointF const &im)
{
    return QPointF (im.x()*m_params.m_zoom + .5f*_glViewport[2]*(1.f + _projmatrix[12]),
            - 1.f - im.y()*m_params.m_zoom + .5f*_glViewport[3]*(1.f - _projmatrix[13]));
}

void GLWidget::Select(int mode, bool saveInfos)
{
    if (hasDataLoaded())
    {
        QPointF P2D;
        bool pointInside;
        cPolygon polyg;

        if(mode == ADD || mode == SUB)
        {
            if ((m_GLData->m_polygon.size() < 3) || (!m_GLData->m_polygon.isClosed()))
                return;

            if (!m_bDisplayMode2D)
            {
                for (int aK=0; aK < m_GLData->m_polygon.size(); ++aK)
                {
                    polyg.add(QPointF(m_GLData->m_polygon[aK].x(), _glViewport[3] - m_GLData->m_polygon[aK].y()));
                }
            }
            else
                polyg = m_GLData->m_polygon;
        }

        if (m_bDisplayMode2D)
        {
            QPainter    p;
            QBrush SBrush(Qt::white);
            QBrush NSBrush(Qt::black);

            p.begin(m_GLData->getMask());
            p.setCompositionMode(QPainter::CompositionMode_Source);
            p.setPen(Qt::NoPen);

            if(mode == ADD)
            {
                if (m_bFirstAction)
                {
                    p.fillRect(m_GLData->getMask()->rect(), Qt::black);
                }
                p.setBrush(SBrush);
                p.drawPolygon(polyg.getVector().data(),polyg.size());
            }
            else if(mode == SUB)
            {
                p.setBrush(NSBrush);
                p.drawPolygon(polyg.getVector().data(),polyg.size());
            }
            else if(mode == ALL)
            {
                p.fillRect(m_GLData->getMask()->rect(), Qt::white);
            }
            else if(mode == NONE)
            {
                p.fillRect(m_GLData->getMask()->rect(), Qt::black);
            }
            p.end();

            if(mode == INVERT)
                m_GLData->getMask()->invertPixels(QImage::InvertRgb);

            m_GLData->maskedImage._m_mask->ImageToTexture(m_GLData->getMask());
        }
        else
        {
            for (int aK=0; aK < m_GLData->Clouds.size(); ++aK)
            {
                Cloud *a_cloud = m_GLData->Clouds[aK];

                for (uint bK=0; bK < (uint) a_cloud->size();++bK)
                {
                    Vertex P  = a_cloud->getVertex( bK );
                    Pt3dr  Pt = P.getPosition();

                    switch (mode)
                    {
                    case ADD:
                        getProjection(P2D, Pt);
                        pointInside = polyg.isPointInsidePoly(P2D);
                        if (m_bFirstAction)
                            emit selectedPoint(aK,bK,pointInside);
                        else
                            emit selectedPoint(aK,bK,pointInside||P.isVisible());
                        break;
                    case SUB:
                        if (P.isVisible())
                        {
                            getProjection(P2D, Pt);
                            pointInside = polyg.isPointInsidePoly(P2D);
                            emit selectedPoint(aK,bK,!pointInside);
                        }
                        break;
                    case INVERT:
                        emit selectedPoint(aK,bK,!P.isVisible());
                        break;
                    case ALL:
                        m_bFirstAction = true;
                        emit selectedPoint(aK,bK, true);
                        break;
                    case NONE:
                        emit selectedPoint(aK,bK,false);
                        break;
                    }
                }

                a_cloud->setBufferGl(true);
            }
        }

        if (((mode == ADD)||(mode == SUB)) && (m_bFirstAction)) m_bFirstAction = false;

        if (saveInfos)
        {
            selectInfos info;
            //info.params = m_params;
            info.poly   = m_GLData->m_polygon.getVector();
            info.selection_mode   = mode;

            for (int aK=0; aK<4; ++aK)
                info.glViewport[aK] = _glViewport[aK];
            for (int aK=0; aK<16; ++aK)
            {
                info.mvmatrix[aK] = _mvmatrix[aK];
                info.projmatrix[aK] = _projmatrix[aK];
            }

            m_infos.push_back(info);
        }

        clearPolyline();
    }
}

void GLWidget::clearPolyline()
{
    if (hasDataLoaded())
    {
        m_GLData->m_polygon.clear();
        m_GLData->m_polygon.setClosed(false);
        m_GLData->m_dihedron.clear();
    }

    update();
}

void GLWidget::undo()
{
    if (m_infos.size() && hasDataLoaded())
    {
        if ((!m_bDisplayMode2D) || (m_infos.size() == 1))
            Select(ALL, false);

        for (int aK = 0; aK < m_infos.size()-1; ++aK)
        {
            selectInfos &infos = m_infos[aK];

            cPolygon Polygon;
            Polygon.setClosed(true);
            Polygon.setVector(infos.poly);
            m_GLData->setPolygon(Polygon);

            if (!m_bDisplayMode2D)
            {
                for (int bK=0; bK<16;++bK)
                {
                    _mvmatrix[bK]   = infos.mvmatrix[bK];
                    _projmatrix[bK] = infos.projmatrix[bK];
                }
                for (int bK=0; bK<4;++bK)  _glViewport[bK] = infos.glViewport[bK];

                if (aK==0) m_bFirstAction = true;
                else m_bFirstAction = false;
            }

            Select(infos.selection_mode, false);
        }

        m_infos.pop_back();
    }
}

void GLWidget::showAxis(bool show)
{
    if (hasDataLoaded())
        m_GLData->pAxis->setVisible(show);
    update();
}

void GLWidget::showBall(bool show)
{
    if (hasDataLoaded())
        m_GLData->pBall->setVisible(show);
    update();
}

void GLWidget::showCams(bool show)
{
    if (hasDataLoaded())
    {
        for (int i=0; i < m_GLData->Cams.size();i++)
            m_GLData->Cams[i]->setVisible(show);
    }

    update();
}

void GLWidget::showBBox(bool show)
{
    if (hasDataLoaded())
        m_GLData->pBbox->setVisible(show);

    update();
}

void GLWidget::ConstructListMessages(bool show)
{
    m_bDrawMessages = show;

    MessageToDisplay DynamicMessage;
    DynamicMessage.color = Qt::lightGray;
    displayNewMessage(QString());

    m_messagesToDisplay.clear();

    if (m_bDrawMessages)
    {
        if(hasDataLoaded())
        {
            if(m_bDisplayMode2D)
            {
                DynamicMessage.position = LOWER_RIGHT_MESSAGE;
                DynamicMessage.message  = "POSITION PIXEL";
                m_messagesToDisplay.push_back(DynamicMessage);

                DynamicMessage.position = LOWER_LEFT_MESSAGE;
                DynamicMessage.message  = "ZOOM";
                m_messagesToDisplay.push_back(DynamicMessage);
            }
            else
            {
                if (m_interactionMode == TRANSFORM_CAMERA)
                    displayMoveMessages();
                else if (m_interactionMode == SELECTION)
                    displaySelectionMessages();

                DynamicMessage.position = LOWER_LEFT_MESSAGE;
                DynamicMessage.message  = "0 Fps";
                m_messagesToDisplay.push_back(DynamicMessage);
            }
        }
        else
            displayNewMessage(tr("Drag & drop images or ply files"));
    }

    update();
}

void GLWidget::displaySelectionMessages()
{
    displayNewMessage(tr("Selection mode"),UPPER_CENTER_MESSAGE);
    displayNewMessage(tr("Left click: add contour point / Right click: close"),LOWER_CENTER_MESSAGE);
    displayNewMessage(tr("Space: add / Suppr: delete"),LOWER_CENTER_MESSAGE);
}

void GLWidget::displayMoveMessages()
{
    displayNewMessage(tr("Move mode"),UPPER_CENTER_MESSAGE);
    displayNewMessage(tr("Left click: rotate viewpoint / Right click: translate viewpoint"),LOWER_CENTER_MESSAGE);
}

void GLWidget::reset()
{
    resetRotationMatrix();
    resetTranslationMatrix();

    m_glPosition[0] = m_glPosition[1] = 0.f;

    clearPolyline();

    m_params.reset();

    m_bFirstAction = true;

    m_GLData = NULL;
}

void GLWidget::resetView()
{
    ConstructListMessages(true);

    if (m_bDisplayMode2D)
        zoomFit();
    else
    {
        resetRotationMatrix();
        resetTranslationMatrix();

        if (hasDataLoaded())
        {
            setZoom(m_GLData->getScale());

            //rustine - a passer dans MainWindow pour ui->action_showBall->setChecked(false)
            m_GLData->pBall->setVisible(true);
        }
    }

    update();
}

void GLWidget::resetRotationMatrix()
{
    _g_rotationMatrix[0] = _g_rotationMatrix[4] = _g_rotationMatrix[8] = 1;
    _g_rotationMatrix[1] = _g_rotationMatrix[2] = _g_rotationMatrix[3] = 0;
    _g_rotationMatrix[5] = _g_rotationMatrix[6] = _g_rotationMatrix[7] = 0;
}

void GLWidget::resetTranslationMatrix()
{
    if (hasDataLoaded())
    {
        Pt3dr center = m_GLData->getCenter();

        m_params.m_translationMatrix[0] = -center.x;
        m_params.m_translationMatrix[1] = -center.y;
        m_params.m_translationMatrix[2] = -center.z;
    }
}
