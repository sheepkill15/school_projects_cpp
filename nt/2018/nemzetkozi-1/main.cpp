#include <iostream>
// #include <fstream>

using namespace std;


// ifstream fin("input");
// #define cin fin

// elso nap min
// masik nap max
// kulonbseg leheto legnagyobb

int main() {

    int n;
    cin >> n;

    struct {
        int elso = -1;
        int masodik = -1;
        int kulonbseg = -1;
    } maxi;
    
    int elso;
    int elsoIndex = 0;
    int elozo = 0;

    cin >> elso;

    for(int i = 1; i < n; i++) {
        int nap;
        cin >> nap;

        if(nap < elso) {
            elso = nap;
            elsoIndex = i;
        }
        if(maxi.kulonbseg < (nap - elso)) {
              maxi = {elsoIndex, i, nap - elso};
        }
        elozo = nap;
    }

    cout << maxi.elso + 1 << ' ' << maxi.masodik + 1 << endl;

}