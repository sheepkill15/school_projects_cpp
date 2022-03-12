#include <iostream>
using namespace std;

int n;
int st[100];

void print(int k) {
	for(int i = 0; i < k; i++) {
		cout << st[i] << ' ';
	}
	cout << endl;
}

void partitie(int k, int sum) {
	if(sum == n) {
		print(k);
		return;
	}

	if(k <= n) { 
		for(int i = 1; i <= n; i++) {
			st[k] = i;
			partitie(k+1, sum + i);
		}
	}
	
}

int main()
{
	cin >> n;
	partitie(0, 0);
	
	return 0;
}
