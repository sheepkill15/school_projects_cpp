#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream fin ("eureni.in");
ofstream fout ("eureni.out");

#define fin cin
#define fout cout

int main()
{
    float s,n,e,t[1000];
    fin >> s;
    fin >> n;
    fin >> e;
    for (int i=0;i<=n;i++)
    {
        t[i]=pow(e,i);
    }
    int ar=0,j=0;
    for (int i=n;i>=0;i--)
    {
		if(t[i] <= s) {
        while (t[i]<=s)
        {
            s=s-t[i];
            j=j+1;
            ar=ar+1;
		}
        fout << t[i] << " " << j << endl;
        j=0;
		}
        
    }
    fout << ar;
    return 0;
}