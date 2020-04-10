#include<iostream>
#include<queue>
using namespace std;

struct cus {
	int a, o, l;
	bool isLast;
};

int main() {
	int n;
	while (cin >> n) {
		queue<cus> inQueue;
		queue<cus> arriving;
		for (int i = 0; i < n; i++) {
			cus tCus;
			cin >> tCus.a >> tCus.o >> tCus.l;
			tCus.isLast = (i == n - 1);
			arriving.push(tCus);
		}
		int currentTime = 0;
		bool noMoreCus = false;
		bool lastCusLeft = true;
		cus tCus;
		cus lastServe;
		while (1) {
			if (!inQueue.empty()) {
				while (!inQueue.empty() && inQueue.front().o == 0) {
					lastServe = inQueue.front();
					inQueue.pop();
				}
				inQueue.front().o--;
				while (!inQueue.empty() && inQueue.front().o == 0) {
					lastServe = inQueue.front();
					inQueue.pop();
				}
			}
			while (arriving.front().a == currentTime) {
				tCus = arriving.front();
				arriving.pop();
				if (inQueue.empty() && tCus.o == 0) {
					lastServe = tCus;
				}
				else if (inQueue.size() <= tCus.l) {
					inQueue.push(tCus);
				}
				if (arriving.empty()) {
					noMoreCus = true;
					break;
				}
			}
			if (noMoreCus) {
				break;
			}
			currentTime++;
		}
		while (!inQueue.empty()) {
			currentTime += inQueue.front().o;
			lastServe = inQueue.front();
			inQueue.pop();
		}
		if (lastServe.isLast) {
			cout << currentTime - lastServe.o << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}