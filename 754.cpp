#include<iostream>
#include<algorithm>
using namespace std;

int n, cus;
int* arr;
int ans;

bool check(int trial) {
	int count = cus;
	int pos = 0;
	int previous;
	while (count > 0) {
		if (pos == n) {
			return false;
		}
		count--;
		previous = arr[pos];
		while (arr[pos] - previous < trial) {
			pos++;
		}
	}
	return true;
}

void biSearch(int bg, int ed) {
	int mid = (bg + ed) / 2;
	bool check1 = check(mid);
	bool check2 = check(mid + 1);
	if (check1 && !check2) {
		ans = mid;
	}
	else if (check2) {
		biSearch(mid + 1, ed);
	}
	else {
		biSearch(bg, mid);
	}
}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		int maxi = 0;
		int mini = 2147483647;
		cin >> n >> cus;
		arr = new int[n+1];
		arr[n] = 2147483647;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			maxi = arr[i] > maxi ? arr[i] : maxi;
			mini = arr[i] < mini ? arr[i] : mini;
		}
		sort(arr, arr + n);

		ans = -1;
		biSearch(0, maxi - mini);
		cout << ans << endl;

		delete[] arr;
	}

	return 0;
}