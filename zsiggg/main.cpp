#include <iostream>
#include <fstream>

#define cout fout

using namespace std;

ifstream fin("zapada.in");
ofstream fout("zapada.out");

int n, m, latott[110], megoldas[3][110];
int k = 0;
int v, kot[110];

struct kruszi
{
    int a;
    int b;
    int c;
};

kruszi t[110];

void lat()
{
    for (int i = 1; i <= n; i++)
        latott[i] = i;
}

void beolvas()
{
    fin >> n >> m;
    for (int i = 0; i < m; i++)
        fin >> t[i].a >> t[i].b >> t[i].c;
    fin >> v;
    for (int i = 0; i < v; i++)
        fin >> kot[i];
}

void rendezes()
{
    int sz = 0;
    for (int i = 0; i < v; i++)
    {
        kruszi a = t[sz];
        t[sz] = t[kot[i] - 1];
        t[kot[i] - 1] = a;
        sz++;
    }
    bool ell = true;
    while (ell == true)
    {
        ell = false;
        for (int i = sz; i < m - 1; i++)
            if (t[i].c > t[i + 1].c)
            {
                kruszi a = t[i];
                t[i] = t[i + 1];
                t[i + 1] = a;
                ell = true;
            }
    }
}

void kruszkal()
{
    for (int i = 0; i < m; i++)
    {
        if (k == n - 1)
            break;
        if (latott[t[i].a] != latott[t[i].b])
        {
            if (latott[t[i].a] > latott[t[i].b])
            {
                for (int j = 1; j <= n; j++)
                {
                    if (latott[j] == latott[t[i].a])
                        latott[j] = latott[t[i].b];
                }
            }
            else
            {
                for (int j = 1; j <= n; j++)
                {
                    if (latott[j] == latott[t[i].b])
                        latott[j] = latott[t[i].a];
                }
            }
            megoldas[0][k] = t[i].a;
            megoldas[1][k] = t[i].b;
            megoldas[2][k] = t[i].c;
            k++;
        }
    }
}

void kiiras()
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += megoldas[2][i];
    }
    cout << sum << endl;
}

int main()
{
    beolvas();
    lat();
    rendezes();
    kruszkal();
    kiiras();
    //for(int i = 0; i < m; i++)
    //  cout << t[i].a << " " << t[i].b << " " << t[i].c << endl;
    return 0;
}