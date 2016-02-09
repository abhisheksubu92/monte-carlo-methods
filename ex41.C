#include "TGraph.h"
#include "TRandom3.h"
#include "TStopwatch.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TF1.h"

void ex41()
{
gStyle->SetOptFit(111);
TRandom3 gen;//invoking the random number generator
Double_t sum=0;//declariation of sum and integration
TH1F *h =new TH1F("h","to estimate k" ,60000,0,6);
Int_t i,num,N=100;//declaring variables for loop and dimension and number of sampling points
cout<<"enter a number from 1 to 5"<<endl;
TF1 *f =new TF1("f","gaus");
TF1 *f1 =new TF1("f1","[0]/TMath::Sqrt(x)");
f1->SetParNames("k");
cin>>num;
Double_t mean,b;
ofstream out;
out.open("k.txt");
	for(q=0;q<10;q++)
	{//for the q
	  
	  h->Reset();
	  
		for(int j=0;j<10000;j++)
	{	//for the j
		sum=0;
		for(i=0;i<N;i++)
		{//for the i
		    Double_t rando=gen.Uniform(0,1);//generating random number in the range of integral
	
	   
        	            Double_t x=rando; //declaring x as raom
			    Double_t y=TMath::Power(x,num);//declaring y as integral value of x with user entered power num
			    sum+= y;
		}//for the i
		mean=sum/N;
		h->Fill(mean);
		}//for the j
h->Fit("f");
b=f->GetParameter(2);
out<<N<<"\t"<<b<<endl;
N*=2;
}//for q
out.close();
TGraph * g=new TGraph("k.txt");
g->SetMarkerStyle(20);
g->Draw("AP");
g->Fit("f1");
g->SetTitle("Uncertainity evaluation");
g->GetXaxis()->SetTitle("N");
g->GetXaxis()->CenterTitle();
g->GetYaxis()->SetTitle("#sigma");
g->GetYaxis()->CenterTitle();
g->GetYaxis()->SetTitleOffset(1.2);
}
