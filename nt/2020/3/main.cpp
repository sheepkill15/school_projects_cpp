#include <iostream>
#include <set>

using namespace std;

long long tomb[200000];

int main()
{
    set<long long> halmaz;

    int n;
    int kulonbozo_db = 0;

    cin >> n;
    {
        set<long long> kulonbozo;
        for(int i = 0; i < n; i++) {
            cin >> tomb[i];
            if(kulonbozo.find(tomb[i]) == kulonbozo.end()) {
                kulonbozo.insert(tomb[i]);
            }
        }
        kulonbozo_db = kulonbozo.size();
    }
    for(int i = n - 1; i >= 0; i--) {
        if(halmaz.find(tomb[i]) == halmaz.end()) {
            halmaz.insert(tomb[i]);
        }
        if(halmaz.size() == kulonbozo_db) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}