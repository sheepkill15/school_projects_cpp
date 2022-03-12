#include <iostream>
using namespace std;

struct Elem {
	int fontos_adat;
	Elem* elotte;
	Elem* utana;
};

Elem* fej, *veg;

void letrehozas(int fontos_adat) {
	fej = new Elem;
	fej->fontos_adat = fontos_adat;
	fej->elotte = nullptr;
	fej->utana = nullptr;
	veg = fej;
}

void hozzaadas(int fontos_adat) {
	Elem* uj_bacsi = new Elem;
	uj_bacsi->fontos_adat = fontos_adat;

	veg->utana = uj_bacsi;
	uj_bacsi->elotte = veg;

	veg = uj_bacsi;
}

void beszuras_utana(Elem* melyik_bacsi, int fontos_adat) {
	Elem* uj_bacsi = new Elem;
	uj_bacsi->fontos_adat = fontos_adat;

	uj_bacsi->elotte = melyik_bacsi;
	uj_bacsi->utana = melyik_bacsi->utana;

	if(melyik_bacsi != veg) {
		melyik_bacsi->utana->elotte = uj_bacsi;
	} else {
		veg = uj_bacsi;
	}

	melyik_bacsi->utana = uj_bacsi;
}

void beszuras_ele(Elem* melyik_bacsi, int fontos_adat) {
	if(melyik_bacsi->elotte == nullptr) {
		Elem* uj_bacsi = new Elem;
		melyik_bacsi->elotte = uj_bacsi;

		uj_bacsi->fontos_adat = fontos_adat;
		uj_bacsi->utana = melyik_bacsi;
		uj_bacsi->elotte = nullptr;

		fej = uj_bacsi;
	}
	else {
		beszuras_utana(melyik_bacsi->elotte, fontos_adat);
	}
}

void torles(Elem* melyik_bacsi) {
	Elem* bacsi_elotti = melyik_bacsi->elotte;
	Elem* bacsi_utani = melyik_bacsi->utana;

	if(bacsi_elotti != nullptr) {
		bacsi_elotti->utana = bacsi_utani;
	} else {
		fej = bacsi_utani;
	}
	if(bacsi_utani != nullptr) {
		bacsi_utani->elotte = bacsi_elotti;
	} else {
		veg = bacsi_elotti;
	}

	delete melyik_bacsi;
}

void kiir() {
	Elem* fiu = fej;
	while(fiu != nullptr) {
		cout << fiu->fontos_adat << ' ';
		fiu = fiu->utana;
	}
}

Elem* keres(int fontos_adat) {
	Elem* fiu = fej;
	while(fiu != nullptr) {
		
		if(fiu->fontos_adat == fontos_adat) {
			return fiu;
		}

		fiu = fiu->utana;
	}
	return fiu;
}

int main()
{
	letrehozas(6);
	hozzaadas(10);
	hozzaadas(2);
	beszuras_utana(fej->utana, 25);
	beszuras_ele(fej, 69);
	torles(veg->elotte);
	kiir();

	Elem* bacsi_aki_kettest_jegyzett_meg = keres(2);
	cout << bacsi_aki_kettest_jegyzett_meg->fontos_adat << endl;
	
	return 0;
}
