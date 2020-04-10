#include<iostream>
#include<cstring>
#include<string>
#include<bitset>
using namespace std;

int sample[101];
int len, n;
int ma;

void print() {
	cout << "print:\n";
	for (int i = 0; i < n; i++) {
		bitset<32> t(sample[i]);
		cout << t << endl;
	}
}

void calc() {
	int ans = 0;
	int t[101];
	memcpy(t, sample, sizeof(sample));
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < len; j++) {
			count += (t[i] & 1);
			t[i] = t[i] >> 1;
		}
		ans += count > (len - count) ? count : (len - count);
	}
	if (ans > ma) {
		ma = ans;
	}
}

void enu(int dep) {
	if (dep == len) {
		calc();
	}
	else {
		for (int c = 0; c < 2; c++) {
			if (c) {
				enu(dep + 1);
			}
			else {
				for (int i = 0; i < n; i++) {
					sample[i] = sample[i] ^ (1 << dep);
				}
				enu(dep + 1);
				for (int i = 0; i < n; i++) {
					sample[i] = sample[i] ^ (1 << dep);
				}
			}
		}
	}
}

int main() {
	while (cin >> n >> len) {
		memset(sample, 0, sizeof(sample));
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < len; j++) {
				sample[i] = (sample[i] << 1) + (str[j] == '1' ? 1 : 0);
			}
		}
		ma = 0;
		enu(0);
		cout << ma << endl;
	}
	return 0;
}