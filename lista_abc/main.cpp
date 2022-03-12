#include <iostream>
#include <fstream>
#include <cstring>
#define cin fin

using namespace std;


/*
* Pelda bemenet: 
* 1             // n
* 14            // 14 eves
* jozsi         // jozsi a neve
*/
ifstream fin("bemenet.be");

#define LISTA_VEGE keres(fej, -1)

struct Elem
{
    Elem *kovi;
    Elem *elozo;
    int eletkor;
    char nev[256];
};

Elem *letrehoz(int eletkor, const char* nev)
{
    Elem* uj_elem = new Elem{nullptr, nullptr, eletkor};
    strcpy(uj_elem->nev, nev);
    return uj_elem;
}

Elem *keres(Elem *fej, int ertek)
{
    Elem *copy = fej;
    for (int i = 0; copy->kovi != nullptr && copy->eletkor != ertek; i++)
    {
        copy = copy->kovi;
    }
    return copy;
}

void illeszt_utana(Elem *fej, int adat, const char* nev)
{
    Elem *fej_utan = fej->kovi;
    fej->kovi = letrehoz(adat, nev);
    fej->kovi->kovi = fej_utan;
    fej->kovi->elozo = fej;
    if(fej_utan != nullptr)
        fej_utan->elozo = fej->kovi;
}

void torol(Elem *fej, Elem *mit)
{
    Elem *utana = mit->kovi;
    Elem *elotte = fej->elozo;
    delete mit;
    elotte->kovi = utana;
    fej->elozo = utana;
}

void kiir(Elem *fej)
{
    Elem *copy = fej;
    while (copy != nullptr)
    {
        cout << copy->eletkor << ' ' << copy->nev << endl;
        copy = copy->kovi;
    }
    cout << endl;
}

void csere(Elem *a, Elem *b) {
    char seged[256];
    strcpy(seged, a->nev);
    strcpy(a->nev, b->nev);
    strcpy(b->nev, seged);

    int seged_eletkor = a->eletkor;
    a->eletkor = b->eletkor;
    b->eletkor = seged_eletkor;
}

void rendez(Elem* fej) {
    bool ok = false;
    do {
        Elem* p = fej;
        ok = false;
        while(p->kovi != nullptr) {
            if(strcmp(p->nev, p->kovi->nev) > 0) {
                ok = true;
                csere(p, p->kovi);
            }
            p = p->kovi;
        }
    }while(ok);
}

int main()
{
    int n;
    int eletkor_seged;
    cin >> n;


    char seged[256];
    cin >> eletkor_seged;
    cin.getline(seged, 1);
    cin.getline(seged, 255);
    
    
    Elem *fej = letrehoz(eletkor_seged, seged);
    kiir(fej);
    for(int i = 0; i < n - 1; i++) {
        cin >> eletkor_seged;
        cin.getline(seged, 1);
        cin.getline(seged, 255);
        illeszt_utana(LISTA_VEGE, eletkor_seged, seged);
    }
    kiir(fej);
    rendez(fej);
    kiir(fej);

    return 0;
}
