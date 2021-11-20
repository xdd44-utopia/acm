#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, c;
	
	while (cin >> n >> c) {
		int* arr = new int[n];
		
		for (int i=0;i<n;i++) {
			cin >> arr[i];
		}
		
		sort(arr, arr + n);
		
		vector<int> idx;
		vector<int> cnt;
		
		int l = 0;
		int r = 0;
		do {
			l = r;
			while (r < n && arr[l] == arr[r]) {
				r++;
			}
			idx.push_back(arr[l]);
			cnt.push_back(r - l);
		} while (r < n);
		
		n = (int)idx.size();
		
		long long ans = 0;
		
		if (c == 0) {
			for (int i=0;i<n;i++) {
				ans += (long long)cnt[i] * (long long)cnt[i];
			}
		}
		else {
			if (c < 0) {
				c = -c;
			}
			bool done = false;
			int prev = 1;
			for (int i = 0;i<n-1;i++) {
				for (int j=prev;j<n;j++) {
					if (idx[j] - idx[i] == c) {
						ans += (long long)cnt[i] * (long long)cnt[j];
						prev = j;
						break;
					}
					else if (j == n - 1 && idx[j] - idx[i] < c) {
						done = true;
						prev = j;
						break;
					}
					else if (idx[j] - idx[i] > c) {
						prev = j;
						break;
					}
				}
				if (done) {
					break;
				}
			}
		}
		
		cout << ans << endl;
		
		delete[] arr;
	}
	
	return 0;
}
