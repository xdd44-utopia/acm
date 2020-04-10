#include<iostream>

using namespace std;

int main() {
	int arr[10001];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 2000; i++) {
		arr[i] = ((arr[i - 1] % 10) + (arr[i - 2] % 10)) % 10;
	}
	int t;
	while (cin >> t) {
		cout << arr[t] << endl;
	}
	return 0;
}