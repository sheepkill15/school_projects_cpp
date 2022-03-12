#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("jegenye.in");
ofstream fout("jegenye.out");

int tomb[10000], reszh[10000];

int main()
{
	int n;
	fin >> n;

	for(int i = 1; i <= n; i++) {
		fin >> tomb[i];
	}
	int k = 1;
	reszh[1] = tomb[1];

	for(int i = 2; i <= n; i++) {
		if(tomb[i] > reszh[k]) {
			reszh[++k] = tomb[i];
		}
		else {
			int bal = 1, jobb = k;
			int pos = k + 1;
			while(bal <= jobb) {
				int kozep = (bal + jobb) / 2;
				if(reszh[kozep] > tomb[i]) {
					pos = kozep;
					jobb = kozep - 1;
				}
				else bal = kozep + 1;
			}
			reszh[pos] = tomb[i];
		}
	}
	// for(int i = 1; i <= k; i++) {
	// 	cout << reszh[i] << ' ';
	// }
	// cout << endl;

	fout << n - k << endl;

	return 0;
}
