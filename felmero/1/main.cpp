#include <iostream>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;

ifstream fin("adat.be");
ofstream fout("adat.ki");

struct Vezetek {
	int elso;
	int masodik;
	int hossz;
};
int n, m;
Vezetek vezetekek[100];

void beolvas() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> vezetekek[i].elso >> vezetekek[i].masodik >> vezetekek[i].hossz;
	}
}

void swap(int i, int j) {
	Vezetek csere = vezetekek[i];
	vezetekek[i] = vezetekek[i+1];
	vezetekek[i+1] = csere;
}

void b_sort() {
	bool ok;
	do {
		ok = false;
		for(int i = 0; i < m - 1; i++) {
			if(vezetekek[i].hossz > vezetekek[i+1].hossz) {
				swap(i, i+1);
				ok = true;
			}
		}
	}while(ok);
}

bool check(int halmaz[], int k, int melyik) {
	for(int i = 0; i < k; i++) {
		if(halmaz[i] == melyik)
			return true;
	}
	return false;
}

int prim(Vezetek ujfa[]) {
	int sum = 0;
	int halmaz[100];
	int k = 0;

	halmaz[k++] = vezetekek[0].elso;
	halmaz[k++] = vezetekek[0].masodik;
	sum += vezetekek[0].hossz;
	int ujfa_hossz = 0;
	ujfa[ujfa_hossz++] = vezetekek[0];

	for(int i = 0; i < m; i++) {
		if(k == n) break;
		const bool tartalmaz_elsot = check(halmaz, k, vezetekek[i].elso);
		const bool tartalmaz_masodikat = check(halmaz, k, vezetekek[i].masodik);
		if(tartalmaz_elsot != tartalmaz_masodikat) {
			if(tartalmaz_elsot) {
				halmaz[k++] = vezetekek[i].masodik;
			}
			else halmaz[k++] = vezetekek[i].elso;
			sum += vezetekek[i].hossz;
			ujfa[ujfa_hossz++] = vezetekek[i];
		}
	}

	return sum;
}

int main()
{
	beolvas();
	b_sort();
	Vezetek ujfa[100];
	cout << "Osszhossz: " << prim(ujfa) << endl;
	cout << "Generalt fa: " << endl;

	for(int i = 0; i < n - 1; i++) {
		cout << ujfa[i].elso << ' ' << ujfa[i].masodik << endl;
	}

	return 0;
}
