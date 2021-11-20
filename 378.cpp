#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
	int dist;
	int cnt;
	int level;
	int visited = false;
	vector<int> edges;
	vector<int> lens;
};

Node nodes[1000];

class Compare {
public:
	bool operator()(int a, int b) {
		return nodes[a].dist > nodes[b].dist;
	}
};

int main() {
	
	freopen("/Users/xdd44/Documents/Code/378/test.in", "r", stdin);
	
	int m, n;
	while (cin >> m >> n) {
		int minLevel = 2147483647;
		int maxLevel = -1;
		for (int i=0;i<=n;i++) {
			nodes[i].cnt = 0;
			nodes[i].edges.clear();
			nodes[i].lens.clear();
		}
		for (int i=0;i<n;i++) {
			int p, l, k;
			cin >> p >> l >> k;
			nodes[n].cnt++;
			nodes[n].edges.push_back(i);
			nodes[n].lens.push_back(p);
			nodes[i].level = l;
			minLevel = minLevel < l ? minLevel : l;
			maxLevel = maxLevel > l ? maxLevel : l;
			for (int j=0;j<k;j++) {
				int t, c;
				cin >> t >> c;
				t--;
				nodes[t].cnt++;
				nodes[t].edges.push_back(i);
				nodes[t].lens.push_back(c);
			}
		}
		int ans = 2147483647;
		for (int lower = minLevel; lower <= maxLevel - m; lower ++) {
			for (int i=0;i<=n;i++) {
				nodes[i].dist = 2147483647;
				nodes[i].visited = false;
			}
			nodes[n].dist = 0;
			priority_queue<int, vector<int>, Compare> pq;
			pq.push(n);
			while (!pq.empty()) {
				int cur = pq.top();
				pq.pop();
				if (cur == 0) {
					ans = ans < nodes[cur].dist ? ans : nodes[cur].dist;
					break;
				}
				else if (!nodes[cur].visited) {
					nodes[cur].visited = true;
					for (int i=0;i<nodes[cur].cnt;i++) {
						int nex = nodes[cur].edges[i];
						int dis = nodes[cur].lens[i];
						if (nodes[nex].level >= lower && nodes[nex].level <= lower + m && nodes[nex].dist > nodes[cur].dist + dis) {
							nodes[nex].dist = nodes[cur].dist + dis;
							pq.push(nex);
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
