#include <iostream>

using namespace std;

const int INF = 1e4;

int n, m;
int matrix[100][100];
bool latott[100];
int ut[100];
int apa[100];

void beolvas() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int elso, masodik, harmadik;
        cin >> elso >> masodik >> harmadik;
        matrix[elso][masodik] = harmadik;
    }
}

void beallit() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || matrix[i][j]) {
                continue;
            }
            matrix[i][j] = INF;
        }
    }
    for(int i = 2; i <= n; i++) {
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

int main()
{
    beolvas();
    beallit();
    dijkstra();
    kiir();

    return 0;
}
