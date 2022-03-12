#include <iostream>
#include <fstream>
#define cin fin

using namespace std;

ifstream fin("adat.be");

void elso(int t)
{
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        int tomb[200000] = {0};

        for (int j = 0; j < n; j++)
        {
            string nap;
            cin >> nap;
            for (int x = 0; x < k; x++)
            {
                tomb[x] += nap[x] - '0';
            }
        }
        int mini = tomb[0];
        for (int x = 1; x < k; x++)
        {
            mini = std::min(mini, tomb[x]);
        }
        cout << std::min(k, mini) << endl;
    }
}

void masodik(int t) {
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        
        string napok[2000];
        for(int j = 0; j < n; j++) {
            cin >> napok[j];
        }

        bool elso[2000] = {0};
        int elsoDb = 0;
        int elsoNapok[2];
        for(int x = 0; x < n; x++) {
            for(int xx = 0; xx < k; xx++) {
                if(!elso[xx]) elsoDb++;
                elso[xx] = elso[xx] || (napok[x][xx] - '0') == 1;
                if(elsoDb == k) {
                    elsoNapok[0] = x;
                    elsoNapok[1] = xx;
                    goto next;
                }
            }
        }
        next:
        bool masodik[2000] = {0};
        int masodikDb = 0;
        int masodikNapok[2];
        for(int x = n - 1; x >= 0; x--) {
            for(int xx = k - 1; xx >= 0; xx--) {
                if(!masodik[xx]) masodikDb++;
                masodik[xx] = masodik[xx] || (napok[x][xx] - '0') == 1;
                if(masodikDb == k) {
                    masodikNapok[0] = x;
                    masodikNapok[1] = xx;
                    goto next2;
                }
            }    
        }
        next2:
        cout << elsoNapok[0] << ' ' << masodikNapok[0] << endl;
        cout << masodikNapok[0] - elsoNapok[0] + 1 << endl;
    }
}

int main()
{
    int p;
    cin >> p;
    int t;
    cin >> t;
    switch (p)
    {
    case 1:
        elso(t);
        break;
    case 2:
        masodik(t);
        break;
    }
    return 0;
}
