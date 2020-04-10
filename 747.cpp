#include<iostream>
#include<queue>
using namespace std;

struct ob {
	int data, idx;
};

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		int n,k;
		queue<ob> q;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			ob t;
			cin >> t.data;
			t.idx = i + 1;
			q.push(t);
		}
		bool havePrinted = false;
		ob* temp = new ob[k];
		while (q.size() > 0) {
			int maxData = -2147483647;
			int maxi;
			int range = (k < q.size() ? k : q.size());
			for (int i = 0; i < range; i++) {
				temp[i] = q.front();
				q.pop();
				if (temp[i].data > maxData) {
					maxData = temp[i].data;
					maxi = i;
				}
			}
			if (havePrinted) {
				cout << " ";
			}
			else {
				havePrinted = true;
			}
			cout << temp[maxi].idx;
			for (int i = 0; i < range; i++) {
				temp[i].data--;
				if (i != maxi) {
					q.push(temp[i]);
				}
			}
		}
		cout << endl;
		delete[] temp;
	}
	return 0;
}