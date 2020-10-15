#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

struct City {
	int adjCnt = 0;
	int adj[40];
	double adjDist[40];
	double adjLimit[40];

	void addEdge(int toward, double dist, double limit) {
		adj[adjCnt] = toward;
		adjDist[adjCnt] = dist;
		adjLimit[adjCnt] = limit;
		adjCnt++;
	}
};

struct Trip {
	int from, to;
	double arriveTime;
	int arriveSpeed;

	Trip(int x, int y, double time, int speed) {
		from = x;
		to = y;
		arriveTime = time;
		arriveSpeed = speed;
	}
};

struct compare {
	bool operator()(const Trip& a, const Trip& b) {
		return a.arriveTime > b.arriveTime;
	}
};

double minCost[40][40][40];

int* father;
int find(int tar) {
	int f = father[tar];
	while (f != father[f]) {
		f = father[f];
	}
	father[tar] = f;
	return father[tar];
}
void uni(int a, int b) {
	if (find(a) != find(b)) {
		father[father[a]] = father[father[b]];
	}
}

int main() {

	int n, m;
	while (cin >> n >> m) {
		if (!n && !m) {
			break;
		}

		City* cities = new City[n];
		father = new int[n];
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}

		int s, g;
		cin >> s >> g;
		s--; g--;

		for (int i = 0; i < m; i++) {
			int x, y, d, c;
			cin >> x >> y >> d >> c;
			x--; y--;
			uni(x, y);
			cities[x].addEdge(y, d, c);
			cities[y].addEdge(x, d, c);
		}
		if (find(s) != find(g)) {
			cout << "unreachable\n";
			delete[] cities;
			delete[] father;
			continue;
		}

		priority_queue<Trip, vector<Trip>, compare> pq;

		for (int i = 0; i < cities[s].adjCnt; i++) {
			Trip t(s, cities[s].adj[i], cities[s].adjDist[i], 1);
			pq.push(t);
		}

		double ans = 100000;
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 40; j++) {
				for (int k = 0; k < 40; k++) {
					minCost[i][j][k] = 200000;
				}
			}
		}
		while (!pq.empty()) {
			Trip current = pq.top();
			pq.pop();
			//cout << "debug " << current.from << " " << current.to << " " << current.arriveTime << " " << current.arriveSpeed << endl;
			//cout << endl;
			if (current.to == g && current.arriveSpeed == 1) {
				ans = (ans < current.arriveTime ? ans : current.arriveTime);
			}
			for (int i = 0; i < cities[current.to].adjCnt; i++) {
				if (cities[current.to].adj[i] != current.from) {
					if (current.arriveSpeed <= cities[current.to].adjLimit[i] && minCost[current.to][cities[current.to].adj[i]][current.arriveSpeed] > current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed)) {
						minCost[current.to][cities[current.to].adj[i]][current.arriveSpeed] = current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed);
						Trip t1(current.to, cities[current.to].adj[i], current.arriveTime + cities[current.to].adjDist[i] / current.arriveSpeed, current.arriveSpeed);
						pq.push(t1);
					}
					
					if (current.arriveSpeed > 1 && current.arriveSpeed - 1 <= cities[current.to].adjLimit[i] && minCost[current.to][cities[current.to].adj[i]][current.arriveSpeed - 1] > current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed - 1)) {
						minCost[current.to][cities[current.to].adj[i]][current.arriveSpeed - 1] = current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed - 1);
						Trip t2(current.to, cities[current.to].adj[i], current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed - 1), current.arriveSpeed - 1);
						pq.push(t2);
					}
					if (current.arriveSpeed + 1 <= cities[current.to].adjLimit[i] && minCost[current.to][cities[current.to].adj[i]][current.arriveSpeed + 1] > current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed + 1)) {
						minCost[current.to][cities[current.to].adj[i]][current.arriveSpeed + 1] = current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed + 1);
						Trip t3(current.to, cities[current.to].adj[i], current.arriveTime + cities[current.to].adjDist[i] / (double)(current.arriveSpeed + 1), current.arriveSpeed + 1);
						pq.push(t3);
					}
				}
			}
		}

		printf("%.5lf\n", ans);

		delete[] cities;
		delete[] father;
	}

	return 0;
}