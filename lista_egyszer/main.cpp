#include <iostream>

using namespace std;

#define LISTA_VEGE keres(fej, -1)

struct Elem
{
    Elem *kovi;
    int adat;
};

Elem *letrehoz(int adat)
{
    return new Elem{nullptr, adat};
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
}


void illeszt_elotte(Elem* &igazi_fej, Elem* fej, int adat)
{
    if(igazi_fej == fej) {
        Elem *uj_fej = letrehoz(adat);
        uj_fej->kovi = igazi_fej;
        igazi_fej = uj_fej;
        return;
    }
    Elem *fej_elott = igazi_fej;
    while(fej_elott->kovi != fej) {
        fej_elott = fej_elott->kovi;
    }
    fej_elott->kovi = letrehoz(adat);
    fej_elott->kovi->kovi = fej;
}

void torol(Elem *&fej, Elem *mit)
{
    Elem *utana = mit->kovi;
    // if(fej == mit) {
    //     fej = fej->kovi;
    //     delete mit;
    //     return;
    // }
    Elem *elotte = fej;
    while(elotte != nullptr && elotte->kovi != mit) {
        elotte = elotte->kovi;
    }
    delete mit;
    elotte->kovi = utana;
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

void minden_egyszer(Elem* &fej) {

    bool tarolo[1000] = {false};

    Elem* kezdet = fej;
    while(kezdet->kovi != nullptr) {
        if(tarolo[kezdet->adat] == false) {
            tarolo[kezdet->adat] = true;
            kezdet = kezdet->kovi;
        }
        else {
            Elem* mentes = kezdet->kovi;
            torol(fej, kezdet);
            if(mentes == nullptr) {
                return;
            }
            kezdet = mentes;
        }
    }
}

Elem* lista_kozepe(Elem* fej, Elem* veg) {
    while(fej != veg) {
        fej = fej->kovi;
        Elem *elotte = fej;
        while(elotte != nullptr && elotte->kovi != veg) {
            elotte = elotte->kovi;
        }
        veg = elotte;
    }
    return fej;
}

void beszur_parosok(Elem* &fej) {
    Elem *copy = fej;
    while(copy != nullptr) {
        if(copy->adat % 2 == 0) {
            illeszt_elotte(fej, copy, -copy->adat);
        }
        copy = copy->kovi;
    }
}

int main()
{
    int n;
    cin >> n;
    int elso;
    cin >> elso;
    Elem* fej = letrehoz(elso);

    for(int i = 1; i < n; i++) {
        int adat;
        cin >> adat;
        illeszt_utana(LISTA_VEGE, adat);
    }
    kiir(fej);
    // minden_egyszer(fej);


    // kiir(fej);

    // cout << lista_kozepe(fej, LISTA_VEGE)->adat << endl;

    beszur_parosok(fej);
    kiir(fej);

    return 0;
}
