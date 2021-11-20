#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int cnt;
	vector<int> edges;
};

Node doms[10000];
bool visited[10000];

void dfs(int pos) {
	if (!visited[pos]) {
		visited[pos] = true;
		for (int i=0;i<doms[pos].cnt;i++) {
			dfs(doms[pos].edges[i]);
		}
	}
}

int main() {
	
	int t;
	cin >> t;
	while (t--) {
		for (int i=0;i<10000;i++) {
			doms[i].cnt = 0;
			doms[i].edges.clear();
			visited[i] = false;
		}
		int n, m, l;
		cin >> n >> m >> l;
		for (int i=0;i<m;i++) {
			int s, t;
			cin >> s >> t;
			s--;
			t--;
			doms[s].cnt++;
			doms[s].edges.push_back(t);
		}
		for (int i=0;i<l;i++) {
			int s;
			cin >> s;
			s--;
			dfs(s);
		}
		int ans = 0;
		for (int i=0;i<n;i++) {
			ans += visited[i];
		}
		cout << ans << endl;
	}
	
	return 0;
}
