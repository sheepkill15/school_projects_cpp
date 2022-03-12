#include <iostream>
using namespace std;

int levag(int szam)
{
    return szam / 10 - (szam % 10) * 3;
}

int main()
{
    int szam;
    cin >> szam;
    cout << (szam % 31 == 0 ? "IGEN" : "NEM") << endl;
    while(szam > 0) {
        szam = levag(szam);
        if(szam >= 0) {
            cout << szam << ' ';
        }
    }
    cout << endl;
}