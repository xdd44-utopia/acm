#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

#define MAXN 5002
#define INF 2147483647

using namespace std;

struct Pipe {
	int from;
	int to;
	int cap;
	int flow;
	Pipe(int x, int y, int c, int f) {
		from = x;
		to = y;
		cap = c;
		flow = f;
	}
};

vector<Pipe> pipes;
vector<int> nodes[MAXN];
int level[MAXN];
int cur[MAXN];
int n, m;
int src, sink;

void addPipe(int from, int to, int c) {
	pipes.push_back(Pipe(from, to, c, 0));
	pipes.push_back(Pipe(to, from, 0, 0));
	int cnt = pipes.size();
	nodes[from].push_back(cnt - 2);
	nodes[to].push_back(cnt - 1);
}

bool genLevel() {
	bool reached = false;
	memset(level, -1, sizeof(int) * MAXN);
	level[src] = 0;
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == sink) {
			reached = true;
			break;
		}
		for (int i = 0; i < nodes[t].size(); i++) {
			Pipe& p = pipes[nodes[t][i]];
			if (p.cap > p.flow && level[p.to] < 0) {
				level[p.to] = level[t] + 1;
				q.push(p.to);
			}
		}
	}
	return reached;
}

int dinic(int pos, int residual) {
	if (pos == sink || residual == 0) {
		return residual;
	}
	int totalAdd = 0;
	int addFlow = 0;
	for (int& i = cur[pos]; i < nodes[pos].size(); i++) {
		Pipe& p = pipes[nodes[pos][i]];
		if (level[pos] + 1 == level[p.to] && p.cap > p.flow) {
			addFlow = dinic(p.to, residual < (p.cap - p.flow) ? residual : (p.cap - p.flow));
			if (addFlow) {
				p.flow += addFlow;
				pipes[nodes[pos][i] ^ 1].flow -= addFlow;
				totalAdd += addFlow;
				residual -= addFlow;
				if (residual == 0) {
					break;
				}
			}
		}
	}
	return totalAdd;
}

int main() {

	while (cin >> n >> m) {
		src = n * 2;
		sink = n * 2 + 1;
		nodes[src].clear();
		nodes[sink].clear();
		for (int i = 0; i < n; i++) {
			nodes[i * 2].clear();
			nodes[i * 2 + 1].clear();
			int x, y;
			cin >> x >> y;
			addPipe(src, i * 2, x);
			addPipe(i * 2 + 1, sink, y);
			addPipe(i * 2, i * 2 + 1, INF);
		}
		for (int i = 0; i < m; i++) {
			int x, y, t;
			cin >> x >> y >> t;
			x--; y--;
			addPipe(x * 2 + 1, y * 2, t);
			addPipe(y * 2 + 1, x * 2, t);
		}

		int ans = 0;
		while (genLevel()) {
			memset(cur, 0, sizeof(cur));
			ans += dinic(src, INF);
		}

		cout << ans << endl;
	}

	return 0;

}