#include<iostream>
#include<cstring>

using namespace std;

bool check[25][25][25][25];

int main() {
	int v[4];
	int target;
	while (cin >> v[0] >> v[1] >> v[2] >> v[3] >> target) {
		int queue[100000];
		int dep[100000];
		bool getit = false;
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 25; j++) {
				for (int k = 0; k < 25; k++) {
					for (int l = 0; l < 25; l++) {
						check[i][j][k][l] = 0;
					}
				}
			}
		}
		check[0][0][0][0] = true;
		memset(dep, 0, sizeof(dep));
		int head = 0;
		int tail = 4;
		for (int i = 0; i < 4; i++) {
			dep[i] = 1;
		}
		queue[0] = v[0] * 1000000;
		queue[1] = v[1] * 10000;
		queue[2] = v[2] * 100;
		queue[3] = v[3];

		while (head < tail) {
			int t[4] = { queue[head] / 1000000, (queue[head] % 1000000) / 10000, (queue[head] % 10000) / 100, queue[head] % 100 };

			if (t[0] == target || t[1] == target || t[2] == target || t[3] == target) {
				cout << dep[head] << endl;
				getit = true;
				break;
			}
			check[t[0]][t[1]][t[2]][t[3]] = true;
			if (!check[0][t[1]][t[2]][t[3]] && t[0] > 0) {
				check[0][t[1]][t[2]][t[3]] = true;
				queue[tail] = t[1] * 10000 + t[2] * 100 + t[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[t[0]][0][t[2]][t[3]] && t[1] > 0) {
				check[t[0]][0][t[2]][t[3]] = true;
				queue[tail] = t[0] * 1000000 + t[2] * 100 + t[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[t[0]][t[1]][0][t[3]] && t[2] > 0) {
				check[t[0]][t[1]][0][t[3]] = true;
				queue[tail] = t[0] * 1000000 + t[1] * 10000 + t[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[t[0]][t[1]][t[2]][0] && t[3] > 0) {
				check[t[0]][t[1]][t[2]][0] = true;
				queue[tail] = t[0] * 1000000 + t[1] * 10000 + t[2] * 100;
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[v[0]][t[1]][t[2]][t[3]] && t[0] < v[0]) {
				check[v[0]][t[1]][t[2]][t[3]] = true;
				queue[tail] = v[0] * 1000000 + t[1] * 10000 + t[2] * 100 + t[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[t[0]][v[1]][t[2]][t[3]] && t[1] < v[1]) {
				check[t[0]][v[1]][t[2]][t[3]] = true;
				queue[tail] = t[0] * 1000000 + v[1] * 10000 + t[2] * 100 + t[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[t[0]][t[1]][v[2]][t[3]] && t[2] < v[2]) {
				check[t[0]][t[1]][v[2]][t[3]] = true;
				queue[tail] = t[0] * 1000000 + t[1] * 10000 + v[2] * 100 + t[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			if (!check[t[0]][t[1]][t[2]][v[3]] && t[3] < v[3]) {
				check[t[0]][t[1]][t[2]][v[3]] = true;
				queue[tail] = t[0] * 1000000 + t[1] * 10000 + t[2] * 100 + v[3];
				dep[tail] = dep[head] + 1;
				tail++;
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (i != j && v[j] - t[j] > 0 && t[i] > 0) {
						int op[4];
						op[0] = t[0]; op[1] = t[1]; op[2] = t[2]; op[3] = t[3];
						if (t[i] > v[j] - t[j]) {
							op[i] -= v[j] - op[j];
							op[j] = v[j];
						}
						else {
							op[j] += op[i];
							op[i] = 0;
						}
						if (!check[op[0]][op[1]][op[2]][op[3]]) {
							check[op[0]][op[1]][op[2]][op[3]] = true;
							queue[tail] = op[0] * 1000000 + op[1] * 10000 + op[2] * 100 + op[3];
							dep[tail] = dep[head] + 1;
							tail++;
						}
					}
				}
			}
			head++;
		}
		if (!getit) {
			cout << -1 << endl;
		}
	}
	system("pause");
	return 0;
}