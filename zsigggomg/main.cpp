#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("adat.be");

int a[100][100], k, d[100], t[100], n, pontok;
bool s[100];

void be()
{
    fin >> k >> n >> pontok;
    for(int i = 1; i <= n; i++)
    {
        int c, b;
        fin >> c >> b;
        fin >> a[c][b];
    }
    for(int i = 1; i <= pontok; i++)
        for(int j = 1; j <= pontok; j++)
            if(a[i][j] == 0 and i != j)
                a[i][j] = 1000;
    for(int i = 1; i <= pontok; i++)
        d[i] = a[k][i];
    s[k] = 1;
}

void dijkstra()
{
    bool ell = 0;
    int jelenlegi;
    while(ell == 0)
    {
        ell = 1;
        int mini = 1001;
        for(int i = 1; i <= pontok; i++)
            if(d[i] < mini and s[i] == 0)
            {
                mini = d[i];
                jelenlegi = i;
            }
        s[jelenlegi] = 1;
        for(int i = 1; i <= pontok; i++)
            if(s[i] == 0 and d[jelenlegi] + a[jelenlegi][i] < d[i])
            {
                d[i] = d[jelenlegi] + a[jelenlegi][i];
                t[i] = jelenlegi;
            }
        for(int i = 1; i <= pontok; i++)
            if(s[i] == 0)
                ell = 0;
    }   
}

int ossz = 0;

void ki(int p)
{
    cout << p << " ";
    ossz += d[p];
    if(t[p] != 0)
        ki(t[p]);
}

int main()
{
    be();
    dijkstra();
    for(int i = 1; i <= pontok; i++)
        cout << s[i] << " ";
    cout << endl;
    for(int i = 1; i <= pontok; i++)
        cout << d[i] << " ";
    cout << endl;
    for(int i = 1; i <= pontok; i++)
        cout << t[i] << " ";
    /*for(int i = 1; i <= pontok; i++)
    {
        if(i != k)
            ki(i);
        cout << ossz << endl;
        ossz = 0;
    }*/
    return 0;
}