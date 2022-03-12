#include <iostream>
#include <iomanip>
#include <fstream>
#define cin fin
using namespace std;

ifstream fin("adat.be");

int matrix[100][100];
int pontok;

bool latott[100];
int utak[100];
int apak[100];

void beallit() 
{
    for(int i = 1; i <= pontok; i++) {
        for(int j = 1; j <= pontok; j++) {
            matrix[i][j] = 69;
        }
    }

    for(int i = 2; i <= pontok; i++) {
        utak[i] = 69;
    }
}

void beolvas() 
{
    int elek;
    cin >> pontok >> elek;

    beallit();

    for(int i = 0; i < elek; i++) 
    {
        int elso, masodik, hossz;
        cin >> elso >> masodik >> hossz;
        matrix[elso][masodik] = hossz;
    }
}

int jelenlegi_pont_meghatarozas() 
{
    int mini_ertek = 70;
    int mini_pont = -1;
    for(int i = 1; i <= pontok; i++) 
    {
        if(mini_ertek > utak[i] && latott[i] == 0) {
            mini_ertek = utak[i];
            mini_pont = i;
        }
    }
    return mini_pont;
}

bool check() 
{
    for(int i = 1; i <= pontok; i++) {
        if(latott[i] == 0) return true;
    }
    return false;
}

void dijkstra()
{
    while(check()) 
    {
        int jelenlegi = jelenlegi_pont_meghatarozas();
        latott[jelenlegi] = true;

        for(int i = 1; i <= pontok; i++) 
        {
            if(i != jelenlegi && 
                latott[i] == 0 && 
                utak[i] > utak[jelenlegi] + matrix[jelenlegi][i]) 
            {
                utak[i] = utak[jelenlegi] + matrix[jelenlegi][i];
                apak[i] = jelenlegi;
            }
        }
    }
}

void ut_visszafejtes(int pont) 
{
    if(apak[pont] != 0) 
    {
        ut_visszafejtes(apak[pont]);
    }
    cout << pont << ' ';
}

int main()
{
    beolvas();

    for(int i = 1; i <= pontok; i++) {
        for(int j = 1; j <= pontok; j++) {
            cout << setw(3) <<  matrix[i][j] << ' ';
        }
        cout << endl;
    }

    dijkstra();

    for(int i = 1; i <= pontok; i++) {
        cout << utak[i] << ' ';
    }
    cout << endl;

    ut_visszafejtes(69);
    cout << endl;

    return 0;
}