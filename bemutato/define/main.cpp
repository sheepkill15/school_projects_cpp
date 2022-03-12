#include <iostream>
#include <stdio.h>

using namespace std;

#define PI 3.1415

#define KIIRAS(x) cout << x << endl

#define KIIRAS_NEV(x) cout << #x << endl

#define FOR_CIKLUS(x) for(int i = 0; i < x; i++)

#define KIIR_HA_NAGYOBB_MINT_0(x) if(x > 0) { \
    cout << x << endl; \
}

#define LEFUTTAT(x) cout << #x << " = " << x() << endl

int kiszamolja_az_elet_ertelmet() {
    return 42;
}

int main()
{

    LEFUTTAT(kiszamolja_az_elet_ertelmet);


    
    // cout << 3.1415 << endl;

    // KIIRAS(15);


    // FOR_CIKLUS(5) {
    //     KIIRAS(i);
    // }

    // KIIR_HA_NAGYOBB_MINT_0(10);

    return 0;
}
