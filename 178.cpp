#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 5005
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap, ll flow) :u(u), v(v), cap(cap), flow(flow) {}
};

vector<Edge> edges;
vector<int> graph[MAXN];
int level[MAXN];
int cur[MAXN];
int src, sink;

void addEdge(int from, int to, ll cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	ll m = edges.size();
	graph[from].push_back(m - 2);
	graph[to].push_back(m - 1);
}

bool genLevel() {
	bool reached = false;
	memset(level, -1, sizeof(int)*MAXN);
	level[src] = 0;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int current = q.front();
		if (current == sink) {
			reached = true;
			break;
		}
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			Edge ed = edges[graph[current][i]];
			if (level[ed.v] < 0 && ed.flow < ed.cap) {
				level[ed.v] = level[current] + 1;
				q.push(ed.v);
			}
		}
	}
	return reached;
}

ll findPath(int pos, ll limit) {
	if (pos == sink || limit == 0) {
		return limit;
	}
	ll totalAdd = 0;
	ll addFlow;
	for (int &i = cur[pos]; i < graph[pos].size(); i++) {
		Edge &ed = edges[graph[pos][i]];
		if (level[pos] + 1 == level[ed.v] && ed.cap > ed.flow) {
			addFlow = findPath(ed.v, limit < (ed.cap - ed.flow) ? limit : (ed.cap - ed.flow));
			if (addFlow > 0) {
				ed.flow += addFlow;
				edges[graph[pos][i] ^ 1].flow -= addFlow;
				totalAdd += addFlow;
				limit -= addFlow;
				
				if (limit == 0) {
					break;
				}
			}
		}
	}
	return totalAdd;
}

int main() {
	
	int n, m;
	while (cin >> n >> m) {
		if (n == 0) {
			break;
		}
		edges.clear();
		for (int i=0;i<MAXN;i++) {
			graph[i].clear();
		}
		
		int target = 0;
		
		src = 0;
		sink = n + m + 1;
		for (int i=1;i<=m;i++) {
			addEdge(0, i, 1);
		}
		for (int i=1;i<=n;i++) {
			int t;
			cin >> t;
			target += t;
			addEdge(m + i, sink, t);
		}
		for (int i=1;i<=m;i++) {
			int t;
			cin >> t;
			for (int j=0;j<t;j++) {
				int d;
				cin >> d;
				addEdge(i, m + d, 1);
			}
		}
		
		ll sum = 0;
		
		while (genLevel()) {
			memset(cur, 0, sizeof(int) * MAXN);
			sum += findPath(src, INF);
		}
		
		cout << (sum == target ? 1 : 0) << endl;
	}
	
	return 0;
}
