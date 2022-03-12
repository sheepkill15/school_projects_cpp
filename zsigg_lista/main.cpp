#include <iostream>

using namespace std;

int n, m;

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

Elem *keres(Elem *fej, int index)
{
    Elem *copy = fej;
    for (int i = 0; copy->kovi != nullptr && index != i; i++)
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

void kiir(Elem *veg)
{
    Elem *copy = veg;
    while (copy != nullptr)
    {
        cout << copy->adat << ' ';
        copy = copy->elozo;
    }
    cout << endl;
}

void feladat(Elem* veg1, Elem* veg2)
{
    Elem* copy1 = veg1, *copy2 = veg2;
    bool tov = false;
    int adat = copy1->adat + copy2->adat;
    Elem *fej3 = letrehoz(adat % 10);
    if(adat / 10 > 0)
        tov = true;
    copy1 = copy1->elozo;
    copy2 = copy2->elozo;
    int k;
    if(n < m)
        k = n;
    else
        k = m;
    for(int i = 1; i < k; i++)
    {
        adat = copy1->adat + copy2->adat;
        if(tov == true)
            adat++;
        illeszt_utana(keres(fej3, -1), adat % 10);
        tov = false;
        if(adat / 10 > 0)
            tov = true;
        copy1 = copy1->elozo;
        copy2 = copy2->elozo;
    }
    for(int i = k; i < n; i++) {
        adat = copy1->adat;
        if(tov) {
            adat++;
            tov = false;
        }
        illeszt_utana(keres(fej3, -1), adat % 10);
        copy1 = copy1->elozo;
    }
    for(int i = k; i < m; i++) {
        adat = copy2->adat;
        if(tov) {
            adat++;
            tov = false;
        }
        illeszt_utana(keres(fej3, -1), adat % 10);
        copy2 = copy2->elozo;
    }
    kiir(keres(fej3, -1));
}

int main()
{
    cin >> n;
    int adat;
    cin >> adat;
    Elem* fej1 = letrehoz(adat);
    for(int i = 1; i < n; i++)
    {
        cin >> adat;
        illeszt_utana(keres(fej1, -1), adat);
    }
    cin >> m;
    cin >> adat;
    Elem* fej2 = letrehoz(adat);
    for(int i = 1; i < m; i++)
    {
        cin >> adat;
        illeszt_utana(keres(fej2, -1), adat);
    }
    feladat(keres(fej1, -1), keres(fej2, -2));
    return 0;
}