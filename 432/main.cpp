#include <iostream>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("taxe.in");
ofstream fout("taxe.out");

int sivatag[201][201];
int uj[201][201];

int main()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i <= n+1; i++) {
		for(int j = 0; j <= m+1; j++) {
			uj[i][j] = 101;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> sivatag[i][j];
			uj[i][j] = 0;
		}
	}

	for(int i = 1; i <= n; i++) {
		uj[i][m] = sivatag[i][m];
	}

	for(int j = m - 1; j >= 1; j--) {
		for(int i = 1; i <= n; i++) {
			uj[i][j] = min(min(uj[i-1][j+1], uj[i][j+1]), uj[i+1][j+1]) + sivatag[i][j];
		}
	}
	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= m; j++) {
	// 		cout << uj[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }
	int mini = 101;

	for(int i = 1; i <= n; i++) {
		if (uj[i][1] < mini) {
			mini = uj[i][1];
		}
	}
	cout << mini << endl;
	
	return 0;
}
