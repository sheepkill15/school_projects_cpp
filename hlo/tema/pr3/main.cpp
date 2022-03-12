#include <iostream>
using namespace std;

int n;
int st[100];

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
	
	for(int i = st[k-1] + 1; i <= n; i++) {
		st[k] = i;
		partitie(k+1, sum + i);
	}
	
}

int main()
{
	cin >> n;
	partitie(1, 0);
	
	return 0;
}
