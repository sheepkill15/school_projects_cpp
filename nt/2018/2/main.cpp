#include <iostream>
// #include <fstream>
#include <vector>

using namespace std;

// ifstream fin("input");

// #define cin fin

int varos[200][200];
int seged[200][200];
int n, m, k;

int main()
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> varos[i][j];
        }
    }
    struct {
        int ertek = 0;
        int i;
        int j;
    } maxi;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int egyik = 0;
            int masik = 0;
            if(i > 0 && abs(varos[i][j] - varos[i-1][j]) <= k) {
                egyik = seged[i-1][j];
            }
            if(j > 0 && abs(varos[i][j] - varos[i][j-1]) <= k) {
                masik = seged[i][j-1];
            }
            seged[i][j] = max(egyik, masik) + 1;
            if(seged[i][j] >= maxi.ertek) {
                maxi = {seged[i][j], i, j};
            }
        }
    }
    maxi.ertek --;
    cout << maxi.ertek << endl;

    vector<char> lepesek(maxi.ertek);

    int i = maxi.i;
    int j = maxi.j;

    while(seged[i][j] > 1) {
        int le = 0;
        int jobbra = 0;
        if(abs(varos[i][j] - varos[i-1][j]) <= k) {
            le = seged[i-1][j];
        }
        if(abs(varos[i][j] - varos[i][j-1]) <= k) {
            jobbra = seged[i][j-1];
        }

        if(le > jobbra) {
            lepesek.push_back('L');
            i--;
        } else {
            lepesek.push_back('J');
            j--;
        }
    }
  
    cout << i + 1 << ' ' << j + 1 << endl;

    for(auto it = lepesek.rbegin(); it != lepesek.rend(); it++) {
        cout << *it;
    }
    cout << endl;


    return 0;
}
