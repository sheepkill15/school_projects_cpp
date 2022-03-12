#include <iostream>

using namespace std;

void random_fuggveny(int egy_szam) {
    // valami hasznosat csinal
}

int main()
{

    {
        int szam;
        cin >> szam;

        cout << "A szam: " << szam << endl;
    }

    cout << "A szam megint: " << szam << endl;

    {
        {
            {
                {
                    {
                        char titkos_uzenet[] = "hali";
                    }
                }
            }
            cout << titkos_uzenet << endl;
        }
    }

    int* szam;

    {
        int* egy_uj_szam = new int(5);
        szam = egy_uj_szam;
        cout << *egy_uj_szam << endl;
    }

    cout << *szam << endl;

    delete szam;

    cout << *szam << endl;

    return 0;
}
