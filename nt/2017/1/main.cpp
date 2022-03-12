#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// ifstream fin("input");
// #define cin fin

struct Pont {
    int szam;
    Pont* szulo;
    
    Pont* gyerekek[100001];
    
    int gyerek_szam = 0;
};

Pont *fej;

int apa_tomb[100001];

Pont* keres_szulo(int szulo, Pont* asd) {
    if(asd->szam == szulo) {
        return asd;
    }
    for(int i = 0; i < asd->gyerek_szam; i++) {
        Pont* talalt = keres_szulo(szulo, asd->gyerekek[i]);
        if(talalt != nullptr) return talalt;
    }
    return nullptr;
}

int levelek[100001];
int level_szam = 0;

Pont* szulok[100001];
int szulo_szam = 0;

Pont* level_pontok[100001];
int level_pont_szam = 0;

void bejar(Pont*& fej) {
    if(fej->szam == -1) return;
    for(int i = 0; i < fej->gyerek_szam; i++) {
        if(fej->gyerekek[i]->szam != -1) {
            bejar(fej->gyerekek[i]);
        }
    }
    if(fej->gyerek_szam == 0) {
        levelek[level_szam++] = fej->szam;
        szulok[szulo_szam++] = fej->szulo;
        level_pontok[level_pont_szam++] = fej;
        return;
    }
    for(int i = 0; i < fej->gyerek_szam; i++) {
        if(fej->gyerekek[i]->szam != -1) return;
    }

    levelek[level_szam++] = fej->szam;
    if(fej->szulo != nullptr) {
        szulok[szulo_szam++] = fej->szulo;
    }
    level_pontok[level_pont_szam++] = fej;
}

void kiir(Pont* fej) {
    cout << fej->szam << endl;
    for(int i = 0; i < fej->gyerek_szam; i++) {
        if(fej->gyerekek[i]->szam != -1) {
            kiir(fej->gyerekek[i]);
        }
    }
}

void ciklus() {
    bejar(fej);
    for(int i = 0; i < szulo_szam; i++) {
        Pont* szulo = szulok[i];
        szulo->szam = -1;
    }
    szulo_szam = 0;
    for(int i = 0; i < level_pont_szam; i++) {
        Pont* szulo = level_pontok[i];
        szulo->szam = -1;
    }
    level_pont_szam = 0;

}

int main()
{
    int n;

    cin >> n;

    fej = new Pont;
    fej->szam = 1;
    fej->szulo = nullptr;

    for(int i = 2; i <= n; i++) {
        int szulo;
        cin >> szulo;
        apa_tomb[i] = szulo;
        Pont* szulo_pont = keres_szulo(szulo, fej);
        szulo_pont->gyerekek[szulo_pont->gyerek_szam++] = new Pont { i, szulo_pont };
    }

    while(fej->szam != -1) {
        ciklus();
    }

    sort(levelek, levelek + level_szam);
    cout << level_szam << endl;
    for(int i = 0; i < level_szam; i++) {
        cout << levelek[i] << ' ';
    }
    cout << endl;

    return 0;
}