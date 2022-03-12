#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("adat.in");

int n, m;
int szomszedsagi_matrix[100][100];
int latott[101];
int varakozasi_sor[101];
int sor_eleje, sor_vege;
int db = 0;

void beolvas() {
	fin >> n >> m; // n - pontok szama, m - elek szama
	for(int i = 1; i <= m; i++) {
		int elso, masodik;
		fin >> elso >> masodik;
		szomszedsagi_matrix[elso][masodik] = 1;
		szomszedsagi_matrix[masodik][elso] = 1;
	}
}

void bejaras() {
	while(sor_eleje < sor_vege) {
		int jelenlegi = varakozasi_sor[sor_eleje++];
		latott[jelenlegi] = db;
		cout << jelenlegi << ' ';

		for(int i = 1; i <= n; i++) {
			if(szomszedsagi_matrix[jelenlegi][i] == 1) {
				if(latott[i] == 0) {
					varakozasi_sor[sor_vege++] = i;
					latott[i] = db;
				}
			}
		}
	}
}

int main()
{
	beolvas();
	for(int i = 1; i <= n; i++) {
		if(latott[i] == 0) {
			db++;
			sor_vege = 0;
			sor_eleje = 0;
			varakozasi_sor[sor_vege++] = i;
			bejaras();
		}
	}
	cout << endl;
	for(int i = 1; i <= n; i++) {
		cout << latott[i] << ' ';
	}
	cout << endl << db << endl;
	return 0;
}
