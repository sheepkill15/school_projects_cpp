
#include <iostream>
#include <fstream>

//#define cin fin
//#define cout fout

using namespace std;

ifstream fin("no_pals.in");
ofstream fout("no_pals.out");

#define MOD 666013

int main()
{
    int n , i ;
    unsigned long long kil=90, amitvonunk=9;
    cin >> n;
    cout << 0 << endl;
    for(i=2;i<=n;i++)
    {
               unsigned long long megold = (kil - amitvonunk)%MOD;
                cout << megold << endl;
             kil *= 10;
            if(i%2 == 0)
			{
                amitvonunk *= 10;
			}
    }
}
