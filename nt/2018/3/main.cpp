#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("input");

#define cin fin

struct El {
    int honnan;
    int hova;
} elek[15001];

int uj_db = 1;

int n, m;

int hanyszor[10001];

bool latott[10001];

int csere[10001];

int melysegi(int pont) {
    latott[pont] = true;
    csere[pont] = uj_db++;
    int sum = 0;
    bool voltmar = false;
    for(int i = 1; i <= m; i++) {
        if(voltmar == false && elek[i].honnan == pont && csere[pont] > csere[elek[i].hova]) {
            sum++;
            voltmar = true;
        }
        if(elek[i].honnan == pont && latott[elek[i].hova] == false) {
            sum += melysegi(elek[i].hova); 
        }
    }
    return sum;
}

int main()
{

    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int honnan, hova;
        cin >> honnan >> hova;
        elek[i] = {honnan, hova};
        hanyszor[honnan]++;
    }

    int elagazasok_es_ciklusok = 0;

    for(int i = 1; i <= n; i++) {
        if(hanyszor[i] == 2) {
            elagazasok_es_ciklusok++;
        }
    }
    for(int i = 1; i <= n; i++) {
        csere[i] = INT32_MAX;
    }
    cout << melysegi(1) << endl;


    return 0;
}
