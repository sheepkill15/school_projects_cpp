#include <iostream>
#include <vector>

using namespace std;

void elso(const string& C) {
    int sum = 0;
    for(int i = 0; i < C.size(); i++) {
        if(C[i] == 'H' || C[i] == 'V') sum++;
    }
    cout << sum + 1 << endl;
}

int get_next(const string& str) {
    int next = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] != 'H' && str[i] != 'V' && str[i] != '*') {
            next = next * 10 + (str[i] - '0');
        }
        else break;
    }
    return next;
}

int szel = 0, hossz = 0;
string C;

struct {
    vector<string> csillagok;
    vector<string> V;
    vector<string> H;
} data;

void masodik(int ki, int kj) {
    while(C.size() > 0) {
        if(C[0] == 'H') {
            int next = get_next(C.substr(1));
            if(ki + next > hossz) {
                hossz = ki + next;
            }
            data.H.push_back('H' + to_string(ki + next));
            C = C.substr(1);
            masodik(ki, kj);
            masodik(ki + next, kj);
            return;
        }
        else if(C[0] == 'V') {
            int next = get_next(C.substr(1));
            if(kj + next > szel) {
                szel = kj + next;
            }
            data.V.push_back('V' + to_string(kj + next));
            C = C.substr(1);
            masodik(ki, kj);
            masodik(ki, kj + next);
            return;
        }
        else if(C[0] == '*') {
            C = C.substr(1);
            data.csillagok.push_back("*");
            return;
        }
        C = C.substr(1);
    }
}
int melyseg;

int harmadik(int ki, int kj) {
    

    return 0;
}

int main()
{
    int p;
    cin >> p;
    cin >> C;

    switch(p) {
    case 1:
        elso(C);
        break;
    case 2:
        masodik(0, 0);
        cout << hossz + 1 << ' ' << szel + 1 << endl;
        break;
    case 3:
        cout << harmadik(0, 0) << endl;
        break;
    case 4:
        cout << C << endl;
        break;
    }

    return 0;
}
