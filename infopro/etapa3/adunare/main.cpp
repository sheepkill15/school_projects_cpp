//
// Created by simon on 2021. jan. 17..
//

#include <iostream>
using namespace std;

int db[3];
int elso[1001], masodik[1001], harmadik[1001];
int n, q;

bool ellenoriz(const int st[], int k) {
    for(int i = 0; i < k; i++) {
        if(st[i] >= st[k]) return false;
    }
    return true;
}

int main() {

    int egy, ketto, harom;
    cin >> n >> q >> egy >> ketto >> harom;

    while(egy) {
        int szj = egy % 10;
        egy /= 10;
        elso[db[0]++] = szj;
    }

    while(ketto) {
        int szj = ketto % 10;
        ketto /= 10;
        masodik[db[1]++] = szj;
    }

    while(harom) {
        int szj = harom % 10;
        harom /= 10;
        harmadik[db[2]++] = szj;
    }

    int dbd = 0;
    int st[100001];
    int k = 0;
    st[k] = -1;
    while(k >= 0) {
        bool jo, van;
        do {
            van = (st[k]++ < n - 1);
            if(van) {
                jo = ellenoriz(st, k);
            }
        } while(van && !jo);
        if(van) {
            if(k < n) {
                int sum1 = 0;
                int sum2 = 0;
                int sum3 = 0;
                int tizh = 1;
                for(int i = 0; i <= k; i++) {
                    sum1 += elso[st[i]] * tizh;
                    sum2 += masodik[st[i]] * tizh;
                    sum3 += harmadik[st[i]] * tizh;
                    tizh *= 10;
                }
                if(sum1 + sum2 == sum3)
                {
                    dbd++;

                }
                k++;
                st[k] = -1;

            }
        }
        else k--;
    }

    cout << dbd + 1 << endl;

    for(int x = 0; x < q; x++){
        int sor, oszlop, szam;
        cin >> sor >> oszlop >> szam;
        if(sor == 1) {
            elso[n - oszlop] = szam;
        }
        else if(sor == 2) {
            masodik[n  - oszlop] = szam;
        }
        else if(sor == 3) {
            harmadik[n - oszlop] = szam;
        }
        dbd = 0;
        k = 0;
        st[k] = -1;
        while(k >= 0) {
            bool jo, van;
            do {
                van = (st[k]++ < n - 1);
                if(van) {
                    jo = ellenoriz(st, k);
                }
            } while(van && !jo);
            if(van) {
                if(k < n) {
                    int sum1 = 0;
                    int sum2 = 0;
                    int sum3 = 0;
                    int tizh = 1;
                    for(int i = 0; i <= k; i++) {
                        sum1 += elso[st[i]] * tizh;
                        sum2 += masodik[st[i]] * tizh;
                        sum3 += harmadik[st[i]] * tizh;
                        tizh *= 10;
                    }
                    if(sum1 + sum2 == sum3)
                    {
                        dbd++;

                    }
                    k++;
                    st[k] = -1;
                }
            }
            else k--;
        }
        cout << dbd + 1 << endl;
    }


    return 0;
}
