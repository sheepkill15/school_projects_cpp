#include <iostream>

using namespace std;

struct Termek {
    int ID;
    int mennyiseg;
    char nev[15];
};

struct {
    int mennyiseg;
    char nev[15];
} egyedi_termek;

union SzamVagyBetu {
        int szam;
        char szam_betukent;
};

struct Vector3 {
    union {
        struct {
            int x;
            int y;
            int z;
        };
        struct {
            int r;
            int g;
            int b;
        };
    };
};


int main()
{
    Termek termek;
    termek.mennyiseg = 5;

    egyedi_termek.mennyiseg = 6;

    cout << termek.mennyiseg << endl;
    cout << egyedi_termek.mennyiseg << endl;

    SzamVagyBetu szvb;
    szvb.szam = 65;
    cout << szvb.szam << ' ' << szvb.szam_betukent << endl;

    Vector3 vector;
    vector.r = 1;
    vector.y = 2;
    vector.b = 3;

    cout << "x: " << vector.x << " y: " << vector.y << " z: " << vector.z << endl;
    cout << "r: " << vector.r << " g: " << vector.g << " b: " << vector.b << endl;

    return 0;
}
