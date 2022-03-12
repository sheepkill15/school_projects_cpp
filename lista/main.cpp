#include <iostream>

using namespace std;

#define LISTA_VEGE keres(fej, -1)

struct Elem
{
    Elem *kovi;
    Elem *elozo;
    int adat;
};

Elem *letrehoz(int adat)
{
    return new Elem{nullptr, nullptr, adat};
}

Elem *keres(Elem *fej, int ertek)
{
    Elem *copy = fej;
    for (int i = 0; copy->kovi != nullptr && copy->adat != ertek; i++)
    {
        copy = copy->kovi;
    }
    return copy;
}

void illeszt_utana(Elem *fej, int adat)
{
    Elem *fej_utan = fej->kovi;
    fej->kovi = letrehoz(adat);
    fej->kovi->kovi = fej_utan;
    fej->kovi->elozo = fej;
    if(fej_utan != nullptr)
        fej_utan->elozo = fej->kovi;
}


void illeszt_elotte(Elem* &fej, int adat)
{
    Elem *fej_elott = fej->elozo;
    if(fej_elott == nullptr) {
        fej->elozo = letrehoz(adat);
        fej->elozo->kovi = fej;
        fej = fej->elozo;
        return;
    }
    fej_elott->kovi = letrehoz(adat);
    fej_elott->kovi->kovi = fej;
    fej_elott->kovi->elozo = fej_elott;
    fej->elozo = fej_elott->kovi;
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
        cout << copy->adat << ' ';
        copy = copy->kovi;
    }
    cout << endl;
}

int main()
{
    Elem *fej = letrehoz(5);
    kiir(fej);
    illeszt_utana(fej, 2);
    kiir(fej);
    illeszt_utana(LISTA_VEGE, 4);
    kiir(fej);
    illeszt_elotte(fej, 14);
    kiir(fej);

    return 0;
}
