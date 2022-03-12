#include <iostream>
#include <bitset>
using namespace std;

bitset<100000000> ertekek;

int main() {

    int p;
    int adam;
    int eva;

    cin >> p;
    cin >> adam;

    for(int i = 0; i < adam; i++) {
        int elso, masodik;
        cin >> elso >> masodik;

        for(int j = elso; j < masodik; j++) {
            ertekek.set(j, true);
        }
    }

    cin >> eva;

    for(int i = 0; i < eva; i++) {
        int elso, masodik;
        cin >> elso >> masodik;

        int kezdet = -1;
        int veg = -1;

        for(int j = elso; j < masodik; j++) {
            if(ertekek[j] == true) {
                if(kezdet < 0) {
                    kezdet = j;
                }
                veg = j;
            }
            else if(kezdet > 0) {
                cout << kezdet << ' ' << veg + 1 << endl;
                kezdet = -1;
                veg = -1;
            }
        }
        if(kezdet > 0 && veg > 0) {
            cout << kezdet << ' ' << veg + 1 << endl;
        }
    }

     return 0;
}
