#include<iostream>
#include<stack>
using namespace std;

int* arr;
int* sample;
int* idx;

bool check(int n) {
	for (int i = 0; i < n; i++) {
		int base = sample[i];
		int come = base;
		for (int j = i + 1; j < n; j++) {
			if (sample[j] > base) {
				if (sample[j] < come) {
					return false;
				}
				else {
					come = sample[j];
				}
			}
		}
	}
	return true;
}

void print(int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << idx[i] << " ";
	}
	cout << endl;
}

int search(int x, int s, int t) {
	if (s == t) {
		if (arr[s] == x) {
			return s;
		}
	}
	else {
		int mid = (s + t) / 2;
		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] > x) {
			return search(x, s, mid);
		}
		else {
			return search(x, mid + 1, t);
		}
	}
}

void merge(int s, int t) {
	if (s < t) {
		int mid = (s + t) / 2;
		merge(s, mid);
		merge(mid + 1, t);
		int* tmp = new int[t - s + 1];
		int* ti = new int[t - s + 1];
		for (int i = 0; i < t - s + 1; i++) {
			tmp[i] = arr[i + s];
			ti[i] = idx[i + s];
		}
		int pos = s;
		int i = 0;
		int j = mid - s + 1;
		while (pos <= t) {
			if (j > t - s || (i <= mid - s && tmp[i] <= tmp[j])) {
				arr[pos] = tmp[i];
				idx[pos] = ti[i];
				pos++;
				i++;
			}
			else if (i > mid - s || (j <= t - s && tmp[j] < tmp[i])) {
				arr[pos] = tmp[j];
				idx[pos] = ti[j];
				pos++;
				j++;
			}
		}
		delete[] tmp;
		delete[] ti;
	}
}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		int n;
		cin >> n;
		arr = new int[n];
		idx = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			idx[i] = i;
		}
		merge(0, n - 1);

		int m;
		cin >> m;
		for (int ct = 0; ct < m; ct++) {
			sample = new int[n];
			for (int i = 0; i < n; i++) {
				int t;
				cin >> t;
				sample[i] = idx[search(t, 0, n-1)];
			}
			if (check(n)) {
				cout << "Aye\n";
			}
			else {
				cout << "Impossible\n";
			}
			delete[] sample;
		}
		delete[] arr;
	}
	return 0;
}