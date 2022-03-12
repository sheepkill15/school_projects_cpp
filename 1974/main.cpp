#include <iostream>
#include <fstream>
#include <algorithm>
#define cin fin
#define cout fout
using namespace std;

const size_t N = 2e5 + 1;

struct El
{
	int elso;
	int masodik;
	int koltseg;
	int index;
};

ifstream fin("trumplandia.in");
ofstream fout("trumplandia.out");

El ellista[N];
int n, m, q;

bool compare(const El &a, const El &b)
{
	return a.koltseg < b.koltseg;
}

int kruskal()
{
	int latott[N];
	size_t osszkoltseg = 0;

	for (int i = 1; i <= n; i++)
	{
		latott[i] = i;
	}

	int k = 0;
	for (int i = 0; i < m; i++)
	{
		if (k == n)
			break;

		if (latott[ellista[i].elso] != latott[ellista[i].masodik])
		{
			int kisebb = std::min(latott[ellista[i].elso], latott[ellista[i].masodik]);
			int nagyobb = std::max(latott[ellista[i].elso], latott[ellista[i].masodik]);
			k++;
			osszkoltseg += ellista[i].koltseg;
			for (int j = 1; j <= n; j++)
			{
				if (latott[j] == nagyobb)
				{
					latott[j] = kisebb;
				}
			}
		}
	}

	return osszkoltseg;
}

int main()
{
	cin >> n >> m >> q;

	for (int i = 0; i < m; i++)
	{
		cin >> ellista[i].elso >> ellista[i].masodik >> ellista[i].koltseg;
		ellista[i].index = i;
	}

	sort(ellista, ellista + m, compare);

	cout << kruskal() << endl;
	for(int i = 0; i < q; i++) {
		int melyik;
		cin >> melyik;

		int igazi;

		for(int i = 0; i < m; i++) {
			if(ellista[i].index == melyik - 1) {
				igazi = i;
				break;
			}
		}
		swap(ellista[0], ellista[igazi]);
		cout << kruskal() << endl;
		swap(ellista[0], ellista[igazi]);
	}

	return 0;
}
