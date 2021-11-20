#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

#define LL 2147483647;

using namespace std;

struct Node {
	int cnt;
	bool visit1;
	bool visit2;
	int dist1;
	int dist2;
	vector<int> edges;
	vector<int> dist;
	
	void clear() {
		cnt = 0;
		visit1 = false;
		visit2 = false;
		dist1 = LL;
		dist2 = LL;
		edges.clear();
		dist.clear();
	}
};

Node juns[1000];

class Compare1 {
public:
	bool operator() (int i, int j) {
		return juns[i].dist1 > juns[j].dist1;
	}
};
class Compare2 {
public:
	bool operator() (int i, int j){
		return juns[i].dist2 > juns[j].dist2;
	}
};

int main() {
	
	//freopen("/Users/xdd44/Documents/Code/172/sample.in", "r", stdin);
	
	int n,m;
	int caseNum = 0;
	while (cin >> n >> m) {
		caseNum++;
		for (int i=0;i<n;i++) {
			juns[i].clear();
		}
		
		for (int i=0;i<m;i++) {
			int t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			juns[t1].cnt++;
			juns[t1].edges.push_back(t2);
			juns[t1].dist.push_back(t3);
			juns[t2].cnt++;
			juns[t2].edges.push_back(t1);
			juns[t2].dist.push_back(t3);
		}
		
		priority_queue< int, vector<int>, Compare1 > q1;
		priority_queue< int, vector<int>, Compare2 > q2;
		juns[0].dist2 = 0;
		q2.push(0);
		bool isUpdated = false;
		do {
			isUpdated = false;
			if (!q1.empty()) {
				isUpdated = true;
				int cur = q1.top();
				q1.pop();
				juns[cur].visit1 = true;
				for (int i=0;i<juns[cur].cnt;i++) {
					int pointer = juns[cur].edges[i];
					if (!juns[pointer].visit2 && juns[pointer].dist2 > juns[cur].dist1 + juns[cur].dist[i]) {
						juns[pointer].dist2 = juns[cur].dist1 + juns[cur].dist[i];
						q2.push(pointer);
					}
				}
			}
			if (!q2.empty()) {
				isUpdated = true;
				int cur = q2.top();
				q2.pop();
				juns[cur].visit2 = true;
				for (int i=0;i<juns[cur].cnt;i++) {
					int pointer = juns[cur].edges[i];
					if (!juns[pointer].visit1 && juns[pointer].dist1 > juns[cur].dist2 + juns[cur].dist[i]) {
						juns[pointer].dist1 = juns[cur].dist2 + juns[cur].dist[i];
						q1.push(pointer);
					}
				}
			}
		} while (isUpdated);
		
		cout << "Set #" << caseNum << endl;
		if (juns[n-1].dist2 < 2147483647) {
			cout << juns[n-1].dist2 << endl;
		}
		else {
			cout << "?\n";
		}
	}
	
	return 0;
}
