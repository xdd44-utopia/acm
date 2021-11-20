#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string line1[30001];
string line2[30001];
int idx[30001];
int arr[30001];
int temp[30001];

bool compare(int i, int j) {
	return line1[i].compare(line1[j]) < 0;
}

int bisearch(int target, int l, int r) {
	if (l == r) {
		return l;
	}
	int mid = (l+r)/2;
	int result = line1[idx[mid]].compare(line2[target]);
	if (result == 0) {
		return mid;
	}
	else if (result > 0) {
		return bisearch(target, l, mid);
	}
	else {
		return bisearch(target, mid+1, r);
	}
}

int merge(int l, int r) {
	if (l == r) {
		return 0;
	}
	if (l == r - 1) {
		if (arr[l] < arr[r]) {
			return 0;
		}
		else {
			int t = arr[r];
			arr[r] = arr[l];
			arr[l] = t;
			return 1;
		}
	}
	int mid = (l+r)/2;
	int result = merge(l, mid) + merge(mid+1, r);
	int pl = l;
	int pr = mid + 1;
	for (int i=l;i<=r;i++){
		temp[i] = arr[i];
	}
	while (pl <= mid || pr <= r) {
		while (pl <= mid && (pr > r || temp[pl] < temp[pr])) {
			arr[pl + pr - (mid + 1)] = temp[pl];
			pl++;
		}
		while (pr <= r && (pl > mid || temp[pl] > temp[pr])) {
			arr[pl + pr - (mid + 1)] = temp[pr];
			result += mid - pl + 1;
			pr++;
		}
	}
	return result;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i=0;i<n;i++) {
			cin >> line1[i];
		}
		for (int i=0;i<n;i++) {
			cin >> line2[i];
		}
		for (int i=0;i<n;i++) {
			idx[i] = i;
		}
		sort(idx, idx+n, compare);
		for (int i=0;i<n;i++) {
			arr[i] = idx[bisearch(i, 0, n-1)];
		}
		cout << merge(0, n-1) << endl;
	}
}
