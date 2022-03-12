#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, t[100000];

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}

	sort(t, t + n);

	unsigned long long szorzat1 = t[0] * t[1];
	unsigned long long szorzat2 = t[n-2] * t[n-1];

	cout << max(szorzat1, szorzat2);

	//cout << endl;

	return 0;
}
