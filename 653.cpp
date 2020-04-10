#include<iostream>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		int **arr = new int*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[m];
		}
		bool inCorner = false;
		bool inSide = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
				if (arr[i][j]) {
					if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
						inCorner = true;
					}
					else if (i*j == 0 || i == n - 1 || j == m - 1) {
						inSide = true;
					}
				}
			}
		}

		if (inCorner) {
			cout << 1 << endl;
		}
		else if (inSide) {
			cout << 2 << endl;
		}
		else {
			cout << 4 << endl;
		}

		for (int i = 0; i < n; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}