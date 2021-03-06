/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr

   
    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in 
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte 
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/


#include "NewRechPH.h"


std::vector<const std::vector<double> *> VRAD(const cOnePCarac * aPC)
{
   std::vector<const std::vector<double> *> aRes;
   aRes.push_back(&(aPC->CoeffRadiom()));
   aRes.push_back(&(aPC->CoeffRadiom2()));
   aRes.push_back(&(aPC->CoeffGradRadial()));
   aRes.push_back(&(aPC->CoeffGradTangent()));
   aRes.push_back(&(aPC->CoeffGradTangentPiS4()));
   aRes.push_back(&(aPC->CoeffGradTangentPiS2()));

   return aRes;
}

double Dist(const std::vector<double> & aV1,const std::vector<double> & aV2)
{
    double aRes=0.0;
    for (int aK=0 ; aK<int(aV1.size()) ; aK++)
    {
        aRes += ElSquare(aV1[aK]-aV2[aK]);
    }
    return aRes;
}

std::vector<double> VectDist(const cOnePCarac * aP1,const cOnePCarac * aP2)
{
    std::vector<const std::vector<double> *>  aVV1 = VRAD(aP1);
    std::vector<const std::vector<double> *>  aVV2 = VRAD(aP2);

    std::vector<double> aRes;
    double aSomRes = 0;
    for (int aK=0 ; aK<int(aVV1.size()) ; aK++)
    {
        double aD = Dist(*(aVV1[aK]),*(aVV2[aK]));
        aRes.push_back(aD);
        aSomRes += aD;
    }
    aRes.push_back(aSomRes);
    return aRes;
}




void TestMatchInvRad(const std::vector<cOnePCarac> & aVH,const cOnePCarac * aHom1,const cOnePCarac * aHom2)
{
     ELISE_ASSERT(aHom1->Kind() == aHom2->Kind(),"Dif Kind in TestMatchInvRad");

     
     std::vector<double> aVD0 =  VectDist(aHom1,aHom2);
     std::vector<int> aVNbOk(aVD0.size(),0);
     int aNbOkLab = 0;
     for (int aK=0 ; aK<int(aVH.size()) ; aK++)
     {
         const cOnePCarac * aHomTest = & aVH[aK];
         if (aHomTest->Kind() == aHom2->Kind())
         {
             aNbOkLab ++;
             std::vector<double> aVDist =  VectDist(aHomTest,aHom2);
             for (int aK=0 ; aK<int(aVDist.size()); aK++)
                 aVNbOk[aK]  += (aVDist[aK] > aVD0[aK]);
         }
     }
     std::cout << "PropRad " << aVNbOk[0] / double(aNbOkLab) << "\n";
     std::cout << "PropRad2 " << aVNbOk[1] / double(aNbOkLab) << "\n";
     std::cout << "PropGradR " << aVNbOk[2] / double(aNbOkLab) << "\n";
     std::cout << "PropGradT " << aVNbOk[3] / double(aNbOkLab) << "\n";
     std::cout << "PropGradPiS4 " << aVNbOk[4] / double(aNbOkLab) << "\n";
     std::cout << "PropGradPiS2 " << aVNbOk[5] / double(aNbOkLab) << "\n";
     std::cout << "PropTot " << aVNbOk[6] / double(aNbOkLab) << "\n";

/*
     double aDRadiom  = Dist(aHom1->CoeffRadiom(),aHom2->CoeffRadiom());
     double aDRadiom2 = Dist(aHom1->CoeffRadiom2(),aHom2->CoeffRadiom2());
     double aDGradR = Dist(aHom1->CoeffGradRadial(),aHom2->CoeffGradRadial());
     double aDGradT = Dist(aHom1->CoeffGradTangent(),aHom2->CoeffGradTangent());
     double aDGradTPiS4 = Dist(aHom1->CoeffGradTangentPiS4(),aHom2->CoeffGradTangentPiS4());
     double aDGradTPiS2 = Dist(aHom1->CoeffGradTangentPiS2(),aHom2->CoeffGradTangentPiS2());

     int aNbOkRadiom  = 0;
     int aNbOkRadiom2 = 0;
     int aNbOkGradR   = 0;
     int aNbOkGradT   = 0;
     int aNbOkGPiS4   = 0;
     int aNbOkGPiS2   = 0;

     int aNbOkLab = 0;

     for (int aK=0 ; aK<int(aVH.size()) ; aK++)
     {
         const cOnePCarac * aHom1 = & aVH[aK];
         if (aHom1->Kind() == aHom2->Kind())
         {
             aNbOkLab ++;
             int OkRad = Dist(aHom1->CoeffRadiom(),aHom2->CoeffRadiom())    > aDRadiom;
             int OkRad2 = Dist(aHom1->CoeffRadiom2(),aHom2->CoeffRadiom2()) > aDRadiom2;
             int OkGradR = Dist(aHom1->CoeffGradRadial(),aHom2->CoeffGradRadial()) > aDGradR;
             int OkGradT = Dist(aHom1->CoeffGradTangent(),aHom2->CoeffGradTangent()) > aDGradT;
             int OkGradTPiS4 = Dist(aHom1->CoeffGradTangentPiS4(),aHom2->CoeffGradTangentPiS4()) > aDGradTPiS4;
             int OkGradTPiS2 = Dist(aHom1->CoeffGradTangentPiS2(),aHom2->CoeffGradTangentPiS2()) > aDGradTPiS2;

             aNbOkRadiom += OkRad;
             aNbOkRadiom2 += OkRad2;
             aNbOkGradR   += OkGradR;
             aNbOkGradT   += OkGradT;
             aNbOkGPiS4   += OkGradTPiS4;
             aNbOkGPiS2   += OkGradTPiS2;
           
         }
     }

     std::cout << "PropRad " << aNbOkRadiom / double(aNbOkLab) << "\n";
     std::cout << "PropRad2 " << aNbOkRadiom2 / double(aNbOkLab) << "\n";
     std::cout << "PropGradR " << aNbOkGradR / double(aNbOkLab) << "\n";
     std::cout << "PropGradT " << aNbOkGradT / double(aNbOkLab) << "\n";
     std::cout << "PropGradPiS4 " << aNbOkGPiS4 / double(aNbOkLab) << "\n";
     std::cout << "PropGradPiS2 " << aNbOkGPiS2 / double(aNbOkLab) << "\n";
*/
}


/*Footer-MicMac-eLiSe-25/06/2007

Ce logiciel est un programme informatique servant à la mise en
correspondances d'images pour la reconstruction du relief.

Ce logiciel est régi par la licence CeCILL-B soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL-B telle que diffusée par le CEA, le CNRS et l'INRIA 
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant 
donné sa spécificité de logiciel libre, qui peut le rendre complexe à 
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement, 
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité. 

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez 
pris connaissance de la licence CeCILL-B, et que vous en avez accepté les
termes.
aooter-MicMac-eLiSe-25/06/2007*/
