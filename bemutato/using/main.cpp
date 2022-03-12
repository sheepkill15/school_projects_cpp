#include <iostream>
#include <chrono>

using namespace std;

namespace Suli {
    void vakacio(int napok) {
        // ez a fuggveny adna vakaciot :p
    }

    int hany_diak() {
        return 0; // ki menne suliba?
    }
}

namespace {
    void csak_ebben_a_fileban() {
        // titkos stuff
    }
}

int main()
{
    // vakacio(10);


    Suli::vakacio(10);

    cout << Suli::hany_diak() << endl;

    using namespace Suli;

    vakacio(10);
    cout << hany_diak() << endl;

    csak_ebben_a_fileban();

    using nagy_szam = unsigned long long;

    nagy_szam tanulok_otthon = 68419;

    using ido_pont = chrono::system_clock::time_point;

    ido_pont ido = chrono::high_resolution_clock::now();

    return 0;
}
