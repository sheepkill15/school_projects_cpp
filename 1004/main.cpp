#include <iostream>
#include <fstream>

//#define cin fin
//#define cout fout

using namespace std;

ifstream fin("eureni.in");
ofstream fout("eureni.out");

int main()
{
    int S, n, e, hatv[1001], k = 1;
    int db = 0;
    cin >> S >> n >> e;
    hatv[0] = 1;
    int elozo = 1;
    for(int i = 0; i < n; i++)
    {
        elozo *= e;
        hatv[k++] = elozo;
    }
    for(int i = k - 1; i >= 0; i--)
    {
        if(S/hatv[i] > 0)
        {
			int local_db = S/hatv[i];
            db += local_db;
            cout << hatv[i] << ' ' << local_db <<endl;
            S -= hatv[i] * (local_db);
        }
    }
    cout << db << endl;
    return 0;
}