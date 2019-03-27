#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TRandom.h"

// This example is a variant of hsimple.C but using a TTree instead
// of a TNtuple. It shows :
//   -how to fill a Tree with a few simple variables.
//   -how to read this Tree
//   -how to browse and analyze the Tree via the TBrowser and TTreeViewer
// This example can be run in many different ways:
//  way1:  .x tree1.C    using the CINT interpreter
//  way2:  .x tree1.C++  using the automatic compiler interface
//  way3:  .L tree1.C  or .L tree1.C++
//          tree1()
// One can also run the write and read parts in two separate sessions.
// For example following one of the sessions above, one can start the session:
//   .L tree1.C
//   tree1r();
//
//  Author: Rene Brun

void tree1w()
{
   //create a Tree file tree1.root
   
   //create the file, the Tree and a few branches
   TFile f("tree1.root","recreate");
   TTree t1("t1","a simple Tree with simple variables");
   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   t1.Branch("px",&px,"px/F");
   t1.Branch("py",&py,"py/F");
   t1.Branch("pz",&pz,"pz/F");
   t1.Branch("random",&random,"random/D");
   t1.Branch("ev",&ev,"ev/I");
   
   //fill the tree
   for (Int_t i=0;i<10000;i++) {
     gRandom->Rannor(px,py);
     pz = px*px + py*py;
     random = gRandom->Rndm();
     ev = i;
     t1.Fill();
  }
  
  //save the Tree header. The file will be automatically closed
  //when going out of the function scope
  t1.Write();
}

