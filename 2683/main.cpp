#include <iostream>

using namespace std;

const int N = 1e6;

int d[N],k;

void keres(int x) {
    
    if(x <= d[k])
    {
        d[++k] = x;
        return;
    }
    int st, dr, p, mid;
    p = st = 1;
	dr = k;
    while(st <= dr)
    {
        mid = (st+dr)/2;
        if(d[mid] < x) {
            p = mid;
			dr = mid-1;
		}
        else
            st = mid+1;
    }
    d[p] = x;
}

int main()
{
    int n, x;
    cin >> n >> x;
    d[1] = x;
    k = 1;

    for(int i = 2; i <= n; i++) {
        cin>>x;
		keres(x);
	}

    cout << k << endl;
    return 0;
}
