#include <iostream>
#define MAXN 101
#define INF 1000000000

using namespace std;

int map[MAXN][MAXN];
int n, m;

int main() {

	while (cin >> n >> m) {
		for (int i = 0; i < MAXN; i++) {
			for (int j = 0; j < MAXN; j++) {
				map[i][j] = (i == j ? 0 : INF);
			}
		}

		for (int i = 0; i < m; i++) {
			int x, y, t;
			cin >> x >> y >> t;
			x--; y--;
			map[x][y] = t;
			map[y][x] = t;
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (map[i][k] < INF && map[k][j] < INF && map[i][k] + map[k][j] < map[i][j]) {
						map[i][j] = map[i][k] + map[k][j];
						map[j][i] = map[i][k] + map[k][j];
					}
				}
			}
		}
		
		int ans = 2147483647;
		int ansI = 0;
		int sum;
		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0; j < n; j++) {
				sum += map[i][j];
			}
			if (ans > sum) {
				ans = sum;
				ansI = i;
			}
		}
		cout << ansI + 1 << endl;
	}
	return 0;
}