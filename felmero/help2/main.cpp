#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("TERKEP.BE");
ofstream fout("TERKEP.KI");
int terkep[100][100];

int varakozasi_sor[100], sor_eleje = 0, sor_vege = 0, latott[100], n, m, db;
void beolvas()
{
    fin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        int elso, masodik;
        fin >> elso >> masodik;
        terkep[elso][masodik] = 1;
        terkep[masodik][elso] = 1;
    }

}

void kiiras()
{
        for (int i = 1; i <= n; i++)
        {
           for(int j = 1; j <= n; j++)
           {
                fout << terkep[i][j] << " ";
           }
           fout << endl;
        }
}
void bejaras()
{
	while(sor_eleje < sor_vege)
    {
		int jelenlegi = varakozasi_sor[sor_eleje++];
		for(int i = 1; i <= n; i++)
		{
			if(terkep[jelenlegi][i] == 1)
			{
				if(latott[i] == 0)
				{
					latott[i] = db;
					varakozasi_sor[sor_vege++] = i;
				}
			}
		}
	}
}
void b()
{
    int van = 0, sz;

    for (int i = 1; i <= n; i++)
    {
        sz = 1;
        for (int j = 1; j <= n; j++)
        {
          sz = sz + terkep[i][j];
        }

        if (sz == n) {
            van = 1;
            fout << i << " ";
        }
    }

    if (!van)
    {
        fout << "Nincs ilyen";
    }

    fout << endl;
}

void c()
{
    int sz, db = 0;

    for (int i = 1; i <= n; i++)
    {
        sz = 0;
        for (int j = 1; j <= n; j++)
        {
          sz = sz + terkep[i][j];
        }

        if (sz == 2)
        {
            db++;
        }
    }

    if (db)
    {
        fout << db;
    } else
    {
        fout << "Nincs ilyen";
    }

    fout << endl;
}

int main()
{
    beolvas();
    kiiras();
	b();
	c();
	db++;
	sor_eleje = 0;
	sor_vege = 1;
	varakozasi_sor[0] = 1;
	bejaras();
	bool jo = true;
	for(int i = 1; i<=n; i++)
        {
		if(latott[i] != 1)
		{
			jo = false;
			break;
		}
	}

	if(jo)
    {
		fout << "igen" << endl;
	}
	else fout << "nem" << endl;

	for(int i = 1; i <= n; i++) {
		int sum = 0;
		for(int j = 1; j <= n; j++)
		{
			if(terkep[i][j] == 1)
            {
				sum += 1;
			}
		}
		if(sum == 0)
        {
			fout << i << ' ';
		}
	}

    return 0;
}