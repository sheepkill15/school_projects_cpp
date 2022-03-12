#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("gomba.in");
ofstream fout("gomba.out");

int n, m, erdo[100][100] = {0}, megold = 0, maxim;

void beolvas ()
{
	fin >> n >> m;

	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
		{
			fin >> erdo[i][j];
		}
	}  
}

void kiir ()
{
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
		{
		    fout << erdo[i][j] << " ";
		}
		
		fout << endl;
	}  
}

void megoldas () {
	for(int i = 1; i <= n; i++)
    {
		for(int j = 1; j <= m; j++)
		{
		    maxim = max(erdo[i][j+1], erdo[i-1][j]);
		    maxim = max(maxim, erdo[i-1][j+1]);
			erdo[i][j] += maxim;
		}
	}

	for(int j = 0; j < m; j++)
    {
		if(erdo[n][j] >= megold)
		{
			megold = erdo[n][j];
		}
	}

	fout << megold;
}

int Hello(const char* szoveg) {
	return szoveg[0];
}

int main()
{
    beolvas();
    //kiir();
    megoldas();
	cout << Hello("Asdasd") << endl;
	return 0;
}
