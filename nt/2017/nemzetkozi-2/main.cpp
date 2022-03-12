#include <iostream>
#include <cstring>

using namespace std;

char matrix[100][100];
char szo[13];
int n;


int bejar(int i, int j, int c) {
    if(matrix[i][j] == szo[c]) {

    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    cin >> szo;

    return 0;
}
