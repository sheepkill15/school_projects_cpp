#include <iostream>
#include <cmath>

using namespace std;

int pontok, gyoker;
int bal[100];
int jobb[100];

int preorder_es_melyseg(int pont) {
    cout << pont << ' ';
    int elso = 0, masodik = 0;
    if(bal[pont]) {
        elso = preorder(bal[pont]);
    }
    if(jobb[pont]) {
        masodik = preorder(jobb[pont]);
    }
    return std::max(elso, masodik) + 1;
}

int inorder_es_melyseg(int pont) {
    int elso = 0, masodik = 0;
    if(bal[pont]) {
        elso = inorder(bal[pont]);
    }
    cout << pont << ' ';
    if(jobb[pont]) {
        masodik = inorder(jobb[pont]);
    }
    return std::max(elso, masodik) + 1;
}

int posztorder_es_melyseg(int pont) {
    int elso = 0, masodik = 0;
    if(bal[pont]) {
        elso = posztorder(bal[pont]);
    }
    if(jobb[pont]) {
        masodik = posztorder(jobb[pont]);
    }
    cout << pont << ' ';
    return std::max(elso, masodik) + 1;
}

int levelek(int x)
{
    int l = 0;
    if(bal[x]==0 && jobb[x]==0)
        return 1;
    if(bal[x]!=0)
        l += levelek(bal[x]);

    if(jobb[x]!=0)
        l += levelek(jobb[x]);
    return l;
}

int szinten(int pont, int szint, int melyseg = 0) {
    int db = 0;
    if(szint == melyseg) {
        return 1;
    }
    if(bal[pont]) {
        db += szinten(bal[pont], szint, melyseg + 1);
    }
    if(jobb[pont]) {
        db += szinten(jobb[pont], szint, melyseg + 1);
    }
    return db;
}

bool teljes(int melyseg) {
    int sum = 0;
    for(int i = 0; i < melyseg; i++) {
        sum += pow(2, i);
    }
    return sum == pontok;
}

int main()
{
    cin >> pontok >> gyoker;
    for(int i = 1; i <= pontok; i++) {
        cin >> bal[i];
    }
    for(int i = 1; i <= pontok; i++) {
        cin >> jobb[i];
    }
    int melyseg;
    cout << endl << "Preorder: " << preorder(gyoker) - 1 << endl;
    
    cout << endl << "Inorder: " << inorder(gyoker) - 1 << endl;
    
    cout << endl << "Posztorder: ";
    melyseg = posztorder(gyoker);
    cout << endl;

    cout << "Levelek: " << levelek(gyoker) << endl;

    cout << "3. szinten: " << szinten(gyoker, 3) << endl;
    
    if(teljes(melyseg)) {
        cout << "Teljesen kiegyensulyozott";
    }
    else cout << "Nem teljesen kiegyensulyozott";

    return 0;
}
