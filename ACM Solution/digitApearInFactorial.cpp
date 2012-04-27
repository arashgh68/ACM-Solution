// acm_test.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>

int F_D_in_factorial(int ,int);

int _tmain(int argc, _TCHAR* argv[])
{

	int n,k,out;
	std::cin >> n;
	std::cin>>k;
	out = F_D_in_factorial(n,k);
	std::cout <<"Apear digit in factorial ="<<out<<"\n";
	return 0;
}

int F_D_in_factorial(int n ,int k)
{
	int indexChanged;
	int f[1000];
	int out=0;
	int cary=0;
	for(int i=0;i<1000;i++)
		f[i]=0;
	f[0] = 1;
	indexChanged = 1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<1000;j++)
		{
			f[j] = f[j] * i;
			if(cary!=0)
				f[j] = f[j]+cary;
			if(f[j]>9)
			{				
				cary = f[j] / 10;
				f[j] = f[j]%10;
			}
			else
				cary =0;
			if(j>indexChanged&& f[j]>0)
				indexChanged = j;
		}		
	}
	for(int i=0;i<indexChanged;i++)
	{
		if(f[i] == k)
			out++;
	}
	return out;
}

