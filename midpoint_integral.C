#include "TGraph.h"
#include "TRandom.h"
#include "TStopwatch.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TMath.h"
/*
===================================================================================================================================================
This code is to find the numerical value of Integration using the midpoint summation  rule

Here the space over which the function is integrated is divided into number of meshes and the value of the function is found
at the mid point of each of the division of each mesh and sumed to give the value of the integral. The value of the integral is the sum multiplied by 
the width of the interval
=====================================================================================================================================================
The code is divided into Two parts.
a) Definition of the function 
b) The main part where the loops are run

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




void mid()
{

Int_t D;

	for(D=1; D<9; D++)
	{
		
		if(D==1)
	
{
			
		   Double_t N=65536, n=65536;
		   Double_t dx=1/n;
		   Double_t sum=0,vmid;
		   	for(int i=0; i<n;i++)
			
			
		
		
			{
			   
	  		   Double_t x= dx/2+ (i/n);
			  
		 	   
			    vmid= func1(x);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 1 dimensions is  "<<sum<<endl;}
		if(D==2)
		{
			
		   Double_t N=65536, n=256;
		   Double_t dx=1/n;
		   Double_t sum=0,vmid;
		   	for(int i=0; i<n;i++)
			for (int j=0;j<n;j++) 
			
		
		
			{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   
			    vmid= func2(x,two);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 2 dimensions is  "<<sum<<endl;}
		if(D==3)
		{
			
		   Double_t N=64000, n=40;
		   Double_t dx=1/n;
		   Double_t sum=0,vmid;
		   	for(int i=0; i<n;i++)
			for (int j=0;j<n;j++) 
			for(int k=0;k<n;k++)
		
		
			{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   Double_t three=dx/2+(k/n);
			   
			    vmid= func3(x,two,three);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 3 dimensions is  "<<sum<<endl;}
		if(D==4)
		{
			
		   Double_t N=65536, n=16;
		   Double_t dx=1/n;
		   Double_t sum=0,vmid;
		   for(int i=0; i<n;i++)
		for (int j=0;j<n;j++) 
		for(int k=0;k<n;k++)
		for(int l=0;l<n;l++)
		
			{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   Double_t three=dx/2+(k/n);
			   Double_t four=dx/2+(l/n);
			   //Double_t five=dx/2+(m/16);
			  // Double_t six=dx/2+(m/n);
			    vmid= func4(x,two,three,four);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 4 dimensions is  "<<sum<<endl;}

		if(D==5)
{
		 Double_t N=59049,n=9;
		Double_t sum=0,vmid,dx=1/n;

		for(int i=0; i<n;i++)
		for (int j=0;j<n;j++) 
		for(int k=0;k<n;k++)
		for(int l=0;l<n;l++)
		for(int m=0;m<n;m++)
		
			{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   Double_t three=dx/2+(k/n);
			   Double_t four=dx/2+(l/n);
			   Double_t five=dx/2+(m/n);
			   Double_t six=dx/2+(m/n);
			    vmid= func5(x,two,three,four,five);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 5 dimensions is   "<<sum<<endl;}


if(D==6)
{
		 Double_t N=46656,n=6;
		Double_t sum=0,vmid,dx=1/n;

		for(int i=0; i<n;i++)
		for (int j=0;j<n;j++) 
		for(int k=0;k<n;k++)
		for(int l=0;l<n;l++)
		for(int m=0;m<n;m++)
		for(int p=0;p<n;p++)
			{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   Double_t three=dx/2+(k/n);
			   Double_t four=dx/2+(l/n);
			   Double_t five=dx/2+(m/n);
			   Double_t six=dx/2+(m/n);
			    vmid= func6(x,two,three,four,five,six);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 6 dimensions is   "<< sum<<endl;}
if(D==7)
{
		 Double_t N=78125,n=5;
		Double_t sum=0,vmid,dx=1/n;

		for(int i=0; i<n;i++)
		for (int j=0;j<n;j++) 
		for(int k=0;k<n;k++)
		for(int l=0;l<n;l++)
		for(int m=0;m<n;m++)
		for(int p=0;p<n;p++)
		for(int q=0;q<n;q++)
		{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   Double_t three=dx/2+(k/n);
			   Double_t four=dx/2+(l/n);
			   Double_t five=dx/2+(m/n);
			   Double_t six=dx/2+(p/n);
			   Double_t seven=dx/2+(q/n);
			    vmid= func7(x,two,three,four,five,six,seven);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 7 dimensions is   "<< sum<<endl;}

if(D==8)
{
		 Double_t N=65516,n=4;
		Double_t sum=0,vmid,dx=1/n;

		for(int i=0; i<n;i++)
		for (int j=0;j<n;j++) 
		for(int k=0;k<n;k++)
		for(int l=0;l<n;l++)
		for(int m=0;m<n;m++)
		for(int p=0;p<n;p++)
		for(int q=0;q<n;q++)
		for(int r=0; r<n;r++)
		{
			   
	  		   Double_t x= dx/2+ (i/n);
			   Double_t two= dx/2+(j/n);
		 	   Double_t three=dx/2+(k/n);
			   Double_t four=dx/2+(l/n);
			   Double_t five=dx/2+(m/n);
			   Double_t six=dx/2+(p/n);
			   Double_t seven=dx/2+(q/n);
			   Double_t eight =dx/2+(r/n);
			    vmid= func8(x,two,three,four,five,six,seven,eight);
			   sum+=vmid/N;
			}

cout<<"Value of Integral in 8 dimensions is   "<< sum<<endl;}
}




}

		






