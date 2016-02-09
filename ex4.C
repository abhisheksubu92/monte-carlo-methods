#include "TGraph.h"
#include "TRandom.h"
#include "TStopwatch.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMath.h"
using namespace std;
/*
====================================================================================
In the First part of the code the various functions are defined 
in the second part the process of integration using monte carlo method is followed.

====================================================================================
The function to be integrated is a D dimensional function where D=1,...,8, Using the monte carlo method
*/


double func1(double x1)
{
Double_t y = TMath::Power(x1,2);
return y;
}


double func2(double x2,double x1)
{
Double_t y= TMath::Power(x2,2)+ func1(x1);
return y;
}
double func3(double x2,double x1,double x3)
{
Double_t y= func2(x1,x2)+TMath::Power(x3,2);
return y;
}


double func4(double x2,double x1,double x3,double x4)
{
Double_t y= func3(x1,x2,x3)+TMath::Power(x4,2);
return y;
}


double func5(double x2,double x1,double x3,double x4,double x5)
{
Double_t y= func4(x1,x2,x3,x4)+TMath::Power(x5,2);
return y;
}

double func6(double x2,double x1,double x3,double x4,double x5,double x6)
{
Double_t y= func5(x1,x2,x3,x4,x5)+TMath::Power(x6,2);
return y;
}

double func7(double x2,double x1,double x3,double x4,double x5,double x6,double x7)
{
Double_t y= func6(x1,x2,x3,x4,x5,x6) +TMath::Power(x7,2);
return y;
}

double func8(double x2,double x1,double x3,double x4,double x5,double x6,double x7,double x8)
{
Double_t y= func7(x1,x2,x3,x4,x5,x6,x7)+TMath::Power(x8,2);
return y;
}


/*

===============================================================================================
code for integration starts below.Here numbers are generated randomly from  
================================================================================================


*/
void ex4()
{
TRandom3 gen;
Double_t sum=0,mean,n=1000000;
TStopwatch w;
w.Start();
for(Int_t i=0;i<n;i++)
	{
	    Double_t x=gen.Uniform(0,1); // random number for x1
	    Double_t t= gen.Uniform(0,1);// random number for x2
	    Double_t a= gen.Uniform(0,1);//random number for x3
	    Double_t b=gen.Uniform(0,1);//random number of x4
	    Double_t c=gen.Uniform(0,1);//random number for x5
	    Double_t d=gen.Uniform(0,1);//random number for x6
	    Double_t e=gen.Uniform(0,1);//random number for x7
	    Double_t f=gen.Uniform(0,1);//random number for x8
	    Double_t z= func1(x);
	    sum+=z;


	}
w.Stop();
w.Print();
cout<<"Value of Integration is   "<<(sum/n)<<endl;



}
