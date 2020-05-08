#include<iostream>

using namespace std;

int ans[15][3];

int calc(int n, int from, int to, int pass) {
	if (ans[n][abs(from - to)] > 0) {
		return ans[n][abs(from - to)];
	}
	else {
		int sum = 0;
		if (pass == 1) {
			sum += ans[n - 1][2] > 0 ? ans[n - 1][2] : calc(n - 1, from, to, pass);
			sum ++;
			sum += ans[n - 1][2] > 0 ? ans[n - 1][2] : calc(n - 1, to, from, pass);
			sum ++;
			sum += ans[n - 1][2] > 0 ? ans[n - 1][2] : calc(n - 1, from, to, pass);
		}
		else {
			sum += ans[n - 1][abs(from - pass)] > 0 ? ans[n - 1][abs(from - pass)] : calc(n - 1, from, pass, to);
			sum += abs(from - to);
			sum += ans[n - 1][abs(pass - to)] > 0 ? ans[n - 1][abs(pass - to)] : calc(n - 1, pass, to, from);
		}
		ans[n][abs(from - to)] = sum;
		return sum;
	}
}

int main() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 3; j++) {
			ans[i][j] = -1;
		}
	}
	ans[1][1] = 1;
	ans[1][2] = 2;
	int n;
	while (cin >> n) {
		cout << calc(n, 0, 2, 1) << endl;
	}
	return 0;
}