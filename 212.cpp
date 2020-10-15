#include <iostream>
#include <cstring>

using namespace std;

long long rmd[33];
bool isNeeded[33];

int main() {

	long long b, p, m;
	while (cin >> b >> p >> m){

		rmd[1] = b % m;
		for (int i = 2; i < 33; i++) {
			rmd[i] = (rmd[i - 1] * rmd[i - 1]) % m;
		}

		for (int i = 1; i < 33; i++) {
			isNeeded[i] = p % 2;
			p /= 2;
		}

		long long ans = 1;
		for (int i = 1; i < 33; i++) {
			if (isNeeded[i]) {
				ans *= rmd[i];
				ans %= m;
			}
		}

		cout << ans << endl;
	}

	return 0;

}