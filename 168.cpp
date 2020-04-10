#include <iostream>
#include <queue>

using namespace std;

struct Edge {
	int len;
	int idx;
	Edge* next;

	void init(int tidx, int tlen) {
		idx = tidx;
		len = tlen;
		next = nullptr;
	}
};

struct Node {
	int idx;
	bool visited;
	int dist;
	Edge* firstEdge;
	
	void init(int ti) {
		idx = ti;
		visited = false;
		dist = 2147483647;
		firstEdge = nullptr;
	}

	void addEdge(int tidx, int tlen) {
		Edge* p = new Edge;
		p->init(tidx, tlen);
		p->next = firstEdge;
		firstEdge = p;
	}

	void toString() {
		cout << idx << " " << dist << " connecting";
		Edge* p = firstEdge;
		while (p != nullptr) {
			cout << " " << p->idx << " " << p->len << ",";
			p = p->next;
		}
		cout << endl;
	}
};

struct cmp {
	bool operator()(Node a, Node b) {
		return a.dist > b.dist;
	}
};

int main() {
	while (1) {
		int n, r;
		cin >> n;
		if (n == 0) {
			break;
		}
		cin >> r;
		Node* arr = new Node[n];

		for (int i = 0; i < n; i++) {
			arr[i].init(i);
		}

		for (int i = 0; i < r; i++) {
			int ta, tb, td;
			cin >> ta >> tb >> td;
			ta--;
			tb--;
			arr[ta].addEdge(tb, td);
			arr[tb].addEdge(ta, td);
		}

		priority_queue<Node, vector<Node>, cmp> pq;
		int cnt = 0;
		int ans = 0;
		arr[0].dist = 0;
		pq.push(arr[0]);

		while (cnt < n) {
			while (arr[pq.top().idx].visited) {
				pq.pop();
			}
			Node tn = pq.top();
			pq.pop();
			arr[tn.idx].visited = true;
			cnt++;
			ans += tn.dist;

			Edge* te = tn.firstEdge;
			while (te != nullptr) {
				if (arr[te->idx].dist > te->len) {
					arr[te->idx].dist = te->len;
					pq.push(arr[te->idx]);
				}
				te = te->next;
			}
		}

		cout << ans << endl;

		delete[] arr;
	}
	return 0;
}