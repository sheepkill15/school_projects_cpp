#include <iostream>

using namespace std;

int main()
{
    // egesz szamok

    int szam = 15;   // 10es szamrendszer
    szam = 017;      // 8as szamrendszer
    szam = 0xF;      // 16os szamrendszer
    unsigned long long nagy_szam = 15ull;  // u = unsigned, l = long, l = long

    // tizedes szamok

    float tizedes = 1.5;   // semmi nelkul egy double
    tizedes = 1.5f;        // igy mar igazi float
    tizedes = 15e-1f;      // ez is egy modja

    float szazalek = 15 / 100.f;

    // karakterek

    char karakter = 'a';   // sima aranyos 1 darab karakter
    karakter = '\n';       // enter karakter
    karakter = '\t';       // tab
    karakter = '\\';       // \ karakter
    karakter = '\'';       // ' karakter 

    // karakterlancok

    char uzenet[] = "hello there";         // sima szoveg
    char uzenet2[] = "hello" " " "there";  // ugyan az a szoveg, darabkakbol

    return 0;
}
