#include <iostream>
#include <cstring>
// #include <fstream>

using namespace std;

// ifstream fin("input");
// #define cin fin

int tomb[100000];
bool latott[100001];
int n;

int keres(int x, int index) {
    for(int i = index - 1; i >= 0; i--) {
        if(tomb[i] == x) return i;
    }
    return -1;
}

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tomb[i];
    }

    int kezdet = 0, veg = 0;

    int max = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if (latott[tomb[i]])
        {
            max = std::max(max, veg - kezdet + 1);
            int ujkezdet = keres(tomb[i], i) + 1;
            for(int x = kezdet; x <= ujkezdet; x++) {
                latott[tomb[x]] = false;
            }
            kezdet = ujkezdet;
        }
        veg = i;
        latott[tomb[i]] = true;
    }
    max = std::max(max, veg - kezdet + 1);

    cout << max << endl;
}