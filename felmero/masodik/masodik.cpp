#include <iostream>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("Auto.in");
ofstream fout("Auto.out");

struct autocska {
	int ido;
	int index;
};

int main()
{
	int n;
	int T;
	autocska autok[100];

	cin >> n >> T;
	for(int i = 0; i < n; i++) {
		cin >> autok[i].ido;
		autok[i].index = i + 1;
	}

	bool ok;
	do {
		ok = false;
		for(int i = 0; i < n-1; i++) {
			if(autok[i].ido > autok[i+1].ido) {
				autocska csere;
				csere = autok[i];
				autok[i] = autok[i+1];
				autok[i+1] = csere;
				ok = true;
			}
		}
	}while(ok);

	int sum = 0;

	int megoldasIndexek[100];
	int db = 0;

	for(int i = 0; i < n; i++) {
		if(autok[i].ido + sum <= T) {
			sum += autok[i].ido;
			megoldasIndexek[db++] = autok[i].index;
		}
		else break;
	}
	cout << db << endl;
	for(int i = 0; i < db; i++) {
		cout << megoldasIndexek[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
