#include <iostream>
#include <fstream>

#define cin fin
#define cout fout

using namespace std;

ifstream fin("file.be");
ofstream fout("file.ki");

int n, m;

int szomszedsagi_matrix[100][100];
int illeszkedesi_matrix[100][100];
int szomszedsagi_lista[100][100];

void szomszedM() {
	
	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		int elso, masodik;
		cin >> elso >> masodik;
		szomszedsagi_matrix[elso][masodik] = 1;
		szomszedsagi_matrix[masodik][elso] = 1;
	}

	cout << endl;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << szomszedsagi_matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void illeszkM() {
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) {
		int elso, masodik;
		cin >> elso >> masodik;
		illeszkedesi_matrix[elso][i] += 1;
		illeszkedesi_matrix[masodik][i] += 1;
	}
	cout << endl;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << illeszkedesi_matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

void szomszedL() {
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++) {
		int elso, masodik;
		cin >> elso >> masodik;
		szomszedsagi_lista[elso][++szomszedsagi_lista[elso][0]] = masodik;
		szomszedsagi_lista[masodik][++szomszedsagi_lista[masodik][0]] = elso;
	}
	cout << endl;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < n; j++) {
			cout << szomszedsagi_lista[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	// szomszedM();
	// illeszkM();
	szomszedL();

	return 0;
}
