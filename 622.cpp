#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int sa[2000];

void suff(int* arr, int n) {
	int m = 2000;
	int* dir = new int[m];
	int* x = new int[n];
	int* y = new int[n];
	memset(dir, 0, sizeof(int) * m);
	for (int i = 0; i < n; i++) {
		x[i] = arr[i];
		dir[arr[i]]++;
	}
	for (int i = 1; i < m; i++) {
		dir[i] += dir[i - 1];
	}
	for (int i = n - 1; i >= 0; i--) {
		sa[--dir[x[i]]] = i;
	}


	for (int k = 1; k <= n; k <<= 1) {
		int pos = 0;
		for (int i = n - k; i < n; i++) {
			y[pos++] = i;
		}
		for (int i = 0; i < n; i++) {
			if (sa[i] >= k) {
				y[pos++] = sa[i] - k;
			}
		}

		memset(dir, 0, sizeof(int) * m);
		for (int i = 0; i < n; i++) {
			dir[x[y[i]]]++;
		}
		for (int i = 1; i < m; i++) {
			dir[i] += dir[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			sa[--dir[x[y[i]]]] = y[i];
		}

		int* t = x; x = y; y = t;
		pos = 1;
		x[sa[0]] = 0;
		for (int i = 0; i < n; i++) {
			x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? pos - 1 : pos++;
		}

	}

	delete[] x;
	delete[] y;
	delete[] dir;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int len = str.length();
		int* arr = new int[len + 1];
		for (int j = 0; j < len; j++) {
			switch (str[j]) {
				case 'A':
					arr[j] = 1;
					break;
				case 'C':
					arr[j] = 2;
					break;
				case 'G':
					arr[j] = 3;
					break;
				case 'T':
					arr[j] = 4;
					break;
			}
		}
		arr[len] = 0;
		suff(arr, len);

		int maxLen = 0;
		int maxCnt = 1;
		int maxPos = 0;
		bool conti = false;
		for (int i = 0; i < len - 1; i++) {
			int posi = sa[i];
			int posj = sa[i + 1];
			int commonLen = 0;
			while (arr[posi] == arr[posj]) {
				commonLen++;
				posi++;
				posj++;
				if (posi == len || posj == len) {
					break;
				}
			}
			if (commonLen > maxLen) {
				maxPos = sa[i];
				maxCnt = 2;
				maxLen = commonLen;
				conti = true;
			}
			else if (commonLen == maxLen && conti) {
				maxCnt++;
			}
			else {
				conti = false;
			}
		}

		if (maxCnt < 2) {
			cout << "No repetitions found!" << endl;
		}
		else {
			for (int i = maxPos; i < maxPos + maxLen; i++) {
				switch (arr[i]) {
				case 1:
					cout << 'A';
					break;
				case 2:
					cout << 'C';
					break;
				case 3:
					cout << 'G';
					break;
				case 4:
					cout << 'T';
					break;
				}
			}
			cout << " " << maxCnt << endl;
		}

		delete[] arr;
	}

	return 0;
}