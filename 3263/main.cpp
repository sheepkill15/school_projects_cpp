#include <fstream>
#include <algorithm>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("summax_xi.in");
ofstream fout("summax_xi.out");

bool compare(int a, int b) {
	return a > b;
}

int main()
{
	int n;
	int matrix[101][101];

	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		sort(matrix[i], matrix[i] + n, compare);
	}

	int ossz = 0;
	for(int i = 0; i < n; i++) {
		ossz += matrix[i][0];
	}

	cout << ossz << endl;
	
	return 0;
}
