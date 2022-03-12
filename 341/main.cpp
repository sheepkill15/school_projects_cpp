#include <iostream>
#include <fstream>
#include <algorithm>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("bomboane.in");
ofstream fout("bomboane.out");

struct doboz {
	unsigned short cukorka;
	unsigned short index;
};

struct megoldas {
	unsigned short honnan;
	unsigned short hova;
	unsigned short mennyit;
};

bool done(doboz dobozok[], short n) {
	for(unsigned short i = 0; i < n - 1; i++) {
		if(dobozok[i].cukorka != dobozok[i+1].cukorka) return false;
	}
	return true;
}

int main()
{
	int n;
	doboz dobozok[1000];
	megoldas megoldasok[1000];
	int ossz = 0;
	cin >> n;
	for(unsigned short i = 0; i < n; i++) {
		cin >> dobozok[i].cukorka;
		dobozok[i].index = i + 1;
		ossz += dobozok[i].cukorka;
	}
	if(ossz % n != 0) {
		cout << -1;
		return 0;
	}

	int atlag = ossz / n;

	int k = 0;

	while(!done(dobozok, n)) {
		doboz mini = dobozok[0];
		doboz maxi = dobozok[0];

		int mI = 0;
		int mmI = 0;

		for(unsigned short i = 1; i < n; i++) {
			if(dobozok[i].cukorka > maxi.cukorka) {
				maxi = dobozok[i];
				mI = i;
			}
			if(dobozok[i].cukorka < mini.cukorka) {
				mini = dobozok[i];
				mmI = i;
			}
		}
		short mennyit = atlag - mini.cukorka;
		
		dobozok[mI].cukorka -= mennyit;
		dobozok[mmI].cukorka += mennyit;

		megoldasok[k].honnan = maxi.index;
		megoldasok[k].hova = mini.index;
		megoldasok[k].mennyit = mennyit;
		k++;
	}

	cout << k << endl;
	for(int i = 0; i < k; i++) {
		cout << megoldasok[i].honnan << ' ';
		cout << megoldasok[i].hova << ' ';
		cout << megoldasok[i].mennyit << endl;
	}
	
	return 0;
}
