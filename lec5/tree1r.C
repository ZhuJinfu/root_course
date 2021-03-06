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

void tree1r()
{
   //read the Tree generated by tree1w and fill two histograms
   
   //note that we use "new" to create the TFile and TTree objects !
   //because we want to keep these objects alive when we leave this function.
   TFile *f = new TFile("tree1.root");
   TTree *t1 = (TTree*)f->Get("t1");
   Float_t px, py, pz;
   Double_t random;
   Int_t ev;
   t1->SetBranchAddress("px",&px);
   t1->SetBranchAddress("py",&py);
   t1->SetBranchAddress("pz",&pz);
   t1->SetBranchAddress("random",&random);
   t1->SetBranchAddress("ev",&ev);
   
   //create two histograms
   TH1F *hpx   = new TH1F("hpx","px distribution",100,-3,3);
   TH2F *hpxpy = new TH2F("hpxpy","py vs px",30,-3,3,30,-3,3);
   
   //read all entries and fill the histograms
   Int_t nentries = (Int_t)t1->GetEntries();
   for (Int_t i=0;i<nentries;i++) {
     t1->GetEntry(i);
     hpx->Fill(px);
     hpxpy->Fill(px,py);
   }
  
  //we do not close the file. We want to keep the generated histograms
  //we open a browser and the TreeViewer
  if (gROOT->IsBatch()) return;
  new TBrowser();

}   
