#include <iostream>
using namespace std;

int arr[101];
int n_monede;
int w[101];

int rezolva(int target) {
	if(target == 0) {
		return 0;
	}
	else if(target < 0) {
		return INT16_MAX;
	}
	else if(arr[target]) {
		return arr[target];
	}
	int mini = INT16_MAX;
	for(int i = 0; i < n_monede; i++) {
		mini = std::min(mini, rezolva(target - w[i]));
	}
	arr[target] = mini + 1;
	return arr[target];
}

int main()
{
	int S;
	cin >> n_monede;
	for(int i = 0 ; i < n_monede; i++) {
		cin >> w[i];
	}
	cin >> S;
	cout << rezolva(S) << endl;
	
	return 0;
}
