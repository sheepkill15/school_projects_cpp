#include <iostream>
using namespace std;

bool palindrom(int szam) {
	int eredeti = szam;
	int visszafele = 0;
	while(szam) {
		visszafele = visszafele*10 + szam%10;
		szam /= 10;
	}
	return visszafele == eredeti;
}

int main()
{
	
	cout << palindrom(1550) << std::endl;
	
	return 0;
}
