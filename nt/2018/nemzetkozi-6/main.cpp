#include <iostream>

using namespace std;

int t[5000];
int n;

int penz;

int megoldas[3];
int lastSum;

bool ossz(int kezdIndex) {
    int k = 0;
    int sum = t[kezdIndex];
    megoldas[0] = kezdIndex;
    for(int i = kezdIndex - 1; i >= 0 && k < 2; i--) {
        if(sum + t[i] <= penz) {
            sum += t[i];
            k++;
            megoldas[k] = i;
        } else {
            sum -= t[megoldas[k]];
            k--;
            i = megoldas[k];
        }
    }
    lastSum = sum;
    return k == 2;
}

int main() {

    cin >> n >> penz;

    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int maxi = -1;
    int vegleges[3];
    for(int i = n - 1; i >= 0; i--) {
        if(ossz(i)) {
            if(maxi < lastSum) {
                maxi = lastSum;
                vegleges[0] = megoldas[0];
                vegleges[1] = megoldas[1];
                vegleges[2] = megoldas[2];
            }
        }
    }

    cout << vegleges[0] + 1 << ' ' << vegleges[1] + 1 << ' ' << vegleges[2] + 1 << endl;

    return 0;
}
