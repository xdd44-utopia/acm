#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int cnt;
	vector<int> edges;
};

Node country[20];

int main() {
	
	int caseNum = 0;
	int temp;
	bool isFirst = true;
	while (cin >> temp) {
		caseNum++;
		cout << "Test Set #" << caseNum << endl;
		for (int i=0;i<20;i++) {
			country[i].cnt = 0;
			country[i].edges.clear();
		}
		for (int i=0;i<19;i++) {
			int tn;
			if (isFirst) {
				tn = temp;
				isFirst = false;
			}
			else {
				cin >> tn;
			}
			for (int j=0;j<tn;j++) {
				int to;
				cin >> to;
				to--;
				country[i].cnt++;
				country[i].edges.push_back(to);
				country[to].cnt++;
				country[to].edges.push_back(i);
			}
		}
		
		int n;
		cin >> n;
		while (n--) {
			int s, t;
			cin >> s >> t;
			s--;
			t--;
			int visited[20];
			queue<int> bfs;
			for (int i=0;i<20;i++) {
				visited[i] = -1;
			}
			visited[s] = 0;
			bfs.push(s);
			while (!bfs.empty()) {
				int cur = bfs.front();
				bfs.pop();
				if (cur == t) {
					s++;
					t++;
					if (s < 10) {
						cout << " ";
					}
					cout << s;
					cout << " to ";
					if (t < 10) {
						cout << " ";
					}
					cout << t;
					cout << ": ";
					cout << visited[cur] << endl;
					break;
				}
				for (int i=0;i<country[cur].cnt;i++) {
					if (visited[country[cur].edges[i]] < 0) {
						visited[country[cur].edges[i]] = visited[cur] + 1;
						bfs.push(country[cur].edges[i]);
					}
				}
			}
		}
		cout << endl;
		isFirst = true;
	}
	
	return 0;
}
