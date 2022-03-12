#include <iostream>
using namespace std;

int bal[100], jobb[100];
int pontok, gyoker;

void preorder(int pont) {
    cout << pont;
    if(!bal[pont] && !jobb[pont]) {
        return;
    }
    cout << " ( ";
    if(bal[pont]) {
        preorder(bal[pont]);
        cout << ", ";
    }
    else cout << "., ";
    if(jobb[pont]) {
        preorder(jobb[pont]);
    }
    else cout << '.';
    cout << " ) ";
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
    preorder(gyoker);

    return 0;
}
