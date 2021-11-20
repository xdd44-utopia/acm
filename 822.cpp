#include <iostream>
using namespace std;

struct Node {
	int parent = 0;
	int l = 0;
	int r = 0;
	int w = 0;
	int wP = 0;
	int wL = 0;
	int wR = 0;
	long long cost = 0;
};

Node tree[5005];
int tot;
long long minimum = 9223372036854775806;

void init(int pos) {
	if (tree[pos].l != 0) {
		init(tree[pos].l);
	}
	if (tree[pos].r != 0) {
		init(tree[pos].r);
	}
	tree[pos].wL = tree[tree[pos].l].w + tree[tree[pos].l].wL + tree[tree[pos].l].wR;
	tree[pos].wR = tree[tree[pos].r].w + tree[tree[pos].r].wL + tree[tree[pos].r].wR;
	tree[pos].wP = tot - tree[pos].w - tree[pos].wL - tree[pos].wR;
	tree[pos].cost = (long long)tree[pos].wL + (long long)tree[pos].wR + tree[tree[pos].l].cost + tree[tree[pos].r].cost;
}

void find(int pos) {
	if (pos != 1) {
		tree[pos].cost = tree[tree[pos].parent].cost + (long long)tree[pos].wP - (long long)(pos == tree[tree[pos].parent].l ? tree[tree[pos].parent].wL : tree[tree[pos].parent].wR);
		minimum = (minimum < tree[pos].cost ? minimum : tree[pos].cost);
	}
	if (tree[pos].l != 0) {
		find(tree[pos].l);
	}
	if (tree[pos].r != 0) {
		find(tree[pos].r);
	}
}

int main() {
	
	int n;
	cin >> n;
	tot = 0;
	
	for (int i=1;i<=n;i++) {
		int w, l, r;
		cin >> w >> l >> r;
		tot += w;
		tree[i].w = w;
		tree[i].l = l;
		tree[i].r = r;
		tree[l].parent = i;
		tree[r].parent = i;
	}
	
	int root = 1;
	for (int i=1;i<=n;i++) {
		if (tree[i].parent == 0) {
			root = i;
		}
	}
	
	init(root);
	
	find(root);
	
	cout << minimum << endl;
	
	return 0;
}
