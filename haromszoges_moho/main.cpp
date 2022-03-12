#include <iostream>
using namespace std;

int main()
{
	int n, matrix[100][100];

	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int ossz = matrix[0][0];
	int j = 0;
	for(int i = 1; i < n; i++) {
		if(matrix[i][j] > matrix[i][j+1]) {
			ossz += matrix[i][j];
		}
		else {
			ossz += matrix[i][j+1];
			j++;
		}
	}

	cout << ossz << endl;

	return 0;
}
