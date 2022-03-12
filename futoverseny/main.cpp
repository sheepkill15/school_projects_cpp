#include <iostream>
#include <fstream>
#include <cstring>
#define cin fin

using namespace std;

ifstream fin("bemenet.be");

#define LISTA_VEGE keres(fej, -1)

struct Elem
{
    char nev[256];
    time_t ind, veg;
    Elem *kovi;
};

Elem *letrehoz(const char* nev, time_t ind, time_t veg)
{
    Elem* uj = new Elem;
    strcpy(uj->nev, nev);
    uj->ind = ind;
    uj->veg = veg;
    uj->kovi = nullptr;
    return uj;
}

Elem* keres(Elem* fej, int _) {
    Elem* copy = fej;
    while(copy->kovi) {
        copy = copy->kovi;
    }
    return copy;
}

void illeszt_utana(Elem *fej, const char* nev, time_t ind, time_t veg)
{
    Elem *fej_utan = fej->kovi;
    fej->kovi = letrehoz(nev, ind, veg);
    fej->kovi->kovi = fej_utan;
}

void kiir(Elem *fej)
{
    Elem *copy = fej;
    while (copy != nullptr)
    {
        cout << copy->nev << endl;
        copy = copy->kovi;
    }
}

int beolvas() {
    int adat;
    char seged[10];
    cin >> adat;
    cin.getline(seged, 9);
    return adat;
}

void beolvas(char hova[]) {
    cin.getline(hova, 256);
}
void csere(Elem *a, Elem *b) {
    char seged[256];
    strcpy(seged, a->nev);
    strcpy(a->nev, b->nev);
    strcpy(b->nev, seged);

    time_t seged_ind = a->ind;
    a->ind = b->ind;
    b->ind = seged_ind;

    time_t seged_veg = a->veg;
    a->veg = b->veg;
    b->veg = seged_veg;
}

void rendez(Elem* fej) {
    bool ok = false;
    do {
        Elem* p = fej;
        ok = false;
        while(p->kovi != nullptr) {
            if(p->veg - p->ind > p->kovi->veg - p->kovi->ind) {
                ok = true;
                csere(p, p->kovi);
            }
            p = p->kovi;
        }
    }while(ok);
}

void rangsor(Elem* fej) {
    rendez(fej);

    Elem* copy = fej;
    for(int i = 0; i < 3 && copy != nullptr; i++) {
        cout << i+1 << ' ' << copy->nev << endl;
        copy = copy->kovi;
    }
}

int main()
{
    int n = beolvas();
    char nev[256];
    beolvas(nev);
    time_t ind = beolvas(), veg = beolvas();
    Elem* fej = letrehoz(nev, ind, veg);

    for(int i = 1; i < n; i++) {
        beolvas(nev);
        ind = beolvas();
        veg = beolvas();
        illeszt_utana(LISTA_VEGE, nev, ind, veg);
    }
    kiir(fej);

    rangsor(fej);

    return 0;
}
