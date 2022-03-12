#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("SZIMPI.BE");
ofstream fout("SZIMPI.KI");

using namespace std;
int n, m;
int illeszkedesi[100][100];
int csucs[100][100];

int varakozasi_sor[100];
int latott[100];
int sor_eleje;
int sor_vege;
int db;

bool k = 1;

void beolvas()
{

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int elso, masodik;
		cin >> elso >> masodik;
		illeszkedesi[elso][i] = 1;
		illeszkedesi[masodik][i] = -1;
	}

	for(int j = 1; j <= m; j++) {
		int elso = 0, masodik = 0;
		for(int i = 1; i <= n; i++) {
			if(illeszkedesi[i][j] == 1) {
				elso = i;
			}
			else if(illeszkedesi[i][j] == -1) {
				masodik = i;
			}
		}
		csucs[elso][masodik] = 1;
	}

}
void bejaras()
{
	while(sor_eleje < sor_vege)
    {
		int jelenlegi = varakozasi_sor[sor_eleje++];
		latott[jelenlegi] = db;
		for(int i = 1; i <= n; i++)
		{
			if(csucs[jelenlegi][i] == 1)
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

void ut()
{
    for (int i = 1; i <= n; i++)
    {
       for(int j = 1; j <= n; j++)
       {
            if (csucs[i][j] != csucs[j][i]) {
                k = 0;
            }
       }
    }
    
    if (k == 1) {
        cout << "Kolcsonos" << endl;
    } else {
        cout << "Nem Kolcsonos" << endl;
    }
}

void c()
{
    int lista[100] = {0}, sz = 0, max = 0, jelen;
    if (k == 1) {
        for (int i = 1; i <= n; i++)
        {
            jelen = 0;
            
           for(int j = 1; j <= n; j++)
           {
                jelen = jelen + csucs[i][j];
           }
           
           if (jelen == max) {
               sz++;
               lista[sz] = i;
           } else {
               if (jelen > max) {
                   max = jelen;
                   sz = 1;
                   lista[sz] = i;
               }
           }
        }
        
        cout << endl;
        
        for (int i = 1; i <= sz; i++) {
            cout << lista[i] << " ";
        }
    }
}

int main()
{
	beolvas();
	db++;
	sor_eleje = 0;
	sor_vege = 1;
	varakozasi_sor[0] = 1;
	bejaras();

	ut();
	c();

	for(int i = 1; i <= n; i++) {
		if(latott[i] == 0) {
			db++;
			sor_eleje = 0;
			sor_vege = 1;
			varakozasi_sor[0] = i;
			bejaras();
		}
	}

	if(db == 1) {
		cout << "nincsenek" << endl;
		return 0;
	}
	cout << "vannak" << endl;
	cout << db << endl;
	bool kiirat[100] = {0};
	for(int i = 1; i <= n; i++) {
		if(kiirat[latott[i]] == 0) {
			kiirat[latott[i]] = 1;
			cout << '(' << i << ' ';
			for(int j = 1; j <= n; j++) {
				if(i == j) continue;
				if(latott[i] == latott[j]) {
					cout << j << ' ';
				}
			}
			cout << ')' << endl;
		}
	}
	

    return 0;
}