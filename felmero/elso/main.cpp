#include <iostream>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("Penz.in");
ofstream fout("Penz.out");

int main()
{
	int n;
	int s;
	int bankjegyek[100];

	cin >> n >> s;
	for(int i = 0; i < n; i++) {
		cin >> bankjegyek[i];
	}

	bool ok;

	do {
		ok = false;
		for(int i = 0; i < n-1; i++) {
			if(bankjegyek[i] < bankjegyek[i+1]) {
				int csere;
				csere = bankjegyek[i];
				bankjegyek[i] = bankjegyek[i+1];
				bankjegyek[i+1] = csere;
				ok = true;
			}
		}
	}while (ok);

	for(int i = 0; i < n; i++) {
		int mennyi = s / bankjegyek[i];
		if(mennyi > 0) {
			s -= mennyi * bankjegyek[i];
			cout << mennyi << " x " << bankjegyek[i] << endl;
		}
	}
	
	return 0;
}
