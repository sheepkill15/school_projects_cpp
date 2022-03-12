#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("cerc3.in");
ofstream fout("cerc3.out");

struct cerc {
	short eleje;
	short vege;
};

bool compare(const cerc& a, const cerc& b) {
	return a.vege < b.vege;
}

int main()
{
	short n;
	cerc karikak[300];
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		short x, r;
		cin >> x >> r;
		karikak[i].eleje = x - r;
		karikak[i].vege = x + r;
	}

	sort(karikak, karikak + n, compare);

	int db = 1;
	int elozo = karikak[0].vege;
	for(int i = 1; i < n; i++) {
		if(elozo < karikak[i].eleje) {
			db++;
			elozo = karikak[i].vege;
		}
	}
	cout << db << endl;
	return 0;
}
