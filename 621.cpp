#include<iostream>
#include<string>

using namespace std;

struct Edge {
	int from;
	int to;
	int v;
};

Edge edges[3000];

bool hasOld[55][55];
int cmk[55][55];
int crm[55][55];

int father[55];

void initSet() {
	for (int i = 0; i < 55; i++) {
		father[i] = i;
	}
}

int findFather(int x) {
	int t = father[x];
	while (t != father[t]) {
		t = father[t];
	}
	father[x] = t;
	return t;
}

void unionFather(int x, int y) {
	father[findFather(x)] = father[findFather(y)];
}

void sortEdge(int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (edges[j].v < edges[i].v) {
				Edge t = edges[j];
				edges[j] = edges[i];
				edges[i] = t;
			}
		}
	}
}

int main() {
	int n;
	while (true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		int edgeCnt = 0;
		int ans = 0;
		string ipt;
		for (int i = 0; i < n; i++) {
			cin >> ipt;
			for (int j = 0; j < n; j++) {
				hasOld[i][j] = (int)ipt[j] - 48;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cmk[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> crm[i][j];
				if (hasOld[i][j]) {
					ans += crm[i][j];
				}
			}
		}
		ans /= 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				edges[edgeCnt].v = hasOld[i][j] ? (-crm[i][j]) : cmk[i][j];
				edges[edgeCnt].from = i;
				edges[edgeCnt].to = j;
				edgeCnt++;
			}
		}

		sortEdge(edgeCnt);
		initSet();
		for (int i = 0; i < edgeCnt; i++) {
			if (findFather(edges[i].from) != findFather(edges[i].to)) {
				unionFather(edges[i].from, edges[i].to);
				ans += edges[i].v;
			}
		}

		cout << ans << endl;
	}
	return 0;
}