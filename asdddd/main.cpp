#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("adat.be");

struct Elem
{
    Elem *kovi;
    Elem *elozo;
    int oldal;
    char nev[30], cim[50];
};

Elem *letrehoz(int oldal, char nev[], char cim[])
{
    Elem* uj = new Elem;
    strcpy(uj->nev, nev);
    strcpy(uj->cim, cim);
    uj->oldal = oldal;
    uj->kovi = nullptr;
    uj->elozo = nullptr;
    return uj;
}

Elem *veg(Elem *fej)
{
    Elem *copy = fej;
    for (int i = 0; copy->kovi != nullptr; i++)
        copy = copy->kovi;
    return copy;
}

void illeszt_utana(Elem *fej, int oldal, char nev[], char cim[])
{
    Elem *fej_utan = fej->kovi;
    fej->kovi = letrehoz(oldal, nev, cim);
    fej->kovi->kovi = fej_utan;
    fej->kovi->elozo = fej;
    if(fej_utan != nullptr)
        fej_utan->elozo = fej->kovi;
}

int beolvassz() 
{
    int adat;
    char seged[10];
    fin >> adat;
    fin.getline(seged, 9);
    return adat;
}

void beolvasm(char seged[100])
{
    fin.getline(seged, 100);
}

void feladat(Elem* fej, char keres[])
{
    int ossz = 0;
    Elem* seged = fej;
    while(seged->kovi != nullptr)
    {
        if(strcmp(seged->nev, keres) == 0)
            ossz += seged->oldal;
        seged = seged->kovi;
    }
    cout << ossz;
}

void kiir(Elem *fej)
{
    Elem *copy = fej;
    while (copy != nullptr)
    {
        cout << copy->nev << " " << copy->cim << " " << copy->oldal << endl;
        copy = copy->kovi;
    }
}

int main()
{
    int n = beolvassz();
    char nev[30], cim[50];
    beolvasm(nev);
    beolvasm(cim);
    int oldal = beolvassz();
    Elem* fej = letrehoz(oldal, nev, cim);
    for(int i = 1; i < n; i++)
    {
        beolvasm(nev);
        beolvasm(cim);
        oldal = beolvassz();
        illeszt_utana(veg(fej), oldal, nev, cim);
    }
    char keres[30];
    beolvasm(keres);
    //feladat(fej, keres);
    kiir(fej);
    return 0;
}