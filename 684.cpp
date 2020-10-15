#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 2100
#define INF 2147483647
using namespace std;
struct Edge {
	int u, v;
	int cap, flow;
	Edge() {}
	Edge(int u, int v, int cap, int flow) :u(u), v(v), cap(cap), flow(flow) {}
};

vector<Edge> edges;
vector<int> graph[MAXN];
int level[MAXN];
int cur[MAXN];
int src, sink;
bool counting = false;
int fireCnt;
bool isFired[MAXN];

void init() {
	edges.clear();
	for (int i = 0; i < MAXN; i++) {
		graph[i].clear();
	}
}

void addEdge(int from, int to, int cap) {
	edges.push_back(Edge(from, to, cap, 0));
	edges.push_back(Edge(to, from, 0, 0));
	int m = edges.size();
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

int findPath(int pos, int limit) {
	if (pos == sink || limit == 0) {
		return limit;
	}
	int totalAdd = 0;
	int addFlow;
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
	int n, m, k;
	while (cin >> n >> m >> k) {
		init();

		src = n + m + 1;
		sink = n + m + 2;

		addEdge(src, 0, 0);
		for (int i = 1; i < n; i++) {
			addEdge(src, i, 1);
		}
		addEdge(n, sink, 0);
		for (int i = 1; i < m; i++) {
			addEdge(n + i, sink, 1);
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			addEdge(x, n + y, INF);
		}

		int sum = 0;

		while (genLevel()) {
			memset(cur, 0, sizeof(int) * MAXN);
			sum += findPath(src, INF);
		}

		cout << sum << endl;
		/*
		for (int i = 0; i < graph[src].size(); i++) {
			cout << edges[graph[src][i]].flow << " ";
		}
		cout << endl;
		for (int i = n; i < n + m; i++) {
			cout << edges[graph[i][0]].flow << " ";
		}
		cout << endl;*/
	}


	system("pause");
	return 0;
}