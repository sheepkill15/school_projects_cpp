#include <iostream>
using namespace std;

int n;
int st[100];
int K;

void print(int k) {
	for(int i = 1; i < k; i++) {
		cout << st[i] << ' ';
	}
	cout << endl;
}

void partitie(int k, int sum) {

	if(sum >= K) {
		if(sum == K && k == n + 1)
			print(k);
		return;
	}
	
	for(int i = st[k-1] - 1; i >= 1; i--) {
		st[k] = i;
		partitie(k+1, sum + i);
	}
	
}

int main()
{
	cin >> K >> n;
	st[0] = K + 1;
	partitie(1, 0);
	
	return 0;
}
