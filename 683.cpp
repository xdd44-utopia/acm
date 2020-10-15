#include <iostream>

using namespace std;

int main() {
	int k, a, b, v;
	while (cin >> k >> a >> b >> v) {
		int ans = 0;
		while (a > 0) {
			int cap = v;
			int usedDiv = 0;
			while (b > 0 && usedDiv < k - 1) {
				b--;
				cap += v;
				usedDiv++;
			}
			a -= cap;
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}