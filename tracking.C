#include "TGraph.h"
#include "TRandom.h"
#include "TStopwatch.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMath.h"
using namespace std;
/*
===========================================================================================
Defining various functions

============================================================================================

*/
double func1(double x1)
{
Double_t y= -TMath::Log(x1);

return y;
}

double func2(double x2)
{
Double_t y=-0.5*(TMath::Log(x2));
return y;
}
double func3(double x3)
{
double y= -(1/3)*TMath::Log(x3);
return y;
}
//Main code begins
void tracking()
{
gStyle->SetOptFit(111);
TRandom3 gen;
Double_t s1, s2;
Double_t k=0,j=0,s; //defining counters to compute samping fraction of process
TF1 *f =new TF1("f","[0]*TMath::Exp(-[1]*x)"); //defining functin for fit
TH1F *h=new TH1F("h","Tracking",100,0,3);// defining a histogram

//sampling a million times
	for(int i=0;i<1000000;i++)
	{
	  Double_t y1=gen.Uniform(0,1);
	  
	  Double_t y2=gen.Uniform(0,1);
	  
	  s1=func1(y1);
	  s2=func2(y2);
	  
	
          s=TMath::Min(s1,s2);
	  if(s==s1)
		{
		    k++;
			}
		else if(s==s2)
			{
  			   j++;
				}
	 h->Fill(s);
	}	
h->Draw();//drawing the histogram
h->Fit("f","EM");//fitting with function
cout<<"Probability of interaction for #mu = 2   "<< j/(j+k) <<"\t" << "value of interaction for #mu=1  "<<k/(j+k)<<endl;//calculating the sampling fraction
h->GetXaxis()->SetTitle("s");
h->GetXaxis()->CenterTitle();
h->GetYaxis()->SetTitle("counts/bin");
h->GetYaxis()->CenterTitle();
h->GetYaxis()->SetTitleOffset(1.4);
}


