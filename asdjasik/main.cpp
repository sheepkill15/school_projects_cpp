#include <iostream>

using namespace std;

struct Elem {
    int fontos;

    Elem *utana, *elotte;
};

Elem *fej; // lista elso eleme
Elem *veg; // lista utolso eleme

void letrehozas(int fontos) {
    fej = new Elem;
    fej->fontos = fontos;
    fej->utana = nullptr;
    fej->elotte = nullptr;
    veg = fej;
}

void hozzaadas(int fontos) {      // a lista vegere
    Elem *uj_elem = new Elem;
    veg->utana = uj_elem;
    uj_elem->fontos = fontos;
    uj_elem->elotte = veg;
    uj_elem->utana = nullptr;
    veg = uj_elem;
}

void beilleszt_utana(Elem* mi_utan, int fontos) {
    Elem *uj_elem = new Elem;
    uj_elem->fontos = fontos;

    Elem *eddigi_utan = mi_utan->utana;

    mi_utan->utana = uj_elem;
    uj_elem->elotte = mi_utan;

    if(eddigi_utan != nullptr) {
        eddigi_utan->elotte = uj_elem;
    } else {
        veg = uj_elem;
    }

    uj_elem->utana = eddigi_utan;
}

void beilleszt_elotte(Elem* mi_ele, int fontos) {
    Elem *uj_elem = new Elem;
    uj_elem->fontos = fontos;

    Elem *eddigi_elott = mi_ele->elotte;

    mi_ele->elotte = uj_elem;
    uj_elem->utana = mi_ele;

    if(eddigi_elott != nullptr) {
        eddigi_elott->utana = uj_elem;
    } else {
        fej = uj_elem;
    }

    uj_elem->elotte = eddigi_elott;
}

void torles(int fontos) {
    Elem *copy = fej;
    while(copy != nullptr) {
        if(copy->fontos == fontos) {

            Elem* copy_elott = copy->elotte;
            Elem* copy_utan = copy->utana;

            if(copy_elott != nullptr) {
                copy_elott->utana = copy_utan;
            }
            else {
                fej = copy_utan;
            }
            if(copy_utan != nullptr) {
                copy_utan->elotte = copy_elott;
            }
            else {
                veg = copy_elott;
            }

            delete copy;

            copy = copy_elott;
            
            if(copy == nullptr) {
                copy = copy_utan;
                continue;
            }

            // return;
        }

        copy = copy->utana;
    }
}

void kiir() {
    
    Elem *copy = fej;
    while(copy != nullptr) {
        
        cout << copy->fontos << ' ';
        copy = copy->utana;
    
    }
    cout << endl;
}

Elem* keres(int hanyadik) {
    Elem* copy = fej;
    for(int i = 0; i < hanyadik && copy->utana != nullptr; i++) {
        copy = copy->utana;
    }
    return copy;
}

int main()
{
    letrehozas(69);
    hozzaadas(420);
    beilleszt_utana(fej, 69420);
    beilleszt_elotte(fej->utana, 42069);
    kiir();
    torles(69420);
    kiir();
    beilleszt_utana(keres(3), 96);
    kiir();

    return 0;
}
