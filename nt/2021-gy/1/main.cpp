#include <iostream>

using namespace std;

int tomb[100000];

int main() {
    int n, k;
    int s = 1;
    int min = INT32_MAX;
    int sum = 0;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> tomb[i];
    }

    for(int i = 0; i < k; i++) {
        sum += tomb[i];
    }
    min = sum;

    for(int i = k; i < n; i++) {
        sum += tomb[i];
        sum -= tomb[i - k];

        if(sum < min) {
            min = sum;
            s = 0;
        }
        if(sum == min) {
            s ++;
        }
    }
    cout << min << endl << s << endl;
}