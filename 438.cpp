#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (t == 1 || t == 0) {
			cout << 0 << endl;
		}
		else {
			cout << t - 2 << endl;
		}
	}
	return 0;
}