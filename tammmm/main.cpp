#include <iostream>
#include <string.h>

using namespace std;

struct Elem
{
    int inf;
    Elem *kov;
};

Elem *fej, *veg;

void letrehoz(Elem *&fej, Elem *&veg)
{
    fej = new Elem;
    cout << "Kerem az infot: ";
    cin >> fej->inf;
    fej->kov = 0;
    veg = fej;
}

void hozzaad(Elem *&veg)
{
    Elem *akt = new Elem;
    cout << "Kerem az infot: ";
    cin >> akt->inf;
    akt->kov = 0;
    veg->kov = akt;
    veg = akt;
}

void elebeszuras(Elem *fej, Elem *besz, Elem *&p)
{
    if (p)
    {
        besz->kov = p->kov;
        p->kov = besz;
    }
}

void bejaras(Elem *fej, Elem *p)
{
    p = fej;
    while (p)
    {
        if (p->inf % 2 == 0)
        {
            Elem *ment = new Elem;
            ment->inf = p->inf;
            ment->inf *= -1;
            elebeszuras(fej, ment, p);
            p = p->kov;
        }
        p = p->kov;
    }
}

int main()
{

    Elem *p;
    int n;

    cout << "Hany elem lesz?" << endl;
    cin >> n;
    letrehoz(fej, veg);

    for (int i = 0; i < n - 1; i++)
        hozzaad(veg);
    cout << endl;

    bejaras(fej, p);
    return 0;
}