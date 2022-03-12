#include <iostream>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ifstream fin ("gomba.in");
ofstream fout("gomba.out");

int erdo[201][201] = {0};

int max(int a, int b) {
	return (a < b) ? b : a;
}

int main()
{
	int n, m;

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> erdo[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int plusz = max(max(erdo[i-1][j-1], erdo[i-1][j]), erdo[i-1][j+1]);
			erdo[i][j] += plusz;
		}
	}

	// for(int i = 0; i <= n; i++) {
	// 	for(int j = 0; j <= m; j++) {
	// 		cout << erdo[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	int maxi = 0;
	for(int j = 1; j <= m; j++) {
		if(erdo[n][j] > maxi) {
			maxi = erdo[n][j];
		}
	}
	
	cout << maxi << endl;

	return 0;
}
