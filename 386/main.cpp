#include <iostream>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("sumtri1.in");
ofstream fout("sumtri1.out");

int eredeti[100][100];
int uj[100][100];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> eredeti[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		uj[n-1][i] = eredeti[n-1][i];
	}

	for(int i = n - 2; i >= 0; i--) {
		for(int j = 0; j <= i; j++) {
			uj[i][j] = min(uj[i+1][j], uj[i+1][j+1]) + eredeti[i][j];
		}
	}
	cout << uj[0][0] << endl;

	int j = 0;
	for(int i = 0; i < n; i++) {
		cout << eredeti[i][j] << ' ';
		if(uj[i+1][j] > uj[i+1][j+1]) j++;
	}
	cout << endl;
	
	return 0;
}
