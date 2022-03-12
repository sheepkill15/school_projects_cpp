#include <iostream>

using namespace std;

struct Ut {
    int mennyiseg;
    int kovetkezo;
};

Ut utak[100001];

int kapacitas;
int n;


int main() {

    cin >> n;
    cin >> kapacitas;

    for(int i = 0; i < n-1; i++) {
        cin >> utak[i].mennyiseg;
        cin >> utak[i].kovetkezo;
    }

    int deficitek[100001];

    for(int i = 0; i < n-1; i++) {
        deficitek[i] = utak[i].mennyiseg - utak[i].kovetkezo;
    }

    int i = 1;

    int plussz = utak[0].kovetkezo;
    int utolso = 0;

    int megoldas[100001];
    while(i < n-1) {
        if(deficitek[i] > deficitek[utolso]) {
            megoldas[utolso] =  plussz;
            utolso = i;
            plussz = utak[i].kovetkezo;
        }
        if(deficitek[i] < deficitek[utolso]) {
            plussz -= deficitek[i];
            megoldas[i] = utak[i].mennyiseg;
        }
        if(plussz > utak[utolso].mennyiseg) {
            cout << i+1 << endl;
            return 0;
        }

        i++;
    }
    megoldas[utolso] = plussz;
    for(int j = 0; j < n - 1; j++) {
        cout << megoldas[j] << ' ';
    }

    return 0;
}
