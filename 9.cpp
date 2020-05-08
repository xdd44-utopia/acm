#include<iostream>
#include<string>

using namespace std;

struct dpNode {
	string ans;
	int offset;
};

int f[25][25];
int op[25][25];
string a, b;

void init() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			f[i][j] = 0;
			op[i][j] = 0;
		}
	}
}

void output(int i, int j)
{
	if (!i && !j) return;
	if (op[i][j] == 1) {
		output(i - 1, j);
		cout << 'D' << a[i] << (j + 1 > 9 ? "" : "0") << j + 1;
	}
	else if (op[i][j] == 2) {
		output(i, j - 1);
		cout << 'I' << b[j] << (j > 9 ? "" : "0") << j;
	}
	else if (op[i][j] == 3) {
		output(i - 1, j - 1);
		cout << 'C' << b[j] << (j > 9 ? "" : "0") << j;
	}
	else output(i - 1, j - 1);
}

int main() {
	while (true) {
		cin >> a;
		if (a[0] == '#') {
			break;
		}
		cin >> b;
		a = ' ' + a;
		b = ' ' + b;
		init();
		for (int i = 1; i < a.length(); i++) {
			f[i][0] = f[i - 1][0] + 1;
			op[i][0] = 1;
		}
		for (int i = 1; i < b.length(); i++) {
			f[0][i] = f[0][i - 1] + 1;
			op[0][i] = 2;
		}
		for (int i = 1; i < a.length(); i++) {
			for (int j = 1; j < b.length(); j++) {
				if (a[i] == b[j]) {
					f[i][j] = f[i - 1][j - 1];
				}
				else {
					f[i][j] = f[i - 1][j - 1] + 1;
					op[i][j] = 3;
				}
				if (f[i - 1][j] + 1 < f[i][j]) {
					f[i][j] = f[i - 1][j] + 1;
					op[i][j] = 1;
				}
				if (f[i][j - 1] + 1 < f[i][j]) {
					f[i][j] = f[i][j - 1] + 1;
					op[i][j] = 2;
				}
			}
		}
		output(a.length(), b.length());
		cout << 'E' << endl;
	}
	return 0;
}
