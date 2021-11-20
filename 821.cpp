#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int childCnt = 0;
	long long dist = -1;
	vector<int> child;
	vector<int> edge;
	
	void addChild(int x, int l) {
		childCnt++;
		child.push_back(x);
		edge.push_back(l);
	}
	
};

Node tree[100005];
long long maxLen = 0;
int maxPos = 0;

void dfs(int pos) {
	for (int i=0;i<tree[pos].childCnt;i++) {
		int p = tree[pos].child[i];
		int d = tree[pos].edge[i];
		if (tree[p].dist == -1) {
			tree[p].dist = tree[pos].dist + (long long)d;
			if (maxLen < tree[p].dist) {
				maxLen = tree[p].dist;
				maxPos = p;
			}
			dfs(p);
		}
	}
}

int main() {
	
	int n;
	cin >> n;
	
	for (int i=0;i<n-1;i++) {
		int s, t, d;
		cin >> s >> t >> d;
		tree[s].addChild(t, d);
		tree[t].addChild(s, d);
	}
	
	tree[1].dist = 0;
	dfs(1);
	
	for (int i=1;i<=n;i++) {
		tree[i].dist = -1;
	}
	
	int start = maxPos;
	tree[start].dist = 0;
	dfs(start);
	
	cout << maxLen << endl;
	
	return 0;
}
