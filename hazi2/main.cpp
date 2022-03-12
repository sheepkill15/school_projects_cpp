#include <iostream>
#include <algorithm>
using namespace std;

struct El {
	int elso;
	int masodik = 0;
};

struct Pont {
	int fokszam;
	int szam;

	bool assigned[100];
};

bool compare(Pont a, Pont b) {
	return a.fokszam > b.fokszam;
}

int main()
{
	int n;
	El el_tomb[100];
	Pont szamsorozat[100];
	int sor_vege = 0;

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> szamsorozat[i].fokszam;
		szamsorozat[i].szam = i;
	}

	sort(szamsorozat + 1, szamsorozat + n + 1, compare);

	for(int y = 1; y <= n; y++) {
		int i = szamsorozat[y].szam;
		int szam = szamsorozat[y].fokszam;
		for(int x = 0; x < szam; x++) {
			bool plusz = true;
			for(int j = 0; j < sor_vege; j++) {
				if(szamsorozat[y].assigned[el_tomb[j].elso]) continue;
				if(el_tomb[j].elso != i && el_tomb[j].masodik == 0) {
					el_tomb[j].masodik = i;
					plusz = false;
					szamsorozat[y].assigned[el_tomb[j].elso] = true;
					break;
				}
			}
			if(plusz) {
				el_tomb[sor_vege++].elso = i;
			}
		}
	}
	for(int i = 0; i < sor_vege; i++) {
		cout << '[' << el_tomb[i].elso << ',' << el_tomb[i].masodik << ']' << endl;
	}
	
	return 0;
}
