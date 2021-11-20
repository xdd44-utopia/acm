#include <iostream>
#include <cstring>

using namespace std;

struct Cruise {
	int arrive;
	int pn;
	int* passNa;
};

int cnt[100005];
Cruise cruises[100005];

int main() {
	
	memset(cnt, 0, sizeof(cnt));
	cruises[0].arrive = 0;
	cruises[0].pn = 0;
	
	int n;
	int pointer = 0;
	int ans = 0;
	
	cin >> n;
	
	for (int i=1;i<=n;i++) {
		cin >> cruises[i].arrive >> cruises[i].pn;
		if (cruises[i].pn > 0) {
			cruises[i].passNa = new int[cruises[i].pn];
		}
		for (int j=0;j<cruises[i].pn;j++) {
			cin >> cruises[i].passNa[j];
			cnt[cruises[i].passNa[j]]++;
			if (cnt[cruises[i].passNa[j]] == 1) {
				ans++;
			}
		}
		while (cruises[i].arrive - cruises[pointer].arrive >= 86400) {
			for (int j=0;j<cruises[pointer].pn;j++) {
				cnt[cruises[pointer].passNa[j]]--;
				if (cnt[cruises[pointer].passNa[j]] == 0) {
					ans--;
				}
			}
			pointer++;
		}
		cout << ans << endl;
	}
	
	return 0;
}
