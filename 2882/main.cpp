#include <iostream>
#include <fstream>

//#define cin fin
//#define cout fout

using namespace std;

ifstream fin("no_pals.in");
ofstream fout("no_pals.out");

#define MOD 666013

long long kil=1, amitvonunk=9, eddig;

int pal(int i) {
	if(i == 1) return 0;
    if(i % 2 == 0) {
        if(i == 2) kil *= 9;
        else kil *= 10;
        kil %= MOD;
        eddig = amitvonunk - kil;
    }
    else {
        long long seged = (kil * 10) % MOD;
        eddig = amitvonunk - seged;
    }
    
    while(eddig < 0) eddig += MOD;
    eddig %= MOD;
    return eddig;
}
   
int main()
{
    int n , i ;
    
    cin >> n;
    for(i=1;i<=n;i++)
    {
    	cout << pal(i) << endl;
        amitvonunk *= 10;
        amitvonunk %= MOD;
    }
}
