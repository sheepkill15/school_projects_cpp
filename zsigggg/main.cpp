#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("adat.be");

int n, m, latott[100], megoldas[2][100];
int a = 0;

struct kruszi
{
    int a;
    int b;
    int c;
};

kruszi t[100];

void lat()
{
    for(int i = 1; i <= n; i++)
        latott[i] = i;
}

void beolvas()
{
    fin >> n >> m;
    for(int i = 0; i < m; i++)
        fin >> t[i].a >> t[i].b >> t[i].c;
}

void rendezes()
{
    bool ell = true;
    while(ell == true)
    {
        ell = false;
        for(int i = 0; i < m - 1; i++)
            if(t[i].c > t[i + 1].c)
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
    while(a < n)
    {
        for(int i = 0; i < m; i++)
        {
            if(latott[t[i].a] != latott[t[i].b])
            {
                if(latott[t[i].a] > latott[t[i].b])
                    for(int j = 1; j <= n; i++)
                        if(latott[j] == latott[t[i].a])
                            latott[j] = latott[t[i].b];
                else
                    for(int j = 1; j <= n; i++)
                        if(latott[j] == latott[t[i].b])
                            latott[j] = latott[t[i].a];
                megoldas[0][a] = t[i].a;
                megoldas[1][a] = t[i].b;
                a++;
            }
        }
    }
}

void kiiras()
{
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < 2; j++)
            cout << megoldas[j][i] << " ";
        cout << endl;
    }
}

int main()
{
    for(int i = 1; i <= n; i++)
        latott[i] = i;
    //lat();
    beolvas();
    //rendezes();
    //kruszkal();
    //kiiras();
    for(int i = 1; i <= n; i++)
        cout << latott[i] << " ";
    return 0;
}