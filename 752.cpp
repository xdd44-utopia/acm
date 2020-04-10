#include<iostream>
#include<queue>
using namespace std;
struct task {
	int arrive;
	int process;
	int order;
	bool isLow;
};

int main() {
	int n;
	while (cin >> n) {
		queue<task> high;
		queue<task> low;
		queue<task> arriving;
		int* finish = new int[n];
		int time = 0;
		for (int i = 0; i < n; i++) {
			task t;
			cin >> t.arrive >> t.process >> t.isLow;
			t.order = i;
			arriving.push(t);
		}
		while (!high.empty() || !low.empty() || !arriving.empty()) {
			while (!arriving.empty() && arriving.front().arrive <= time) {
				task t = arriving.front();
				arriving.pop();
				if (t.isLow) {
					low.push(t);
				}
				else {
					high.push(t);
				}
			}
			if (!high.empty()) {
				time += high.front().process;
				finish[high.front().order] = time;
				high.pop();
			}
			else if(!low.empty()){
				time += low.front().process;
				finish[low.front().order] = time;
				low.pop();
			}
			else {
				time++;
			}
		}
		cout << finish[0];
		for (int i = 1; i < n; i++) {
			cout << " " << finish[i];
		}
		cout << endl;
		delete[] finish;
	}
}