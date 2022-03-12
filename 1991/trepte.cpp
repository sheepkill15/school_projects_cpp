#include <iostream>

using namespace std;

int n, k;

const int meret = 1e5 + 1;
int tomb[meret];

int lep(int i) {
	if(i <= 0) {
		return 0;
	}
	if(i == 1) {
		return 1;
	}

	if(tomb[i] != 0) return tomb[i];

	int ossz = 0;
	for(int j = 1; j <= k; j++) {
		ossz += lep(i - j) % 9001;
	}
	tomb[i] = ossz;
	return ossz;
}

int main()
{
	cin >> n >> k;
	
	cout << lep(n) << endl;

	return 0;
}
