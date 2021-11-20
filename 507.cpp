#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

struct Room {
	bool visited[13];
	int dist[13];
	int op = 0; // 0 nothing, 1 plus, 2 minus, 3 multi, 4 equal
	int opn;
	
	int cnt = 0;
	vector<int> edges;
	vector<int> lens;
	
	void init() {
		op = 0;
		cnt = 0;
		edges.clear();
		lens.clear();
		for (int i=1;i<=12;i++) {
			visited[i] = false;
			dist[i] = 2147483647;
		}
	}
};

Room rooms[1005];

class Compare {
public:
	bool operator() (pi a, pi b) {
		return rooms[a.first].dist[a.second] > rooms[b.first].dist[b.second];
	}
};

int main() {
	
	int n, nCorridor, nTrap;
	pi start;
	pi target;
	
	while (cin >> n >> nCorridor >> nTrap >> start.first >> start.second >> target.first >> target.second) {
		
		for (int i=1;i<=n;i++) {
			rooms[i].init();
		}
		
		for (int i=0;i<nCorridor;i++) {
			int s, t, d;
			cin >> s >> t >> d;
			rooms[s].edges.push_back(t);
			rooms[s].lens.push_back(d);
			rooms[s].cnt++;
			rooms[t].edges.push_back(s);
			rooms[t].lens.push_back(d);
			rooms[t].cnt++;
		}
		
		for (int i=0;i<nTrap;i++) {
			int r, t;
			char c;
			cin >> r >> c >> t;
			rooms[r].opn = t;
			switch (c) {
				case '+':
					rooms[r].op = 1;
					break;
				case '-':
					rooms[r].op = 2;
					break;
				case '*':
					rooms[r].op = 3;
					break;
				case '=':
					rooms[r].op = 4;
					break;
			}
		}
		
		priority_queue<pi, vector<pi>, Compare> pq;
		rooms[start.first].dist[start.second] = 0;
		pq.push(start);
		bool done = false;
		while (!pq.empty() && !done) {
			pi cur = pq.top();
			pq.pop();
			if (cur == target) {
				done = true;
			}
			else {
				rooms[cur.first].visited[cur.second] = true;
				for (int i=0;i<rooms[cur.first].cnt;i++) {
					pi nex;
					nex.first = rooms[cur.first].edges[i];
					switch (rooms[nex.first].op) {
						case 0:
							nex.second = cur.second;
							break;
						case 1:
							nex.second = cur.second + rooms[nex.first].opn;
							break;
						case 2:
							nex.second = cur.second - rooms[nex.first].opn;
							break;
						case 3:
							nex.second = cur.second * rooms[nex.first].opn;
							break;
						case 4:
							nex.second = rooms[nex.first].opn;
							break;
					}
					nex.second = nex.second % 12;
					while (nex.second <= 0) {
						nex.second += 12;
					}
					if (!rooms[nex.first].visited[nex.second] && rooms[nex.first].dist[nex.second] > rooms[cur.first].dist[cur.second] + rooms[cur.first].lens[i]) {
						rooms[nex.first].dist[nex.second] = rooms[cur.first].dist[cur.second] + rooms[cur.first].lens[i];
						pq.push(nex);
					}
				}
			}
		}
		
		if (!done) {
			cout << "Pray!\n";
		}
		else {
			cout << rooms[target.first].dist[target.second] << endl;
		}
		
	}
	
	return 0;
}
