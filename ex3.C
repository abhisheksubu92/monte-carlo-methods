#include "TGraph.h"
#include "TRandom.h"
#include "TStopwatch.h"
#include "TGraph.h"
#include "TAxis.h"
using namespace std;

void ex3()
{
	
	
	TCanvas *c =new TCanvas("c","Pi",0,0,1080,860);//creating a canvas to plot the fluctuations in pi
	
	TRandom3 gen;// invoking random number generator
	Double_t j=0,k=0; //setting counter j(counting points inside the circle) and k(counting points outside) 
	Double_t pi;
	
	Int_t cnt,i,n;
	ofstream out; //pointing to ofstream
	out.open("file.txt");//opening a file named "file.txt"
	TF1 *f=new TF1("f","3.1415926535",0,10000); //using the actual value of Pi 
	TF1 *f1=new TF1("f1","1/TMath::Sqrt(x)",1,10000);
	
		for(i=0;i<10000;i++)
			{
				Double_t r1=gen.Uniform(0,1);//generating random number for x
			       Double_t r2=gen.Uniform(0,1);//generating random number for y
			       Double_t x= -1+ 2*r1;//defining x
			        Double_t y=-1+2*r2;//defining y
			
				if(x*x + y*y <1)
					{
					   n=j++;
					   
					  }
				else
					{
					  k++;	
						}
				pi= (j/(j+k))*4;	
						out<<i<<"\t"<<pi<<std::endl;//writing the values of pi and number of couples to a file
				
				}
	
					
					

cout<<"number of points inside the circle is  "<<n<<endl; //counting number of points in the circle
out.close();
cout<<pi<<endl;// value of pi

c->cd(1);
TGraph *g= new TGraph("file.txt");//plotting the fluctuations in pi
g->Draw("AL");
g->SetTitle("Random Generation of Pi");

f->Draw("same");//drawing the function defined above in the same canvas to see the fluctuations

/*
The set of lines below is to change the color of line, set label to axis and to create legends.


*/
f->SetLineColor(kRed);
f->SetLineWidth(2);

g->GetYaxis()->SetRangeUser(3,3.7);
g->SetLineColor(kBlue);
g->GetXaxis()->SetTitle("# generated couples");
g->GetXaxis()->CenterTitle();
g->GetYaxis()->SetTitle("value of #pi");
g->GetYaxis()->CenterTitle();

leg = new TLegend(0.4,0.6,0.89,0.89);
leg->AddEntry(g,"Random value of #pi","l");
leg->AddEntry(f,"Actual value of #pi","l");
leg->Draw();

f1->Draw("same");
f1->SetLineColor(kGreen);
}

