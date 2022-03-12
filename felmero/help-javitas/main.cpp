#include <iostream>
using namespace std;

int n, m;
int illeszkedesi[100][100];
int csucs[100][100];


void beolvas() {

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int elso, masodik;
		cin >> elso >> masodik;
		illeszkedesi[elso][i] = 1;
		illeszkedesi[masodik][i] = 1;
	}

	for(int j = 1; j <= m; j++) {
		int elso = 0, masodik = 0;
		for(int i = 1; i <= n; i++) {
			if(illeszkedesi[i][j] == 1) {
				if(elso == 0) {
					elso = i;
				}
				else if(masodik == 0) {
					masodik = i;
				}
			}
		}
		csucs[elso][masodik] = 1;
		csucs[masodik][elso] = 1;
	}
}

int varakozasi_sor[100];
int latott[100];
int sor_eleje;
int sor_vege;
int db = 1;

void bejaras(int kezdopont) {
	varakozasi_sor[sor_vege++] = kezdopont;
	latott[kezdopont] = db;

	while(sor_eleje < sor_vege) {
		int jelenlegi = varakozasi_sor[sor_eleje++];
		for(int i = 1; i <= n; i++) {
			if(csucs[jelenlegi][i] == 1) {
				if(latott[i] == 0) {
					latott[i] = db;
					varakozasi_sor[sor_vege++] = i;
				}
			}
		}
	}
}

int main()
{
	
	beolvas();
	bejaras(1);

	bool ok = true;
	for(int i = 1; i <= n; i++) {
		if(latott[i] == 0) {
			ok = false;
			break;
		}
	}
	if(ok) {
		cout << "Vannak" << endl;
	}
	else cout << "nincsenek" << endl;
	
	return 0;
}
