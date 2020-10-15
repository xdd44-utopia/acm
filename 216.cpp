#include<iostream>
#include<string>

using namespace std;

int main() {
	string str1, str2;
	while (getline(cin, str1)) {
		getline(cin, str2);
		str1 = ' ' + str1;
		str2 = ' ' + str2;
		int len1 = str1.length();
		int len2 = str2.length();
		int** f = new int* [len1];
		for (int i = 0; i < len1; i++) {
			f[i] = new int[len2];
			for (int j = 0; j < len2; j++) {
				f[i][j] = 0;
			}
		}

		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (str1[i] == str2[j]) {
					f[i][j] = f[i - 1][j - 1] + 1;
				}
				else {
					f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
				}
			}
		}

		cout << f[len1 - 1][len2 - 1] << endl;

		for (int i = 0; i < len1; i++) {
			delete[] f[i];
		}
		delete[] f;
	}

	return 0;
}