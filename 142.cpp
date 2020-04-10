#include <iostream>
#include <cstring>
using namespace std;

class Set {
private:
	int n;
	int* relation;
public:
	Set(int amount) {
		n = amount;
		relation = new int[n+1];
		for (int i = 1; i <= n; i++) {
			relation[i] = i;
		}
	}
	int Find(int x) {
		int p = relation[x];
		while (p != relation[p]) {
			p = relation[p];
		}
		relation[x] = p;
		return relation[x];
	}
	void Union(int i, int j) {
		if (Find(i) != Find(j)) {
			relation[relation[i]] = relation[relation[j]];
		}
	}
};

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		int n, r;
		cin >> n >> r;
		Set* friends = new Set(n);
		for (int i = 0; i < r; i++) {
			int x, y;
			cin >> x >> y;
			friends->Union(x, y);
		}
		int *relation = new int[n+1];
		int max = 0;
		for (int j = 1; j <= n; j++) {
			relation[j] = 0;
		}
		for (int i = 1; i <= n; i++) {
			relation[friends->Find(i)]++;
			max = max > relation[friends->Find(i)] ? max : relation[friends->Find(i)];
		}
		cout << max << endl;
		delete[] relation;
		delete friends;
	}
	system("pause");
	return 0;
}