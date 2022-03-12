#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("Penz.in");
ofstream fout("Penz.out");

int S, n;
int tomb[100];

void beolvasas()
{
    fin >> n;
    fin >> S;
    for (int i = 0; i < n; i++)
    {
        fin >> tomb[i];
    }
}
void kiiras()
{
    for (int i = 0; i < n; i++)
    {
        fout << tomb[i] << " ";
    }
	fout << endl;
}

void rendezes()
{
    int p = 1;
    while (p == 1)
    {
        p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (tomb[i] > tomb[i + 1])
            {
                p = 1;
                int seged = tomb[i];
                tomb[i] = tomb[i + 1];
                tomb[i + 1] = seged;
            }
        }
    }
}

void kifizetes()
{
  int S2;
  S2 = S;
  for (int i = n - 1; i >= 0; i--)
  {
        if (S2 / tomb[i] >= 1)
        {
           fout << tomb[i] << "x" << S2 / tomb[i] << endl;
           S2 = S2 - tomb[i] * (S2 / tomb[i]);
        }
  }
}
int main()
{
	beolvasas();
	kiiras();
	rendezes();
	kifizetes();
}