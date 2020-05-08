#include<iostream>
#include<queue>

using namespace std;

bool isPrime[10000];
int p[10000];
int pn = 0;

void gen() {
	for (int i = 0; i < 10000; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i < 10000; i++) {
		if (isPrime[i]) {
			p[pn++] = i;
		}
		for (int j = 0; j < pn && p[j] * i < 10000; j++) {
			isPrime[p[j] * i] = false;
			if (i % p[j] == 0) {
				break;
			}
		}
	}
}

int main() {
	gen();
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;

		int cost = 0;
		bool done = false;
		bool visited[10000];
		queue<int> q;
		queue<int> dep;
		for (int i = 0; i < 10000; i++) {
			visited[i] = false;
		}

		q.push(from);
		dep.push(0);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			int curDep = dep.front();
			dep.pop();
			if (!visited[cur]) {
				visited[cur] = true;
				if (cur == to) {
					done = true;
					cost = curDep;
					break;
				}
				int digit[4];
				for (int j = 0; j < 4; j++) {
					digit[j] = cur % 10;
					cur /= 10;
				}
				for (int j = 0; j < 4; j++) {
					for (int k = (j < 3 ? 0 : 1); k < 10; k++) {
						int newNum = (j == 3 ? k : digit[3]);
						newNum = newNum * 10 + (j == 2 ? k : digit[2]);
						newNum = newNum * 10 + (j == 1 ? k : digit[1]);
						newNum = newNum * 10 + (j == 0 ? k : digit[0]);
						if (!visited[newNum] && isPrime[newNum]) {
							q.push(newNum);
							dep.push(curDep + 1);
						}
					}
				}
			}
		}
		if (done) {
			cout << cost << endl;
		}
		else {
			cout << "Impossible" << endl;
		}
	}

	return 0;
}