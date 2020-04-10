#include<iostream>
#include<stack>

using namespace std;

struct rect {
	int height;
	int start;
};

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		int n;
		cin >> n;

		long long max = 0;
		stack<rect> stk;
		rect t;
		t.height = 0;
		t.start = 0;
		stk.push(t);

		for (int i = 0; i <= n; i++) {
			rect newRect;
			if (i < n) {
				cin >> newRect.height;
			}
			else {
				newRect.height = 0;
			}
			newRect.start = i;
			while (stk.top().height > newRect.height) {
				t = stk.top();
				stk.pop();
				long long tHeight = t.height;
				long long tWidth = i - t.start;
				max = tHeight * tWidth > max ? tHeight * tWidth : max;
				newRect.start = t.start;
			}
			stk.push(newRect);
		}
		cout << max << endl;
	}
	return 0;
}