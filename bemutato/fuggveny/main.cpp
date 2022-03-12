#include <iostream>
#include <algorithm>
using namespace std;


int main()
{

    struct Tort {
        int szamlalo;
        int nevezo;
    };

    Tort tort[100];
    int n = 5;


    sort(tort, tort + n, [](Tort egyik, Tort masik) {
        return egyik.szamlalo / egyik.nevezo < masik.szamlalo / masik.nevezo;
    });

    return 0;
}
