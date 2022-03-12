#include <iostream>
#include <fstream>
//#define cin fin
//#define cout fout
using namespace std;

ifstream fin("cladire.in");
ofstream fout("cladire.out");

int matrix[1001][1001];
int main()
{

	int n, m;
	cin >> n >> m;

	matrix[0][1] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
		}
	}

	cout << matrix[n][m] % 9901 << endl;
	
	return 0;
}
