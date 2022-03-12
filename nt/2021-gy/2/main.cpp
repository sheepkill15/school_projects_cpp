#include <iostream>
// #include <fstream>

using namespace std;

// ifstream fin("input");
// #define cin fin
int reszveny1[100000];
int reszveny2[100000];
int reszveny_db1, reszveny_db2;
int osszeg;


int bin_par(int szam) {
    int local_closest = -1;
    int i = 0;
    int j = reszveny_db2 - 1;
    int keresett = osszeg - szam;
    while(i <= j) {
        int m = (i + j) / 2;
        if(reszveny2[m] > keresett) {
            j = m - 1;
        }
        else if(reszveny2[m] < keresett) {
            i = m + 1;
        }
        else return reszveny2[m];
        if(keresett - reszveny2[m] >= 0) {
            if(reszveny2[m] > local_closest) {
                local_closest = reszveny2[m];
            }
        }
    }
    return local_closest;
}

int main()
{

    cin >> reszveny_db1 >> reszveny_db2 >> osszeg;


    for (int i = 0; i < reszveny_db1; i++)
    {
        cin >> reszveny1[i];
    }
    for (int i = 0; i < reszveny_db2; i++)
    {
        cin >> reszveny2[i];
    }

    int closest = -1;
    for(int i = 0; i < reszveny_db1; i++) {
        int par = bin_par(reszveny1[i]);
        if(par != -1 && reszveny1[i] + par > closest && reszveny1[i] + par <= osszeg) {
            closest = reszveny1[i] + par;
        }
    }

    if(closest == -1) {
        cout << osszeg << endl;
        return 0;
    }

    cout << osszeg - closest << endl;

    return 0;
}