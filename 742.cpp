#include<iostream>
#include<string>

using namespace std;

bool** map;

bool check(int x, int y, int range) {
	if (map[x][y]) {
		bool b = true;
		for (int i = x; i < x + range; i++) {
			for (int j = y; j < y + range; j++) {
				b = b & map[i][j];
				if (!b) {
					return false;
				}
			}
		}
	}
	else {
		bool b = false;
		for (int i = x; i < x + range; i++) {
			for (int j = y; j < y + range; j++) {
				b = b | map[i][j];
				if (b) {
					return false;
				}
			}
		}
	}
	return true;
}

int quad(int x, int y, int range) {
	int count = 1;

	if (range == 1) {
		return count;
	}

	if (!check(x, y, range)) {
		count += quad(x, y, range / 2);
		count += quad(x + range / 2, y, range / 2);
		count += quad(x, y + range / 2, range / 2);
		count += quad(x + range / 2, y + range / 2, range / 2);
	}

	return count;
}

int main() {
	int n;
	while (cin >> n) {
		n = 1 << n;
		map = new bool*[n];
		for (int i = 0; i < n; i++) {
			map[i] = new bool[n];
		}
		for (int i = 0; i < n; i++) {
			string s = "";
			while (s == "" || s == "\n") {
				cin >> s;
			}
			for (int j = 0; j < n; j++) {
				map[i][j] = (s[j] == '1') ? 1 : 0;
			}
		}

		cout << quad(0, 0, n) << endl;

		for (int i = 0; i < n; i++) {
			delete[] map[i];
		}
		delete[] map;
	}
	return 0;
}