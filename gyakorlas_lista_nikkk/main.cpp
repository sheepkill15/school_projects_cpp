#include <iostream>

using namespace std;

#define semmi nullptr

//egyszeresen lancolt lista
struct Elem {
    int adat;
    Elem* kovetkezo;
};

Elem* fej; // legelso   elem
Elem* veg; // legutolso elem

void letrehozas(int adat) {
    fej = new Elem;
    fej->adat = adat;
    fej->kovetkezo = semmi;
    veg = fej;
}

void hozzaadas(int adat) {
    Elem* uj = new Elem;
    uj->adat = adat;
    veg->kovetkezo = uj;
    veg = uj;
    uj->kovetkezo = semmi;
}

void beszuras_utana(Elem* mi_utan, int mit) {
    Elem* uj = new Elem;
    uj->adat = mit;

    uj->kovetkezo = mi_utan->kovetkezo;
    mi_utan->kovetkezo = uj;
}

int main()
{
    cout << "Hello world!" << endl;

    return 0;
}
