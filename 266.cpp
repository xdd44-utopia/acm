#include <iostream>

using namespace std;

bool fl[101][101];

int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					fl[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			fl[x][y] = 1;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (fl[i][k] && fl[k][j]) {
						fl[i][j] = 1;
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (fl[i][j] || fl[j][i]) {
					sum++;
				}
			}
			if (sum == n - 1) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}