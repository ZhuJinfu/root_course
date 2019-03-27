#include "TF1.h"

Double_t DiExp(Double_t *x, Double_t *par)
{
    Double_t f=par[0]*exp(-x[0]/par[1]);
    return f;
}
void myFunc() {
    TF1* f1 = new TF1("f1",DiExp,0,10,2);
    f1->SetParameter(0,100);
    f1->SetParameter(1,2);
    f1->Draw();
}

void histw() {
    gROOT->Reset();
    const Int_t NEntry = 10000 ;
    TFile *file = new TFile("Landau.root","RECREATE");
    TH1F *h1 = new TH1F("h1","A simple histo",100,0,1);
    for (int i=0;i<NEntry;i++) {
        h1->Fill( gRandom->Landau(0.2,0.1) );
    }
    h1->GetXaxis()->SetTitle("X Title, #sqrt{#Delta_{2}}");
    h1->GetXaxis()->CenterTitle();
    h1->GetYaxis()->SetTitle("Y Title, Entries/0.01");
    h1->Draw();
    file->Write();
    c1->SaveAs("Landau.ps");
}

int main(){
    myFunc();
    //histw();
    return 0;
    
}
