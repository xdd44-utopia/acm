#include <iostream>
#include <queue>
#include <cstring>

bool stored[1005];

using namespace std;

int main() {
	
	memset(stored, 0, sizeof(stored));
	queue<int> q;
	int m, n;
	cin >> m >> n;
	
	int ans = 0;
	
	for (int i=0;i<n;i++){
		int t;
		cin >> t;
		if (!stored[t]) {
			ans++;
			stored[t] = true;
			q.push(t);
			if (q.size() > m) {
				stored[q.front()] = false;
				q.pop();
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
