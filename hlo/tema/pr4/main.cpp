#include <iostream>
using namespace std;

int n;
int m;
int st[100];

int a[100];

void print(int k) {
	for(int i = 1; i < k; i++) {
		cout << st[i] << ' ';
	}
	cout << endl;
}

void partitie(int k, int sum) {

	if(sum >= n) {
		if(sum == n)
			print(k);
		return;
	}
	
	for(int i = 0; i < m; i++) {
		st[k] = a[i];
		partitie(k+1, sum + a[i]);
	}
	
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	partitie(1, 0);
	
	return 0;
}
