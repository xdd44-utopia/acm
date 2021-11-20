#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	Edge(int s, int t, int w) {
		from = s;
		to = t;
		weight = w;
	}
	int from, to, weight;
};

int n, m;
int father[200];
vector<Edge> edges;

int find(int i) {
	int p = father[i];
	while (p != father[p]) {
		p = father[p];
	}
	return p;
}

bool join(int i, int j) {
	int fi = find(i);
	int fj = find(j);
	if (fi != fj) {
		father[fi] = fj;
		return true;
	}
	else {
		return false;
	}
}

int span(int l) {
	int cnt = 0;
	for (int i=0;i<n;i++) {
		father[i] = i;
	}
	for (int i=l;i<m;i++) {
		if (join(edges[i].from, edges[i].to)){
			cnt++;
		}
		if (cnt == n - 1){
			return edges[i].weight - edges[l].weight;
		}
	}
	return -1;
}

bool compare(const Edge& a, const Edge& b) {
	return a.weight < b.weight;
}

int main() {
	while (cin >> n >> m) {
		if (n == 0) {
			break;
		}
		edges.clear();
		for (int i=0;i<m;i++) {
			int s, t, w;
			cin >> s >> t >> w;
			s--;
			t--;
			Edge te(s, t, w);
			edges.push_back(te);
		}
		sort(edges.begin(), edges.end(), compare);
		int ans = 2147483647;
		for (int i=0;i<m;i++) {
			int result = span(i);
			if (result >= 0 && result < ans) {
				ans = result;
			}
		}
		cout << (ans < 2147483647 ? ans : -1) << endl;
	}
	return 0;
}
