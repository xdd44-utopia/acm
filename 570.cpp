#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int cnt;
int l[1000];
int r[1000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int len = str.length();
		int sum = 0;
		for (int j = 0; j < len; j++) {
			if (str[j] <= 'N') {
				sum += (str[j] - 'A');
			}
			else {
				sum += 26 - (str[j] - 'A');
			}
		}

		bool currentA = false;
		cnt = 0;
		for (int j = 1; j < len; j++) {
			if (!currentA && str[j] == 'A') {
				l[cnt] = j - 1;
				currentA = true;
			}
			if (currentA && str[j] != 'A') {
				r[cnt++] = j;
				currentA = false;
			}
			if (currentA && j == len - 1) {
				r[cnt++] = j + 1;
				currentA = false;
			}
		}

		int ans = sum + len - 1;

		//cout << cnt << endl;
		for (int j = 0; j < cnt; j++)
		{
			//cout << sum + l[j] * 2 + len - r[j] << " " << sum + (len - r[j]) * 2 + l[j] << endl;
			ans = min(ans, min(sum + l[j] * 2 + len - r[j], sum + (len - r[j]) * 2 + l[j]));
		}

		cout << ans << endl;
	}
	return 0;
}