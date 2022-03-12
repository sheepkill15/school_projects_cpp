//
// Created by simon on 2021. jan. 17..
//

#include <iostream>
#include <fstream>
#define cin fin
using namespace std;

ifstream fin("adat.be"); // NOLINT(cert-err58-cpp,cppcoreguidelines-interfaces-global-init)

int n;
int nodes[10001];
int costs[10001];

int new_costs[10001];

int main() {

    cin >> n;
    nodes[1] = -1;

    for(int i = 2; i <= n; i++) {
        new_costs[i] = INT16_MAX;
    }

    for(int i = 2; i <= n; i++) {
        cin >> nodes[i];
    }
    for(int i = 2; i <= n; i++) {
        cin >> costs[i];
    }



    for(int i = 2; i <= n; i++) {
        new_costs[i] = costs[nodes[i]] + costs[i];
        //new_costs[nodes[i]] = min()
    }

    struct {
        int ertek;
        int index;
    } maxi{INT16_MIN, -1};

    for(int i = 2; i <= n; i++) {
        if(new_costs[i] > maxi.ertek) {
            maxi.ertek = new_costs[i];
            maxi.index = i;
        }
    }
    int curr = maxi.index;
    while (curr > 1) {
        costs[curr] /= 2;
        curr = nodes[curr];
    }

    curr = maxi.index;
    while(curr > 1) {
        new_costs[curr] = costs[nodes[curr]] + costs[curr];
        curr = nodes[curr];
    }
    int sum = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            //if(j == i) continue;
            bool resze = false;
            int new_curr = i;
            while(new_curr > 1) {
                if(new_curr == j) {
                    resze = true;
                    break;
                }
                new_curr = nodes[new_curr];
            }
            if(!resze) {
                new_curr = j;
                while(new_curr > 1) {
                    if(new_curr == i) {
                        resze = true;
                        break;
                    }
                    new_curr = nodes[new_curr];
                }
            }
            if(resze) {
                sum += abs(new_costs[j] - new_costs[i]);
            }
            else
                sum += new_costs[i] + new_costs[j];
        }
    }

    cout << sum << endl;


    return 0;
}