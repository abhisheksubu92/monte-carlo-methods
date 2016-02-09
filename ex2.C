#include "TStyle.h"
#include "TH1.h"
#include "TH2.h"
#include "TStopwatch.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TRandom.h"
using namespace std;

void ex2()
{	
	TStopwatch w;
	w.Start();
	TRandom3 gen;
	TCanvas *c =new TCanvas("c","My canvas",0,0,1080,864);
	
	 //random number initialization
	  Int_t i, n=0;
	
	  TF1 *f =new TF1("f","(2*x)/TMath::Power((1+TMath::Power(x,2),2)");
	  TF1 *f1 =new TF1("f1","1/TMath:Sqrt(x)",0,15);
	  //TF1 *f =new TF1("f","((-1/x)-1");
	
	
	TH1F *h =new TH1F("h","distribution",100,0,15);	
	for(i=0;i<1000000;i++)	
		{
			double r=gen.Uniform(-1.,0);
				//cout<<r<<endl;
				
			double y=TMath::Sqrt(-(1/r)-1);
			
			//cout<<y<<endl;	
			
			h->Fill(y);
		}
        c->cd();
	
	h->Fit("f1");
	h->Draw();
	c->Update();
	h->GetXaxis()->SetTitle("x");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->SetTitle("counts/bin");
	h->GetYaxis()->CenterTitle();
	w.Stop();
	w.Print();

}

void inv()
{	
	TCanvas *c =new TCanvas("c","canvas",0,0,1080,860); //defining canvas to plot the outcome of the sampling.
	TStopwatch w;//invoking stopwatch
	
	TRandom3 generate;//invoking the random number generator
	Int_t i;// setting a counter for the for loop
	Double_t r1,r2;//declaring variables for the random numbers.
	TH2F *h =new TH2F("h","Inversion method",100,-1,1,100,-1,1);//defining a 2D histogram where 
	
	w.Start();//starting the stop watch
	for(i=0;i<1000000;i++)
		{	
		   r1=generate.Uniform(0,1.);//generating random number for r
		   r2=generate.Uniform(0,1);//generating random number for 2pi
		   Double_t  x=TMath::Sqrt(r1)*TMath::Cos(TMath::TwoPi()* r2);//using them in the formula
		   Double_t y=TMath::Sqrt(r1)*TMath::Sin(TMath::TwoPi()*r2);		
		   h->Fill(x,y);//filling the 2D histograms with the generated x and y	

			}
	w.Stop();//stopping the stopwatch
	w.Print();//printing the output
	h->Draw();//drawing the histogram
	/*
	=======================================================
	The next few lines are for naming the axis of the plot
	and changing the color of the marker
	=======================================================
	*/
	h->GetXaxis()->SetTitle("x");
	h->GetYaxis()->SetTitle("y");
	h->GetXaxis()->CenterTitle();
	h->GetYaxis()->CenterTitle();
	h->SetMarkerColor(kBlue);
	
	
}

void rej()
{
	TStopwatch t;//invoking stopwatch
	
	 TRandom3 gen;//invoking the random number generator
	Int_t j=0,k=0,iN;
	
	
  	TH2D *h = new TH2D("h","Rejection Method",100,-1,1,100,-1,1);
	TH1D *h2 = new TH1D("h2","Histogram",100,-1,1);
	t.Start();//starting the timer
	for(i=0;i<1000000;i++)//samplig a million times
		{
			Double_t r1=gen.Uniform(0,1);//generating random number for x
			Double_t r2=gen.Uniform(0,1);//generating random number for y
			Double_t x= -1+ 2*r1;//defining x
			Double_t y=-1+2*r2;//defining y
			if(x*x + y*y <1)//checking the condition
				{
				   h->Fill(x,y);//incrementing the counter and filling the histogram
				   j++;
				}else
				{k++;
				 }
			}
	
	t.Stop();//stopping the timer
	t.Print();//getting the output
	h->Draw();//drawing the histogram
	h->SetMarkerColor(kBlue);
	
	
}


