#include <iostream>
using namespace std;
struct csucs
{
	int be=0,fokszam=0;//max mekkora sebeseggel lehet eljutni az eppen vizsgalt csucsbol ide 
	int gyerekek[100];
	int sulyok[100];	
};
int main()
{
	int n,usz;
	cin>>n>>usz;//csucsok szama, utak szama
	csucs csucsok[n];
	for(int i=0;i<usz;i++)
	{
		int honnan,hova,s;
		cin>>honnan>>hova>>s;
		honnan--;hova--;
		csucsok[honnan].gyerekek[csucsok[honnan].fokszam]=hova;
		csucsok[honnan].sulyok[csucsok[honnan].fokszam]=s;
		csucsok[honnan].fokszam++;
	}
	int max=0,maxi=-1;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)		
		{
			csucsok[j].be=0;
		}
		csucsok[i].be=100001;
		int soreleje=0,sorvege=1;
		short int sor[10000*n];
		sor[0]=i;
		while(soreleje<sorvege)
		{
			for(int j=0;j<csucsok[sor[soreleje]].fokszam;j++)
			{
				int ls=csucsok[sor[soreleje]].sulyok[j];//a sebesseg lekorlatozva.
				if(csucsok[sor[soreleje]].be<ls)
				{
					ls=csucsok[sor[soreleje]].be;
				}
				if(csucsok[csucsok[sor[soreleje]].gyerekek[j]].be<ls)
				{
					sor[sorvege]=csucsok[sor[soreleje]].gyerekek[j];
					sorvege++;
					csucsok[csucsok[sor[soreleje]].gyerekek[j]].be=ls;
				}
			}
			soreleje++;
		}
		long int min=100000;
		for(int l=0;l<n;l++)
		{
			if(min>csucsok[l].be)
			{
				min=csucsok[l].be;
			}
		}
		//cout<<i+1<<" ossz: "<<ossz-100001<<endl;
		if(min>max)
		{
			max=min;
			maxi=i;
		}
	}
	cout<<maxi+1;
	return 0;
}
