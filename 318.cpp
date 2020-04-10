#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

short dx[4] = { 0, 1, 0, -1 };
short dy[4] = { -1, 0, 1, 0 };

bool done[130][130];
int n;

struct point {
	int x,y,dist;
	int data;

	void toString() {
		cout << "(" << x << "," << y << ") data: " << data << " dist: " << dist << " ";
	}
};

struct compare {
	bool operator()(const point & a, const point & b) {
		return a.dist > b.dist;
	}
};

int main() {
	point graph[130][130];
	int prob = 0;
	while (1) {
		prob++;

		memset(done, 0, sizeof(done));
		priority_queue <point, vector<point>, compare> edge;

		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> graph[i][j].data;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j].x = i;
				graph[i][j].y = j;
				if (i == 0 && j == 0) {
					graph[i][j].dist = graph[0][0].data;
				}
				else {
					graph[i][j].dist = 2147483647;
				}
				edge.push(graph[i][j]);
			}
		}

		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				graph[i][j].toString();
			}
			cout << endl;
		}
		*/

		while (!edge.empty()) {
			point pt = edge.top();
			edge.pop();
			if (pt.x == n - 1 && pt.y == n - 1) {
				cout << "Problem " << prob << ": " << pt.dist << endl;
				break;
			}
			if (done[pt.x][pt.y]) {
				continue;
			}
			done[pt.x][pt.y] = true;
			for (int i = 0; i < 4; i++) {
				if (pt.x + dx[i] >= 0 && pt.x + dx[i] < n && pt.y + dy[i] >= 0 && pt.y + dy[i] < n
					&& pt.dist + graph[pt.x + dx[i]][pt.y + dy[i]].data < graph[pt.x + dx[i]][pt.y + dy[i]].dist) {
					graph[pt.x + dx[i]][pt.y + dy[i]].dist = pt.dist + graph[pt.x + dx[i]][pt.y + dy[i]].data;
					edge.push(graph[pt.x + dx[i]][pt.y + dy[i]]);
				}
			}
		}
	}
	return 0;
}