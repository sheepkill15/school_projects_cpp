#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#define cin fin

using namespace std;

ifstream fin("adat.be");

int matrix[100][100];
int n, m;

const int inf = 1e5;
const int padding = log10(inf);

void beallit() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j)
                matrix[i][j] = inf;
        }
    }
}

void beolvas()
{
    for (int i = 0; i < m; i++)
    {
        int elso, masodik, koltseg;
        cin >> elso >> masodik >> koltseg;
        matrix[elso][masodik] = koltseg;
    }
}

void roy_floyd()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ( matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
}

void visszafejt(int i, int j) {
    int k = 1;
    while(k <= n) {
        if(i != k && j != k) {
            if(matrix[i][j] == matrix[i][k] + matrix[k][j]) {
                visszafejt(i, k);
                visszafejt(k, j);
                return;
            }
        }
        k++;
    }
    cout << j << ' ';
}

void kiir() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << setw(padding + 1) << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;
    beallit();
    beolvas();
    roy_floyd();
    kiir();
    int elso, masodik;
    // cout << "A: ";
    cin >> elso;
    // cout << "B: ";
    cin >> masodik;
    visszafejt(elso, masodik);
    cout << endl;

    return 0;
}
