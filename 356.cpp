#define INT_MIN (-2147483647 - 1)
#include <iostream>

using namespace std;

struct edge {
	int pa, pb;
	long long dis;
};

int* father;
edge* ed;
int* cnt;

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
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		father = new int[n + 1];
		ed = new edge[m];
		cnt = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			father[i] = i;
			cnt[i] = 0;
		}
		long long max = INT_MIN;
		for (int i = 0; i < m; i++) {
			int a, b;
			long long d;
			cin >> a >> b >> d;
			max = d > max ? d : max;
			ed[i].pa = a;
			ed[i].pb = b;
			ed[i].dis = d;
		}

		for (int i = 0; i < m; i++) {
			if (ed[i].dis == max) {
				uni(ed[i].pa, ed[i].pb);
			}
		}

		max = INT_MIN;
		for (int i = 1; i <= n; i++) {
			cnt[find(i)]++;
			max = cnt[find(i)] > max ? cnt[find(i)] : max;
		}

		cout << max << endl;

		delete[] father;
		delete[] ed;
		delete[] cnt;
	}
	return 0;
}