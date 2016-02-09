#include "TGraph.h"
#include "TRandom3.h"
#include "TStopwatch.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TF1.h"

using namespace std;

void ex3n()
{
	gStyle->SetOptFit(011);
	TCanvas *c =new TCanvas("c","superimposing",0,0,1080,860);//creating canvas for the histogram
	
	TRandom3 gen;//invoking the random number generator
	Double_t j=0,k=0,mean,m; //declaring counters and parameters for calculation
	Double_t pi, sum, var=0 ;
	Double_t devia;
	TH1F *h=new TH1F("h","mean distribution",60000,0,6);//calling the histogram class
	Int_t N=1000,q;//fixing N 
	TF1 *f =new TF1("f", "gaus"); //creating function to fit
	//TF1 *f1 = new TF1("f1","0.00357583/TMath::Sqrt(x)", 1000,5000);
	for(q=0;q<3;q++)
	{
	if(q==0)
{
	for(int z=0;z<10000;z++)//loops to calculate pi and fill the histogram
	{	
	for(int i=0; i<100;i++)
		{
			Double_t x= gen.Uniform(-1.,1);
			Double_t y=gen.Uniform(-1.,1.);
			if(x*x+y*y<=1)
				{
					j++;
					}
				else {k++;}
				pi=(j/(j+k))*4;
				
				
			}
				
				h->Fill(pi);
				
				
					}h->Fit("f");
devia=f->GetParameter(2);
cout<<"100"<<"\t"<<devia<<endl;
}

if(q==1)
{
	for(int z=0;z<10000;z++)//loops to calculate pi and fill the histogram
	{	
	for(int i=0; i<1000;i++)
		{
			Double_t x= gen.Uniform(-1.,1);
			Double_t y=gen.Uniform(-1.,1.);
			if(x*x+y*y<=1)
				{
					j++;
					}
				else {k++;}
				pi=(j/(j+k))*4;
				
				
			}
				
				h->Fill(pi);
				
				
					}h->Fit("f");
devia=f->GetParameter(2);
cout<<"1000"<<"\t"<<devia<<endl;
}
if(q==2)
{
	for(int z=0;z<10000;z++)//loops to calculate pi and fill the histogram
	{	
	for(int i=0; i<5000;i++)
		{
			Double_t x= gen.Uniform(-1.,1);
			Double_t y=gen.Uniform(-1.,1.);
			if(x*x+y*y<=1)
				{
					j++;
					}
				else {k++;}
				pi=(j/(j+k))*4;
				
				
			}
				
				h->Fill(pi);
				
				
					}h->Fit("f");

}

devia=f->GetParameter(2);
cout<<"5000"<<"\t"<<devia<<endl;
}


}



