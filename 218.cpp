#include <iostream>

using namespace std;

int main() {
	int caseNum;
	cin >> caseNum;
	while (caseNum--) {
		int n;
		cin >> n;
		int* p = new int[n];
		int* w = new int[n];
		for (int i=0;i<n;i++) {
			cin >> p[i] >> w[i];
		}
		int g;
		cin >> g;
		int* v = new int[g];
		int maxv = 0;
		for (int i=0;i<g;i++) {
			cin >> v[i];
			maxv = maxv > v[i] ? maxv : v[i];
		}
		
		int f[2000][50];
		for (int i=0;i<=maxv;i++) {
			if (i - w[0] >= 0) {
				f[0][i] = p[0];
			}
			else {
				f[0][i] = 0;
			}
		}
		for (int i=1;i<n;i++) {
			f[i][0] = 0;
			for (int j=1;j<=maxv;j++) {
				f[i][j] = f[i-1][j];
				if (j - w[i] >= 0 && f[i-1][j-w[i]] + p[i] > f[i][j]) {
					f[i][j] = f[i-1][j-w[i]] + p[i];
				}
			}
		}
		
		int ans = 0;
		for (int i=0;i<g;i++) {
			ans += f[n-1][v[i]];
		}
		
		cout << ans << endl;
		
		delete[] p;
		delete[] w;
		delete[] v;
	}
	return 0;
}
