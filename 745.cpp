#include<iostream>
#include<stack>
using namespace std;

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		int n, t;
		stack<int> data;
		stack<int> maxd;

		cin >> n;
		cin >> t;
		data.push(t);
		maxd.push(t);
		for (int i = 1; i < n; i++) {
			cin >> t;
			data.push(t);
			maxd.push(t > maxd.top() ? t : maxd.top());
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			char ope;
			cin >> ope;
			switch (ope) {
			case 'm': cout << maxd.top() << endl; break;
			case 'r': {
				maxd.pop();
				data.pop();
				break;
			}
			case 'a': {
				cin >> t;
				if (data.empty()) {
					data.push(t);
					maxd.push(t);
					break;
				}
				else {
					data.push(t);
					maxd.push(t > maxd.top() ? t : maxd.top());
					break;
				}
			}
			}
		}
	}
	return 0;
}