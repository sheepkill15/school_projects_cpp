#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("nm.in");
ofstream fout("nm.out");

void add(short a[], short b[], short c[]) {

	short tr = 0;
	c[0] = max(a[0], b[0]);
	for(int i = 1; i <= c[0]; i++) {
		c[i] = a[i] + b[i] + tr;
		tr = c[i] / 10;
		c[i] %= 10;
	}
	if(tr) {
		c[0]++;
		c[c[0]] = tr;
	}
}

void create(long long numar, short numar_mare[]) {
	numar_mare[0] = 0;
	while(numar) {
		short ultim = numar % 10;
		numar_mare[numar_mare[0]++ + 1] = ultim;
		numar /= 10;
	}
}

void print(short numar_mare[]) {
	for(int i = numar_mare[0]; i >= 1; i--) {
		fout << numar_mare[i];
	}
	fout << endl;
}

void copy(short a[], short b[]) {

	for(int i = 1; i <= a[0]; i++) {
		a[i] = 0;
	}

	a[0] = b[0];
	for(int i = 1; i <= a[0]; i++) {
		a[i] = b[i];
	}
}

void produs(short a[], long long number, short c[]) {
	short tr = 0;
	c[0] = a[0];
	for(int i = 1; i <= c[0]; i++) {
		c[i] = a[i] * number + tr;
		tr = c[i] / 10;
		c[i] %= 10;
	}
	while(tr) {
		c[0]++;
		c[c[0]] = tr % 10;
		tr /= 10;
	}
}

void produs(short a[], short b[], short c[]) {
	short tr = 0;
	c[0] = a[0] + b[0] - 1;
	for(int i = 1; i <= c[0]; i++) {
		c[i] = 0;
	}
	for(int i = 1; i <= a[0]; i++) {
		for(int j = 1; j <= b[0]; j++) {
			c[i + j - 1] = a[i] * b[j] + c[i + j - 1];
		}
	}

	for(int i = 1; i <= c[0]; i++) {
			c[i] += tr;
			tr = c[i] / 10;
			c[i] %= 10;
	}

	while(tr) {
		c[0]++;
		c[c[0]] = tr % 10;
		tr /= 10;
	}
}

int main()
{
	long long numar1;
	long long multiplier;

	//int n;
	//cin >> n;

	short numar_mare1[1000] = {0}, numar_mare2[1000] = {0};

	fin >> numar1;

	create(numar1, numar_mare1);

	fin >> multiplier;

	create(multiplier, numar_mare2);

	short suma[1000] = {0};

	produs(numar_mare1, numar_mare2, suma);

	// for(int i = 2; i <= n; i++) {
	// 	produs(numar_mare1, i, suma);
	// 	copy(numar_mare1, suma);
	// }

	// for(int i = 0; i < n; i++) {

	// 	add(numar_mare1, numar_mare2, suma);
	// 	copy(numar_mare1, numar_mare2);
	// 	copy(numar_mare2, suma);

	// }

	print(suma);

	return 0;
}
