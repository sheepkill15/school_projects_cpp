#include <iostream>
// #include <fstream>
// #define cin fin
using namespace std;

// ifstream fin("adat.be");

const int size = 1e3;

bool alakithato(int n, bool matrix[size][size])
{
    if (n % 2 == 1)
        return false;
    for (int i = 0; i < n; i++)
    {
        int db0 = 0;
        int db1 = 0;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j])
                db1++;
            else
                db0++;
        }
        if (db1 > db0)
            return false;
    }
    return true;
}

void elso(int t)
{
    for (int i = 0; i < t; i++)
    {
        int n;
        bool matrix[size][size];
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            string binaris;
            cin >> binaris;
            for (int x = 0; x < n; x++)
            {
                matrix[j][x] = binaris[x] - '0' == 1;
            }
        }
        cout << alakithato(n, matrix) << endl;
    }
}

bool check_if_tabla(int n, bool matrix[size][size])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                if (matrix[i - 1][j] == matrix[i][j])
                    return false;
            }
            else if (i < n - 1)
            {
                if (matrix[i + 1][j] == matrix[i][j])
                    return false;
            }
            if (j > 0)
            {
                if (matrix[i][j - 1] == matrix[i][j])
                    return false;
            }
            else if (j < n - 1)
            {
                if (matrix[i][j + 1] == matrix[i][j])
                    return false;
            }
        }
    }
    return true;
}

void masodik(int t)
{
    for (int i = 0; i < t; i++)
    {
        int n;
        bool matrix[size][size];
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            string binaris;
            cin >> binaris;
            for (int x = 0; x < n; x++)
            {
                matrix[j][x] = binaris[x] - '0' == 1;
            }
        }

        if (check_if_tabla(n, matrix))
        {
            cout << 0 << endl;
            continue;
        }

        int sum = 0;
        for (int x = 0; x < n; x++)
        {
            if (matrix[x][0] == false)
                sum++;
        }
        cout << sum << endl;
    }
}

void harmadik(int t)
{
    for (int i = 0; i < t; i++)
    {
        int n;
        bool matrix[size][size];
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            string binaris;
            cin >> binaris;
            for (int x = 0; x < n; x++)
            {
                matrix[j][x] = binaris[x] - '0' == 1;
            }
        }
        cout << 0 << endl;
    }
}

int main()
{
    int p, t;
    cin >> p >> t;
    switch (p)
    {
    case 1:
        elso(t);
        break;
    case 2:
        masodik(t);
        break;
    case 3:
        harmadik(t);
        break;
    }
    return 0;
}

/*

0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0

1 1 0 0 0
1 0 1 0 1
0 1 1 0 0
0 0 1 1 1
1 0 1 1 0

1 0 1 0 1 0 1
0 1 0 1 0 1 0 
1 0 1 0 1 0 1
0 1 0 1 0 1 0 
1 0 1 0 1 0 1 
0 1 0 1 0 1 0 
1 0 1 0 1 0 1

1 1 1 1 0 0 0
0 0 0 0 1 1 1
1 1 1 1 0 0 0
1 1 1 0 0 0 0
0 0 0 1 1 1 1
1 1 1 0 0 0 0
0 0 0 1 1 1 1
*/