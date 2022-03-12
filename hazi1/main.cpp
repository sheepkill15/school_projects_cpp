#include <iostream>
using namespace std;

bool matrix[100][100];

int varakozasi_sor[100];
int sor_eleje, sor_vege;
bool latott[100];

int n, m;
bool osszefuggo() {
	for(int i = 1; i <= n; i++) {
		if(latott[i] == false) {
			return false;
		}
	}
	return true;
}
void bejaras() {

	while(sor_eleje < sor_vege) {
		int jelenlegi = varakozasi_sor[sor_eleje++];
		latott[jelenlegi] = true;

		for(int i = 1; i <= n; i++) {
			if(matrix[jelenlegi][i] == true) {
				if(latott[i] == false) {
					varakozasi_sor[sor_vege++] = i;
					latott[i] = true;
					matrix[i][jelenlegi] = false;
				}
				else {
					cout << "Ez nem fa!" << endl;
					return;
				}
			}
		}
	}
	if(osszefuggo())
		cout << "Ez egy fa!" << endl;
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int elso, masodik;
		cin >> elso >> masodik;

		matrix[elso][masodik] = 1;
		matrix[masodik][elso] = 1;
	}
	varakozasi_sor[sor_vege++] = 1;
	bejaras();
	
	return 0;
}
