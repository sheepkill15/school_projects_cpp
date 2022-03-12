#include <iostream>

using namespace std;

int main()
{

    int n = 4;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(sum >= 200) {
                goto vege;
            }
            sum += i * j;
        }
    }
vege:
    cout << "Vege!" << endl;

    return 0;
}
