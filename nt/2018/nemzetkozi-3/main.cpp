#include <iostream>
#include <unordered_map>
// #include <fstream>

using namespace std;

// ifstream fin("input");
// #define cin fin

int igen_gy[10001];
int nem_gy[10001];

int cimkek[20001];

void cimke_feltolt(int gy) {
    if(gy < 1) {
        return;
    }

    cimkek[igen_gy[gy]] = cimkek[gy] + 1;
    cimkek[nem_gy[gy]] = cimkek[gy] - 1;

    cimke_feltolt(igen_gy[gy]);
    cimke_feltolt(nem_gy[gy]);
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int igengy;
        int nemgy;
        cin >> igengy >> nemgy;
        igen_gy[i] = igengy;
        nem_gy[i] = nemgy;
    }

    cimke_feltolt(1);
    unordered_map<int, int> hanyszor;
    for(int i = n + 1; i <= 2*n + 1; i++) {
        if(hanyszor.find(cimkek[i]) == hanyszor.end()) {
            hanyszor[cimkek[i]] = 0;
        }
        hanyszor[cimkek[i]]++;
    }

    int maxi = -1;
    int maxiCimke = -1;

    for(auto& val : hanyszor) {
        if(maxi < val.second) {
            maxi = val.second;
            maxiCimke = val.first;
        }
    }
    cout << maxiCimke << ' ' << maxi << endl;
}