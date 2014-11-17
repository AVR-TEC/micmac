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
// File Automatically generated by eLiSe

#include "general/all.h"
#include "private/all.h"


class cEqCorLI_Multi_5_DRPts0_NonNorm: public cElCompiledFonc
{
   public :

      cEqCorLI_Multi_5_DRPts0_NonNorm();
      void ComputeVal();
      void ComputeValDeriv();
      void ComputeValDerivHessian();
      double * AdrVarLocFromString(const std::string &);
      void SetCoeffU_A_0(double);
      void SetCoeffU_A_1(double);
      void SetCoeffU_A_2(double);
      void SetCoeffU_A_3(double);
      void SetCoeffU_A_4(double);
      void SetCoeffU_B_0(double);
      void SetCoeffU_B_1(double);
      void SetCoeffU_B_2(double);
      void SetCoeffU_B_3(double);
      void SetCoeffU_B_4(double);
      void SetCoeffV_A_0(double);
      void SetCoeffV_A_1(double);
      void SetCoeffV_A_2(double);
      void SetCoeffV_A_3(double);
      void SetCoeffV_A_4(double);
      void SetCoeffV_B_0(double);
      void SetCoeffV_B_1(double);
      void SetCoeffV_B_2(double);
      void SetCoeffV_B_3(double);
      void SetCoeffV_B_4(double);
      void SetCste_A_0(double);
      void SetCste_A_1(double);
      void SetCste_A_2(double);
      void SetCste_A_3(double);
      void SetCste_A_4(double);
      void SetCste_B_0(double);
      void SetCste_B_1(double);
      void SetCste_B_2(double);
      void SetCste_B_3(double);
      void SetCste_B_4(double);
      void SetP3X_A_0(double);
      void SetP3X_A_1(double);
      void SetP3X_A_2(double);
      void SetP3X_A_3(double);
      void SetP3X_A_4(double);
      void SetP3X_B_0(double);
      void SetP3X_B_1(double);
      void SetP3X_B_2(double);
      void SetP3X_B_3(double);
      void SetP3X_B_4(double);
      void SetP3Y_A_0(double);
      void SetP3Y_A_1(double);
      void SetP3Y_A_2(double);
      void SetP3Y_A_3(double);
      void SetP3Y_A_4(double);
      void SetP3Y_B_0(double);
      void SetP3Y_B_1(double);
      void SetP3Y_B_2(double);
      void SetP3Y_B_3(double);
      void SetP3Y_B_4(double);
      void SetP3Z_A_0(double);
      void SetP3Z_A_1(double);
      void SetP3Z_A_2(double);
      void SetP3Z_A_3(double);
      void SetP3Z_A_4(double);
      void SetP3Z_B_0(double);
      void SetP3Z_B_1(double);
      void SetP3Z_B_2(double);
      void SetP3Z_B_3(double);
      void SetP3Z_B_4(double);


      static cAutoAddEntry  mTheAuto;
      static cElCompiledFonc *  Alloc();
   private :

      double mLocCoeffU_A_0;
      double mLocCoeffU_A_1;
      double mLocCoeffU_A_2;
      double mLocCoeffU_A_3;
      double mLocCoeffU_A_4;
      double mLocCoeffU_B_0;
      double mLocCoeffU_B_1;
      double mLocCoeffU_B_2;
      double mLocCoeffU_B_3;
      double mLocCoeffU_B_4;
      double mLocCoeffV_A_0;
      double mLocCoeffV_A_1;
      double mLocCoeffV_A_2;
      double mLocCoeffV_A_3;
      double mLocCoeffV_A_4;
      double mLocCoeffV_B_0;
      double mLocCoeffV_B_1;
      double mLocCoeffV_B_2;
      double mLocCoeffV_B_3;
      double mLocCoeffV_B_4;
      double mLocCste_A_0;
      double mLocCste_A_1;
      double mLocCste_A_2;
      double mLocCste_A_3;
      double mLocCste_A_4;
      double mLocCste_B_0;
      double mLocCste_B_1;
      double mLocCste_B_2;
      double mLocCste_B_3;
      double mLocCste_B_4;
      double mLocP3X_A_0;
      double mLocP3X_A_1;
      double mLocP3X_A_2;
      double mLocP3X_A_3;
      double mLocP3X_A_4;
      double mLocP3X_B_0;
      double mLocP3X_B_1;
      double mLocP3X_B_2;
      double mLocP3X_B_3;
      double mLocP3X_B_4;
      double mLocP3Y_A_0;
      double mLocP3Y_A_1;
      double mLocP3Y_A_2;
      double mLocP3Y_A_3;
      double mLocP3Y_A_4;
      double mLocP3Y_B_0;
      double mLocP3Y_B_1;
      double mLocP3Y_B_2;
      double mLocP3Y_B_3;
      double mLocP3Y_B_4;
      double mLocP3Z_A_0;
      double mLocP3Z_A_1;
      double mLocP3Z_A_2;
      double mLocP3Z_A_3;
      double mLocP3Z_A_4;
      double mLocP3Z_B_0;
      double mLocP3Z_B_1;
      double mLocP3Z_B_2;
      double mLocP3Z_B_3;
      double mLocP3Z_B_4;
};

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
Footer-MicMac-eLiSe-25/06/2007*/
