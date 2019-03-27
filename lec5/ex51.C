#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TCanvas.h"

TString rootfile("ex51.root");

// Example of a Tree where branches are variable length arrays
// Run this script with
//   .x ex51.C
// or,
//   .L ex51.C
//   ex51r()
//   by yangzw, 2008.03.22

void ex51r()
{
   gStyle->SetOptFit(1111);
   TFile *f = new TFile(rootfile);
   TTree *t4 = (TTree*)f->Get("t4");
   TH1F *hpx = new TH1F("hpx","",100,-5,5);
   t4->Draw("px>>hpx");
   hpx->Fit("gaus");
   //hpx->Fit("gaus","","",-3,3);
}

void ex51r2()
{
   gStyle->SetOptFit();
   TFile *f = new TFile(rootfile);
   TTree *t4 = (TTree*)f->Get("t4");
   TH1F *hpx = new TH1F("hpx","px of track" ,100,-5,5);
   TCanvas *myC = new TCanvas("myC","",10,10,600,400);
   //hntrack->GetYaxis()->SetRangeUser(0,60);
   TF1 *fcn = new TF1("fcn","gaus",-3,3);
   Double_t mean = hpx->GetMean();
   Double_t sigma = hpx->GetRMS();
   fcn->SetParameters(500,mean,sigma);
   fcn->SetParNames("C","#mu","#sigma");
   fcn->SetLineColor(kRed);
   t4->Draw("px>>hpx","","e");
   hpx->Fit(fcn,"R");
   Double_t mypar[3];
   fcn->GetParameters(&mypar[0]);
   for (int i=0;i<3;i++) cout << "par[" << i << "]=" << mypar[i] << endl;
}

void ex51()
{
  ex51r();
  //ex51r2();
}
