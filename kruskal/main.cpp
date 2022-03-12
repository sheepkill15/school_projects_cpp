#include <iostream>
#include <algorithm>
using namespace std;

struct El {
	int elso;
	int masodik;
	int koltseg;
};

int n, m;
int latott[100];
El ellista[100];

El fa[100];
int fa_vege;

bool compare(const El& a, const El& b) {
	return a.koltseg < b.koltseg;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> ellista[i].elso >> ellista[i].masodik >> ellista[i].koltseg;
	}
	for(int i = 1; i <= n; i++) {
		latott[i] = i;
	}
	sort(ellista, ellista + m, compare);

	int eddig_el = 0;
	for(int i = 0; i < m; i++) {
		if(eddig_el == n) break;

		if(latott[ellista[i].elso] != latott[ellista[i].masodik]) {
			int kisebb = std::min(ellista[i].elso, ellista[i].masodik);
			int nagyobb = kisebb == ellista[i].elso ? ellista[i].masodik : ellista[i].elso;
			fa[fa_vege++] = ellista[i];
			eddig_el ++;
			int latott_nagyobb = latott[nagyobb];
			for(int j = 1; j <= n; j++) {
				if(latott[j] == latott_nagyobb) {
					latott[j] = latott[kisebb];
				}
			}
		}
	}
	
	cout << endl;
	int sum = 0;
	for(int i = 0; i < eddig_el; i++) {
		cout << fa[i].elso << ' ' << fa[i].masodik << endl;
		sum += fa[i].koltseg;
	}

	cout << sum << endl;
	
	return 0;
}
