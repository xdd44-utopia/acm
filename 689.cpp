#include <iostream>
#include <cstring>
#define MAXN 1000001

using namespace std;

int f[MAXN];
int arr[MAXN];

int search(int l, int r, int x) {
	if (l == r) {
		return l;
	}
	else {
		int mid = (l + r) / 2;
		if (x < f[mid]) {
			return search(l, mid, x);
		}
		else {
			return search(mid + 1, r, x);
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		memset(f, 0, sizeof(f));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		f[cnt++] = arr[0];
		for (int i = 1; i < n; i++) {
			if (f[cnt - 1] <= arr[i]) {
				f[cnt++] = arr[i];
			}
			else {
				f[search(0, cnt - 1, arr[i])] = arr[i];
			}
		}
		cout << cnt << endl;
	}
	return 0;
}