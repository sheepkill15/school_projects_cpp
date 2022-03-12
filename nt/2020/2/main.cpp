#include <iostream>
using namespace std;

int tomb[500000];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> tomb[i];
    }

    struct {
        int kezd;
        int veg;
    } maxi{0, -1};

    for(int i = 0; i < n; i++) {

        for(int j = n - 1; j > i; j--) {
            if(tomb[i] > tomb[j]) {
                if(j - i > maxi.veg - maxi.kezd) {
                    maxi = {i, j};
                }
                break;
            }
        }
    }
    if(maxi.veg == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << maxi.kezd + 1 << ' '  << maxi.veg + 1 << endl;
    return 0;
}