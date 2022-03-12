#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("kruszkal.be");
ofstream fout("kruszkal.ki");

int n,m,latott[100],megoldas[2][100];
int k=0;

struct krusz
{
    int a;
    int b;
    int c;
};

krusz t[100];

void latottT()
{
    for(int i=1;i<=n;i++)
        latott[i]=i;
}

void beolvas()
{
    fin >> n >> m;
    for(int i=0;i<m;i++)
        fin >> t[i].a>>t[i].b>>t[i].c;
}

void rendezes()
{
    bool el=true;
    while(el==true){
        el=false;
        for(int i=0;i<m-1;i++){
            krusz a=t[i];
            if(t[i].c > t[i + 1].c)
               { t[i]=t[i+1];
                t[i+1]=a;
                el=true;}
        }
    }
}

void kruszkal()
{
    for(int i=0;i<m;i++){
        if(k==n)
            break;
        if(latott[t[i].a]!= latott[t[i].b]){
            if(latott[t[i].a]>latott[t[i].b])
              {  
				  int latottnagyobb = latott[t[i].a];
				  for(int j=1;j<=n;i++)
                    if(latott[j]==latottnagyobb)
                        latott[j]=latott[t[i].b];}
            else
                {
				  	int latottnagyobb = latott[t[i].b];
					for(int j=1;j<=n;i++)
                    if(latott[j]==latottnagyobb)
                        latott[j]=latott[t[i].a];}
            megoldas[0][k]=t[i].a;
            megoldas[1][k]=t[i].b;
            k++;
        }
    }
}

void kiiras()
{
    for(int i=0;i<k;i++){
        for(int j=0;j<2;j++)
            fout << megoldas [j][i] << " ";
        fout << '\n';
    }
}

int main()
{
    beolvas();
    latottT();
    rendezes();
    kruszkal();
    kiiras();
    return 0;
}