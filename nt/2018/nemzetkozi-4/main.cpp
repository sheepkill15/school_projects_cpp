#include <iostream>

using namespace std;

int teszt[4000][4000];

int main() {
    int n;
    cin >> n;
    int jelek[4000];
    for(int i = 0; i < n; i++) {
        cin >> jelek[i];
    }
    int maxi_hossz = -1;
    int maxi_ind = -1;
    int maxi_veg = -1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(jelek[i] == jelek[j]) {
                if(i > 0 && j > 0) {
                    teszt[i][j] = teszt[i-1][j-1];
                }
                teszt[i][j]++;
                if(teszt[i][j] > maxi_hossz) {
                    maxi_hossz = teszt[i][j];
                    maxi_ind = std::max(i, maxi_ind);
                }
            }
        }
    }
    while(maxi_hossz) {
        cout << jelek[maxi_ind - maxi_hossz + 1] << ' '; 
        maxi_hossz--;
    }
    cout << endl;
    
}