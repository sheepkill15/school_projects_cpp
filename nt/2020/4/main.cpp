#include <iostream>

using namespace std;

long long dalok[100000];
int n, k;
unsigned long long osszeg = 0;
long long kereses(long long mit)
{
    int i = 0; 
    int j = n - 1;

    struct {
        long long ertek = INT64_MAX;
        int index = -1;
    } mini;

    while(i <= j) {
        int kozep = (i + j) / 2;
        if(dalok[kozep] > mit) {
            j = kozep - 1;
        }
        else if(dalok[kozep] < mit) {
            i = kozep + 1;
        }
        else if(dalok[kozep] == mit) return kozep;
        if(dalok[kozep] - mit < mini.ertek) {
            mini = {dalok[kozep] - mit, kozep};
        }
    }
    return mini.index;
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        osszeg += x;
        dalok[i] = osszeg;
    }

    for(int i = 0; i < k; i++) {
        long long idopont;
        cin >> idopont;
        cout << kereses(idopont % osszeg) + 1 << endl;
    }
    cout << endl;
}