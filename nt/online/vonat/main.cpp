#include <iostream>
#include <algorithm>

using namespace std;
int main() {

    int n;
    int stack[100001] = {0};
    int rsp = 0;
    int elozo = -1;

    int megoldas[100001] = {0};
    int k = 0;


    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp > elozo) {
            stack[rsp++] = temp;
        }
        else {
                megoldas[k++] = temp;
        }
        elozo = temp;
    }
    for(int i = 0; i < rsp; i++) {
        if(megoldas[k-1] <= stack[i])
            megoldas[k++] = stack[i];
    }
    cout << k << endl;

       return 0;
}
