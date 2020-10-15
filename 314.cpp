#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len[200005];
string line;
using namespace std;
int main() {
	int ans;
	while (cin >> line) {
		int l = line.length();
		int p, q, r;
		len[0] = 1;
		for (int i = 1, j = 0; i < (l << 1) - 1; i++) {
			p = i >> 1, q = i - p, r = ((j + 1) >> 1) + len[j] - 1;
			len[i] = r < q ? 0 : min(r - q + 1, len[(j << 1) - i]);
			while (p > len[i] - 1 && q + len[i] < l && line[p - len[i]] == line[q + len[i]])
				len[i]++;
			if (q + len[i] - 1 > r)
				j = i;
		}
		ans = l - 1;
		int j = l - 1;
		for (int i = l - 2; i >= 0; i--) {
			if (len[i + j] >= (j - i) / 2 + 1) {
				ans = i;
			}
		}
		cout << line;
		for (int i = ans - 1; i >= 0; i--) {
			cout << line[i];
		}
		cout << endl;

		for (int i = 1, j = 0; i < (l << 1) - 1; i++) {
			cout << len[i];
		}
		cout << endl;
	}
}
