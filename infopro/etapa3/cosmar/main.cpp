//
// Created by simon on 2021. jan. 17..
//

#include <iostream>
#include <set>
using namespace std;

int main() {

    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        set<size_t> A;
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            A.insert(temp);
        }

        size_t B[200000];
        for(int j = 0; j < n; j++) {
            cin >> B[j];
        }
        for (int k = 0; k < 18; k++) {
            size_t maxi = (1ULL << k);
            for (size_t r = 0; r < maxi; r++) {
                bool ok = true;
                for(int j = 0; j < n; j++) {
                    if(B[j] % maxi == r) {
                        B[j] ^= maxi;
                    }
                    if(A.find(B[j]) == A.end()) {
                        ok = false;
                    }
                }
                if(ok) {
                    cout << "DA";
                    goto skip;
                }
            }
        }
        cout << "NU";

skip:
    if(i != T - 1) cout << endl;
    }

    return 0;
}
