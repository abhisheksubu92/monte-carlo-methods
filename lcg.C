#include "TStopwatch.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TH1.h"
#include "TStyle.h"

using namespace std;
void lcg()
{	
	TStopwatch w;
	
	gStyle->SetOptFit(111);	
	
	TCanvas *c1 =new TCanvas("c1","canvas",0,0,1080,864);
	TCanvas *c2 = new TCanvas("c2","canvas",0,0,1080,864);
	TCanvas *c3 = new TCanvas("c3","Bazinga",0,0,1080,864);
	UInt_t i= 987654321;
	Double_t norm=TMath::Power(2,32)-1;
	Double_t j;
	Int_t count=0;
	TH1D *h=new TH1D("h", "Random Number Generation",100,0,1);
	TH1D *h1=new TH1D("h", "Random Number Generation",100,0,1);
	TH1D *h2=new TH1D("h", "Random Number generation",100,0,1);
	TF1 *f =new TF1("f","[0]");
	f->SetParNames("Intercept");
	
	w.Start();
	do
	{
		  i=i*663608941;
		  j= i/norm;
		//cout<<y<<endl;
		//cout<<i<<endl;
		count++;
			h->Fill(j);
		if(count<=1000)
		{
			h1->Fill(j);
		}
		if(count<=1000000)
		{
			h2->Fill(j);
		}
		
		}while(i!=987654321);

	
	
	c1->cd();
	h->Draw();
	h->Fit("f","EM");
	h->GetXaxis()->SetTitle("Random number");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->SetTitle("counts/bin");
	h->GetYaxis()->SetLabelFont(7);
	h->GetYaxis()->SetTitleOffset(1.3);
	h->GetYaxis()->CenterTitle();
	c2->cd();
	h1->Draw();
	h1->Fit("f","EM");
	h1->GetXaxis()->SetTitle("Random number");
	h1->GetXaxis()->CenterTitle();
	h1->GetYaxis()->SetTitle("counts/bin");
	h1->GetYaxis()->CenterTitle();
	c3->cd();
	h2->Draw();
	h2->GetXaxis()->SetTitle("Random number");
	h2->GetXaxis()->CenterTitle();
	h2->GetYaxis()->SetTitle("counts/bin");
	h2->GetYaxis()->CenterTitle();
	h2->GetYaxis()->SetTitleOffset(1.2);
	h2->Fit("f","EM");
	w.Stop();
	w.Print();
	cout<<"sequence length "<<count<<endl;
}
