#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("szamgep.be");
ofstream fout("szamgep.ki");

int halozat[1001][1001];
int kapcsolatszam[1001];
int latott[1001];
int n, m;
int terulet;

int varakozasi_sor[1001];
int sor_eleje = 0;
int sor_vege = 1;

void kiir() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << halozat[i][j] << ' ';
		}
		cout << endl;
	}
}

void bejaras() {
	while(sor_eleje < sor_vege) {
		int jelenlegi = varakozasi_sor[sor_eleje++];
		for(int i = 1; i <= n; i++) {
			if(halozat[jelenlegi][i] == 1) {
				if(latott[i] == 0) {
					latott[i] = terulet;
					varakozasi_sor[sor_vege++] = i;
				}
			}
		}
	}
}

int vanemeg() {
	for(int i = 1; i <= n; i++) {
		if(latott[i] == 0) return i;
	}
	return -1;
}

int main()
{
	fin >> n >> m;
	for(int i = 0; i < m; i++) {
		int elso, masodik;
		fin >> elso >> masodik;

		halozat[elso][masodik] = 1;
		halozat[masodik][elso] = 1;

		kapcsolatszam[elso]++;
		kapcsolatszam[masodik]++;
	}

	kiir();

	bool ok = true;
	int db_c = 0;
	for(int i = 1; i <= n; i++) {
		if(kapcsolatszam[i] != 2) {
			ok = false;
		}
		if(kapcsolatszam[i] == 1) {
				db_c ++;
		}
	}
	if(ok) 
		cout << "igen" << endl;
	else cout << "nem" << endl;

	for(int i = 1; i <= n; i++) {
		if(kapcsolatszam[i] == 1) {
				db_c ++;
		}
	}
	cout << db_c << endl;
	int vanmeg = 0;
	while(vanmeg != -1) {
		
		vanmeg = vanemeg();
		if(latott[vanmeg] == 0) {
			terulet++;
			sor_eleje = 0;
			sor_vege = 1;
			varakozasi_sor[sor_eleje] = vanmeg;
			bejaras();
		}
	}
	ok = true;
	for(int i = 1; i <= n; i++) {
		if(latott[i] != 1) {
			ok = false;
			break;
		}
	}
	if(ok) {
		cout << "igen" << endl;
	}
	else {
		cout << "nem" << endl;

		for(int i = 1; i <= n; i++) {
			cout << latott[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
