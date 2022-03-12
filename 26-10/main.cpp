#include <iostream>
#include <algorithm>
using namespace std;

struct adat {
	float suly;
	float ertek;
	float arany;
	unsigned int index;
};

bool compare(const adat& a, const adat& b) {
	return a.arany > b.arany;
}

int main()
{
	int n, gmax;
	adat tomb[100];
	
	cin >> n >> gmax;
	for(int i = 0; i < n; i++) {
		cin >> tomb[i].suly;
		tomb[i].index = i + 1;
	}
	for(int i = 0; i < n; i++) {
		cin >> tomb[i].ertek;
	}
	for(int i = 0; i < n; i++) {
		tomb[i].arany = tomb[i].ertek / tomb[i].suly;
	}

	sort(tomb, tomb + n, compare);

	int osszsuly = 0, osszertek = 0;
	for(int i = 0; i < n; i++) {
		if(osszsuly + tomb[i].suly <= gmax) {
			cout << tomb[i].index << ' ';
			osszertek += tomb[i].ertek;
			osszsuly += tomb[i].suly;
		}
		else {
			cout << tomb[i].index << ' ';
			float maradt = gmax - osszsuly;
			float vagottErtek =  tomb[i].ertek * (maradt / tomb[i].suly);
			osszertek += vagottErtek;
			break;
		}
	}
	cout << endl;
	cout << osszertek << endl;

	return 0;
}
