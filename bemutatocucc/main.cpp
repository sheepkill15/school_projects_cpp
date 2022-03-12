#include <iostream>

using namespace std;

struct Text {
    char alma;
};

int main()
{
    Text szoveg;

    Text *gyumolcsarus;
    gyumolcsarus = &szoveg;

    szoveg.alma = 'a';
    gyumolcsarus->alma = 'b';
    cout << gyumolcsarus->alma << endl;



    return 0;
}
