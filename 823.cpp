#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Word {
	string w;
	int cnt = 0;
};

Word dict[1005];
string essay[100005];

bool compare(const Word& a, const Word& b) {
	return (a.w.compare(b.w) < 0);
}

int bisearch(const string& str, int l, int r) {
	if (l == r) {
		return l;
	}
	else {
		int mid = (l + r) / 2;
		if (str.compare(dict[mid].w) == 0){
			return mid;
		} else if (str.compare(dict[mid].w) < 0) {
			return bisearch(str, l, mid);
		}
		else {
			return bisearch(str, mid + 1, r);
		}
	}
}

int main(){

	int n, m;
	while (cin >> n) {
		for (int i=0;i<n;i++) {
			cin >> dict[i].w;
			dict[i].cnt = 0;
		}
		
		sort(dict, dict + n, compare);
		
		cin >> m;
		int appear = 0;
		for (int i=0;i<m;i++) {
			cin >> essay[i];
			int find = bisearch(essay[i], 0, n - 1);
			if (dict[find].w.compare(essay[i]) == 0) {
				dict[find].cnt++;
				if (dict[find].cnt == 1) {
					appear++;
				}
			}
		}
		
		if (appear == 0) {
			cout << "0\n0\n";
		}
		else {
			for (int i=0;i<n;i++) {
				dict[i].cnt = 0;
			}
			
			int l = 0;
			int r = 0;
			int quality = 0;
			int ans = 2147483647;
			do {
				while (quality < appear && r < m) {
					int find = bisearch(essay[r], 0, n - 1);
					if (dict[find].w.compare(essay[r]) == 0) {
						dict[find].cnt++;
						if (dict[find].cnt == 1) {
							quality++;
						}
					}
					r++;
				}
				while (quality == appear && l < r) {
					ans = (ans < r - l ? ans : r - l);
					int find = bisearch(essay[l], 0, n - 1);
					if (dict[find].w.compare(essay[l]) == 0) {
						dict[find].cnt--;
						if (dict[find].cnt == 0) {
							quality--;
						}
					}
					l++;
				}
			} while (r < m);
			
			cout << appear << endl << ans << endl;
		}
		
	}

	return 0;
}
