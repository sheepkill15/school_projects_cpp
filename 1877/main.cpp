#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n, t[1001], k,a, sum=0;
    cin >> n;
	
    for(int i = 1; i <= n; i++) {
		cin >> t[i];
	} 

    cin >> k;
    
	sort(t + 1, t + n + 1);

    for(int i = 1; i <= k; i++) {
        t[i] = -t[i];
    }
    for(int i = 1; i <= n; i++) {
		sum += t[i];
	}
    cout << sum << endl;
    return 0;
}