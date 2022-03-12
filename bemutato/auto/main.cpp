#include <iostream>

using namespace std;

struct nagyon_hosszu_nevu_struktura {
    int a;
};

nagyon_hosszu_nevu_struktura kell_struktura() {
    return {5};
}

auto kell_struktura_auto() {
    return nagyon_hosszu_nevu_struktura{10};
}

auto kell_bizonyos_tipus() -> float {
    return 5;
}


int main()
{

    auto szam = 5;  // int
    auto szoveg = "Hello there";   // const char* <=> char[12]

    auto struktura = kell_struktura();

    auto masik_struktura = kell_struktura_auto();

    cout << struktura.a << endl;
    cout << masik_struktura.a << endl;

    auto fuggveny = kell_bizonyos_tipus;

    cout << fuggveny() << endl;

    return 0;
}
