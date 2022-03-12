#include <iostream>
using namespace std;

struct Foglalas
{
    int bal = -1;
    int jobb = -1;
} foglalasok[100];
int k;
int n;
int preorder[100];
int inorder[100];


bool look(int j, int i) {
    if(i - j == 1 || i - j == -1) return false;
    int sgn = (inorder[preorder[j]] < inorder[preorder[i]]) ? 1 : -1;
    for(int x = j+1; x < i; x++) {
        int sgn2 = (inorder[preorder[j]] < inorder[preorder[x]]) ? 1 : -1;
        if(sgn != sgn2) return false;
    }
    return true;
}
/*
* -1  -> bal
*  0  -> nem elerheto
*  1  -> jobb
*/
int left_or_right(int pont, int keresett)
{
    if ((inorder[pont] < inorder[preorder[0]] && inorder[keresett] > inorder[preorder[0]]) ||
        (inorder[pont] > inorder[preorder[0]] && inorder[keresett] < inorder[preorder[0]]))
        return 0;
    if (foglalasok[pont].bal == -1 && inorder[pont] > inorder[keresett])
    {
        foglalasok[pont].bal = keresett;
        return -1;
    }
    if (foglalasok[pont].jobb == -1 && inorder[pont] < inorder[keresett])
    {
        foglalasok[pont].jobb = keresett;
        return 1;
    }
    return 0;
}


int main()
{
    cout << "Pontok szama: ";
    cin >> n;

    cout << "Preorder: ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    cout << "Inorder: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        inorder[temp] = i;
    }

    cout << "Gyoker: " << preorder[0] << endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(look(j, i)) {
                continue;
            }
            int wh = left_or_right(preorder[j], preorder[i]);
            if (wh)
            {
                if (wh < 0) {
                    cout << preorder[j] << " bal " << preorder[i] << endl;
                }
                else
                {
                    cout << preorder[j] << " jobb " << preorder[i] << endl;
                }
                goto skip;
            }
        }
    skip:;
    }

    return 0;
}
