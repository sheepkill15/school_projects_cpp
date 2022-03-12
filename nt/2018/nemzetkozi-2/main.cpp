#include <iostream>
// #include <fstream>

using namespace std;

// ifstream fin("input");
// #define cin fin

int tabla[100][100];
int ertekek[100][100];
int n, m;

int visszakeres(int i, int j) {
    if(j == 0) {
        return i;
    }
    
    int opc1 = ertekek[i][j-1];
    int opc2 = -1;

    if(i > 0) {
        opc2 = ertekek[i-1][j-1];
    }
    int opc3 = -1;
    if(i < n - 1) {
        opc3 = ertekek[i+1][j-1];
    }

    int maxiOpc = std::max(opc1, std::max(opc2, opc3));
    
    if(maxiOpc == opc1) {
        return visszakeres(i, j - 1);
    }
    if(maxiOpc == opc2) {
        return visszakeres(i - 1, j - 1);
    }
    return visszakeres(i + 1, j - 1);
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tabla[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        ertekek[i][0] = tabla[i][0];
    }
    for(int j = 1; j < m; j++) {
        for(int i = 0; i < n; i++) {
            int ertek = 0;

            if(i > 0) {
                ertek = std::max(ertek, ertekek[i-1][j-1]);
            }
            if(i < n - 1) {
                ertek = std::max(ertek, ertekek[i+1][j-1]);
            }
            ertek = std::max(ertek, ertekek[i][j - 1]);
            ertekek[i][j] = ertek + tabla[i][j];
        }
    }

    int maxi = -1;
    int maxiIndex = 0;

    for(int i = 0; i < n; i++) {
        if(ertekek[i][m - 1] > maxi) {
            maxi = ertekek[i][m - 1];
            maxiIndex = i;
        }
    }
    cout << maxi << endl;

    cout << visszakeres(maxiIndex, m - 1) + 1 << endl;

}