#include <iostream>
using namespace std;

char matrix[10][10];
char szo[13];
int n;
bool keres(int i, int j, int ind, int irany) {
    if(i > 0) {
        if(irany != 1 && matrix[i-1][j] == szo[ind+1]) {
            keres(i-1, j, ind+1, 3);
        }
    }
    if(j > 0) {
        if(irany != 2 && matrix[i][j-1] == szo[ind+1]) {
            keres(i, j-1, ind+1, 4);
        }
    }
    if(i < n - 1) {
        if(irany != 3 && matrix[i+1][j] == szo[ind+1]) {
            keres(i+1, j, ind+1, 1);
        }
    }
}