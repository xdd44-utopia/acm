#include <iostream>
#include <vector>
#define MAXN 35
#define DD 1000000007
typedef long long ll;

using namespace std;

vector<ll> f[35];
ll n, m;

void init() {
	for (int i = 0; i < MAXN; i++) {
		f[i].clear();
	}
}

int main() {

	while (cin >> n >> m) {
		n -= n % m;
		init();
		if (m == 1) {
			cout << "1\n";
			continue;
		}
		for (int i = 0; i <= n / m; i++) {
			f[1].push_back((ll)(i + 1));
		}
		ll power = m * m;
		int dep = 2;
		while (n / power > 0) {
			f[dep].push_back(f[dep - 1][(n - (n / power) * power) / (power / m)]);
			
			for (int i = 1; i <= n / power; i++) {
				f[dep].push_back((f[dep][i - 1] + f[dep - 1][(n - ((n / power) - i) * power) / (power / m)]) % DD);
			}
			power *= m;
			dep++;
		}
		dep--;
		cout << f[dep][f[dep].size() - 1] << endl;
		/*
		for (int i = 1; i <= dep; i++) {
			for (int j = 0; j < f[i].size(); j++) {
				cout << f[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	return 0;
}