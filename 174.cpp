#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

const int LL = 2147483647;

using namespace std;

struct Node {
	int tax;
	int dis = LL;
	int from;
	bool visited = false;
	int cnt = 0;
	vector<int> edges;
	vector<int> dist;
	void clear() {
		dis = LL;
		visited = false;
		from = -1;
	}
};

vector<Node> cities;
int start, destination;
bool isPrinted = false;

class Compare {
public:
	bool operator() (int i, int j) {
		return cities[i].dis > cities[j].dis;
	}
};

void print() {
	if (!isPrinted) {
		isPrinted = true;
	}
	else {
		cout << endl;
	}
	cout << "From " << start + 1 << " to " << destination + 1 << " :\n";
	string str = to_string(destination + 1);
	int pointer = destination;
	while (cities[pointer].from >= 0) {
		str = to_string(cities[pointer].from + 1) + "-->" + str;
		pointer = cities[pointer].from;
	}
	cout << "Path: " << str << endl;
	cout << "Total cost : " << (start != destination ? cities[destination].dis : 0) << endl;
}

int main() {
	
	freopen("/Users/xdd44/Documents/Code/174/sample.in", "r", stdin);
	
	int caseNum;
	cin >> caseNum;
	string line;
	getline(cin, line);
	getline(cin, line);
	while (getline(cin, line)) {
		int n = 0;
		int temp = 0;
		cities.clear();
		stringstream ss;
		ss << line;
		while (ss >> temp) {
			n++;
			Node city;
			cities.push_back(city);
			if (n > 1 && temp >= 0) {
				cities[0].cnt++;
				cities[0].edges.push_back(n-1);
				cities[0].dist.push_back(temp);
			}
		}
		for (int i=1;i<n;i++) {
			for (int j=0;j<n;j++) {
				cin >> temp;
				if (i != j && temp >= 0) {
					cities[i].cnt++;
					cities[i].edges.push_back(j);
					cities[i].dist.push_back(temp);
				}
			}
		}
		for (int i=0;i<n;i++) {
			cin >> cities[i].tax;
		}
		getline(cin, line);
		while (getline(cin, line)) {
			if (line.length() == 0) {
				break;
			}
			stringstream sst;
			sst << line;
			sst >> start >> destination;
			start--;
			destination--;
			priority_queue < int, vector<int>, Compare > pq;
			for (int i=0;i<n;i++) {
				cities[i].clear();
			}
			cities[start].dis = -cities[start].tax;
			pq.push(start);
			while (!pq.empty()) {
				int cur = pq.top();
				pq.pop();
				cities[cur].visited = true;
				if (cur == destination) {
					print();
					break;
				}
				for (int i=0;i<cities[cur].cnt;i++) {
					int pointer = cities[cur].edges[i];
					if (!cities[pointer].visited && cities[pointer].dis > cities[cur].dis + cities[cur].tax + cities[cur].dist[i]) {
						cities[pointer].dis = cities[cur].dis + cities[cur].tax + cities[cur].dist[i];
						cities[pointer].from = cur;
						pq.push(pointer);
					}
				}
			}
		}
	}
	
	return 0;
}
