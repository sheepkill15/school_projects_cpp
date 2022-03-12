#include <iostream>
//#include <fstream>
#include <algorithm>
using namespace std;

//ifstream fin("input");
//#define cin fin

struct Gyerek {
    int kivant_szerep;
    int siras;
    int index;
};

Gyerek gyerekek[100001];
int szerep_max[100001];
int szerep_frekv[100001];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> szerep_max[i+1];
    }
    for(int i = 0; i < n; i++) {
        cin >> gyerekek[i].kivant_szerep;
        szerep_frekv[gyerekek[i].kivant_szerep]++;
    }
    for(int i = 0; i < n; i++) {
        cin >> gyerekek[i].siras;
        gyerekek[i].index = i;
    }

    sort(gyerekek, gyerekek+n, [](const Gyerek&a, const Gyerek&b){return a.siras < b.siras;});
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int szerep = gyerekek[i].kivant_szerep;
        if(szerep_frekv[szerep] > szerep_max[szerep]) {
            int min_szerep = 100001;
            int min_szerep_szam = -1;
            for(int i = 1; i <= k; i++) {
                if(i != szerep && szerep_frekv[i] < min_szerep) {
                    min_szerep = szerep_frekv[i];
                    min_szerep_szam = i;
                }
            }
            gyerekek[i].kivant_szerep = min_szerep_szam;
            szerep_frekv[min_szerep_szam]++;
            szerep_frekv[szerep]--;
            sum += gyerekek[i].siras;
        }
    }

    sort(gyerekek, gyerekek+n, [](const Gyerek&a, const Gyerek&b) {return a.index < b.index;});
    cout << sum << endl;
    for(int i = 0; i < n; i++) {
        cout << gyerekek[i].kivant_szerep << ' ';
    }
    cout << endl;

    return 0;
}
