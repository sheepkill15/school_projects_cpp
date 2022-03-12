#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("Auto.in");
ofstream fout("Auto.out");

struct kocsi
{
int ido;
int szam;
};
kocsi kocsitomb[100];
int n, T;
void beolvasas()
{
    fin >> n;
    fin >> T;
    for(int i = 0; i < n; i++)
    {
        fin >> kocsitomb[i].ido;
        kocsitomb[i].szam = i + 1;
    }
}
void kiiras()
{
    for(int i = 0; i < n; i++)
    {
        fout << kocsitomb[i].ido << " ";
    }
	fout << endl;
}

void rendezes()
{
    int p = 1;
    kocsi segedkocsi;
	do
    {
        p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (kocsitomb[i].ido > kocsitomb[i + 1].ido)
            {
                p = 1;
                segedkocsi = kocsitomb[i];
                kocsitomb[i] = kocsitomb[i + 1];
                kocsitomb[i + 1] = segedkocsi;
            }
        }
    }while(p == 1);
}

void szam()
{
	int osszeg = 0;
	for(int i = 0; i < n; i++) {
    	if (osszeg + kocsitomb[i].ido <= T)
    	{
    	    osszeg = osszeg + kocsitomb[i].ido;
    	    fout << kocsitomb[i].szam << ' '; 
    	}
	}
	fout << endl;
}

int main()
{
    beolvasas();
	rendezes();
	kiiras();
	szam();
    return 0;
}