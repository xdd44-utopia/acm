#include <iostream>

using namespace std;

int f[7500];
int coin[4] = {5, 10, 25, 50};

int main() {
	
	for (int i=0;i<7500;i++) {
		f[i] = 1;
	}
	for (int i=0;i<4;i++) {
		for (int j=coin[i];j<7500;j++) {
			f[j] += f[j-coin[i]];
		}
	}
	
	int n;
	while (cin >> n) {
		cout << f[n] << endl;
	}
	
	return 0;
}
