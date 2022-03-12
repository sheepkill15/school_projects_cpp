#include <iostream>
#include <fstream>
#define cin fin
#define cout fout

using namespace std;

ifstream fin("plopi2.in");
ofstream fout("plopi2.out");

int main()
{
	int ossz = 0, db = 0;

	int n;
	cin >> n;

	int elso;
	cin >> elso;

	for(int i = 1; i < n; i++) {

		int temp;
		cin >> temp;

		if(elso < temp) {
			db ++;
			ossz += temp - elso;
		}
		else 
			elso = temp;
	}

	cout << db << ' ' << ossz;
	
	return 0;
}
