#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;

ifstream fin("firma.in");
ofstream fout("firma.out");

const int INF = 1e4;

int n, m;
int matrix[101][101];
bool latott[101];
int ut[101];
int apa[101];

int megoldasok[101];

void beolvas() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int elso, masodik, harmadik;
        cin >> elso >> masodik >> harmadik;
        matrix[elso][masodik] = harmadik;
        matrix[masodik][elso] = harmadik;
    }
}

void beallit(int pont) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || matrix[i][j]) {
                continue;
            }
            matrix[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i != pont)
            ut[i] = INF;
    }
}

int elso_pont() {
    struct {
        int pont = -1;
        int ertek = INF + 1;
    } mini;
    for(int i = 1; i <= n; i++) {
        if(!latott[i] && ut[i] < mini.ertek) {
            mini.ertek = ut[i];
            mini.pont = i;
        }
    }
    return mini.pont;
}

bool check() {
    for(int i = 1; i <= n; i++) {
        if(!latott[i] && ut[i] != INF) {
            return false;
        }
    }
    return true;
}

void dijkstra() {
    while(!check()) {
        const int jelenlegi = elso_pont();
        for(int i = 1; i <= n; i++) {
            if(i == jelenlegi) {
                continue;
            }
            const int sum = ut[jelenlegi] + matrix[jelenlegi][i];
            if(ut[i] > sum) {
                ut[i] = sum;
                apa[i] = jelenlegi;
            }
        }
        latott[jelenlegi] = true;
    }
}

void kiir() {
    cout << "Utak tombje:" << endl;
    for(int i = 1; i <= n; i++) {
        cout << ut[i] << ' ';
    }
    cout << endl;
    cout << "Apak tombje:" << endl;
    for(int i = 1; i <= n; i++) {
        cout << apa[i] << ' ';
    }
    cout << endl;
}

void reset() {
    for(int i = 1; i <= n; i++) {
        ut[i] = 0;
        latott[i] = false;
        apa[i] = 0;
    }
}

int sum() {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += ut[i];
    }
    return sum;
}

int mini() {
    struct {
        int pont = -1;
        int ertek = INF * n;
    } mini;
    for(int i = 1; i <= n; i++) {
        if(megoldasok[i] < mini.ertek) {
            mini.ertek = megoldasok[i];
            mini.pont = i;
        }
    }
    return mini.pont;
}

int main()
{
    beolvas();
    for(int i = 1; i <= n; i++) {
        reset();
        beallit(i);
        dijkstra();
        // kiir();

        megoldasok[i] = sum();
    }
    cout << mini() << endl;

    return 0;
}
