#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input");

#define cin fin

int asztal[1000001];
int k;
void beallit(int p, int d) {
    for(int i = p; i < p + k; i++) {
        asztal[i] = max(asztal[i], d);
    }
}

int main()
{
    int szel, n;
    cin >> szel >> n >> k;

    for(int i = 0; i < szel; i++) {
        asztal[i] = INT32_MIN;
    }

    for(int i = 0; i < n; i++) {
        int p, d;
        cin >> p >> d;
        beallit(p, d);
    }
    int min = asztal[0];
    for(int i = 1; i < szel; i++) {
        if(asztal[i] < min) {
            min = asztal[i];
        }
    }
    cout << min << endl;

    return 0;
}
