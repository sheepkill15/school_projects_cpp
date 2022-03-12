#include <fstream>
#include <iostream>

//#define cin fin
//#define cout fout

using namespace std;

ifstream fin("radiera.in");
ofstream fout("radiera.out");

const int N = 1e6;

int D[N], k, A[N];

// void keres(int x) {
//     if(x >= d[k])
//     {
//         d[++k] = x;
//         return;
//     }
//     // int st, dr, p, mid;
//     // p = st = 1;
// 	// dr = k;
//     // while(st <= dr)
//     // {
//     //     mid = (st+dr)/2;
//     //     if(d[mid] < x) {
//     //         p = mid;
// 	// 		dr = mid-1;
// 	// 	}
//     //     else
//     //         st = mid+1;
//     // }
//     // d[p] = x;
// }

int main() {
  int n;
  cin >> n;
  k = 1;

  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
//   int honnan = 1;
//   int elozo = A[honnan];
//   for(int i = 2; i <= n; i++) {
// 	  if(A[i] < elozo) {
// 		  honnan = i;
// 		  break;
// 	  }
// 	  elozo = A[i];
//   }
// 	D[k] = A[honnan];
	D[k] = A[1];
  for(int i = 2 ; i <= n ; i ++)
	{
	    if(A[i] >= D[k])
	        D[++k] = A[i];
	    else
	    {
	        int st = 1; 
			int dr = k;
			int poz = k + 1;
	        while(st <= dr)
	        {
	            int m = (st + dr) / 2;
	            if(D[m] > A[i])
	                {
						poz = m ;
					 	dr = m - 1;
					}
	            else
	                st = m + 1;
	        }
	        D[poz] = A[i];
	    }
	}

	// for(int i = 1; i <= k; i++) {
	// 	cout << D[i] << ' ';
	// }
	// cout << endl;

  cout << n - k << endl;
  return 0;
}
