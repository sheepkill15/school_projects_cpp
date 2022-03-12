#include <iostream>
// #include <fstream>

using namespace std;

// ifstream fin("input");

// #define cin fin

int napok[100000];
int milyen_napok[100000];
int n;

bool nap_meleg(int i) {
    if(i >= n) return false;
    return milyen_napok[i] == 1;
}

bool nap_hideg(int i) {
    if(i >= n) return false;
    return milyen_napok[i] == 2;
}

int milyen_nap(int i) {
if(napok[i-1] > napok[i] && napok[i+1] > napok[i]) {
                return 2;
            }

            if(napok[i-1] < napok[i] && napok[i+1] < napok[i]) {
                return 1;
            }
            
            return 0;
}

int main()
{
    int k, l;
    cin >> n >> k >> l;

    int kezd = 0;
    int veg = 0;

    int hideg = 0;
    int meleg = 0;

    int db = 0;

    for(int i = 0; i < n; i++) {
        cin >> napok[i];
    }
    for(int i = 1; i < n - 1; i++) {
        milyen_napok[i] = milyen_nap(i);
    }

    int utolso_veg = 0;

    while(veg <= n) {
        if(meleg <= k && hideg <= l && veg != n) {
            if(nap_meleg(veg)) {
                meleg++;
            }
            else if(nap_hideg(veg)) {
                hideg++;
            }
            veg++;
        } else {
            int veg_mentes = veg;
            veg = max(utolso_veg - 1, kezd);
            for(int j = veg_mentes - 1; j >= veg; j--) {
                if(nap_meleg(j)) {
                    meleg--;
                }
                else if(nap_hideg(j)) {
                    hideg--;
                }
            }
            if(nap_meleg(kezd)) {
                meleg--;
            }
            if(nap_hideg(kezd)) {
                hideg--;
            }
            kezd++;
        }
        if(meleg == k && hideg == l) {
            db++;
            utolso_veg = veg - 1;
        }
    }
    
    cout << db << endl;

    return 0;
}
