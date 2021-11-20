#include <iostream>
#include <cstring>

using namespace std;

int main() {
	unsigned long long a, b;
	while (cin >> a >> b) {
		bool aa[100];
		bool bb[100];
		memset(aa, 0, sizeof(bool) * 100);
		memset(bb, 0, sizeof(bool) * 100);
		int pos = 0;
		while (a > 0 || b > 0) {
			aa[pos] = a % 2;
			bb[pos] = b % 2;
			a /= 2;
			b /= 2;
			pos++;
		}
		bool isDiff = false;
		unsigned long long ans = 0;
		for (int i = 99; i >= 0; i--) {
			if (aa[i] != bb[i]) {
				isDiff = true;
			}
			if (isDiff) {
				ans += 1LL << i;
			}
			else {
				ans += aa[i] * (1LL << i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
