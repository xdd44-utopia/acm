#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	Edge(int s, int t, long long w) {
		from = s;
		to = t;
		weight = w;
	}
	int from, to;
	long long weight;
	bool used = false;
};

int n, m;
int father[2000];
vector<Edge> edges;

int find(int i) {
	int p = father[i];
	while (p != father[p]) {
		p = father[p];
	}
	father[i] = p;
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

bool compare(const Edge& a, const Edge& b) {
	return a.weight < b.weight;
}

int main() {
	while (cin >> n >> m) {
		if (n == 0) {
			break;
		}
		for (int i=0;i<n;i++) {
			father[i] = i;
		}
		edges.clear();
		for (int i=0;i<m;i++) {
			int s, t;
			long long w;
			cin >> s >> t >> w;
			Edge te(s, t, w);
			edges.push_back(te);
		}
		sort(edges.begin(), edges.end(), compare);
		long long ans = 0;
		int cnt = 0;
		for (int i=0;i<m;i++) {
			if (join(edges[i].from, edges[i].to)){
				cnt ++;
				ans += edges[i].weight;
				edges[i].used = true;
			}
		}
		if (cnt == n - 1) {
			cout << "Min cost: " << ans << endl;
			bool printed = false;
			for (int i=0;i<m;i++) {
				if (!edges[i].used) {
					if (!printed) {
						printed = true;
					}
					else {
						cout << " ";
					}
					cout << edges[i].weight;
				}
			}
			cout << endl;
		}
		else {
			cout << "\\(^o^)/ pray to god" << endl;
		}
	}
	return 0;
}
