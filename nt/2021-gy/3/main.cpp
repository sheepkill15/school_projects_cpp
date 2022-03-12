#include <iostream>

using namespace std;

int tomb[100000];
int szamok[100000];

int main()
{

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> szamok[i];
        tomb[i] = INT32_MAX;
    }
    tomb[1] = 0;
    for (int i = 1; i < n; i++)
    {
        tomb[i + 1] = std::min(tomb[i + 1], tomb[i] + 1);
        if (szamok[i] > i)
        {
            tomb[szamok[i]] = std::min(tomb[szamok[i]], tomb[i] + 1);
        }
    }

    cout << tomb[n] << endl;
}