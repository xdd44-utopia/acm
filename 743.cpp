#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main() {
	string str = "233";
	while (getline(cin, str) && str.size() > 0) {
		stack<int> stk;
		stack<int> idx;
		bool v = true;
		for (int i = 0; i < str.length(); i++) {
			switch (str[i]) {
			case '(': {
				stk.push(1);
				idx.push(i);
				break;
			}
			case '[': {
				stk.push(2);
				idx.push(i);
				break;
			}
			case '{': {
				stk.push(3);
				idx.push(i);
				break;
			}
			case ')': {
				if (stk.empty() || stk.top() != 1) {
					cout << i + 1 << endl;
					v = false;
				}
				else {
					stk.pop();
					idx.pop();
				}
				break;
			}
			case ']': {
				if (stk.empty() || stk.top() != 2) {
					cout << i + 1 << endl;
					v = false;
				}
				else {
					stk.pop();
					idx.pop();
				}
				break;
			}
			case '}': {
				if (stk.empty() || stk.top() != 3) {
					cout << i + 1 << endl;
					v = false;
				}
				else {
					stk.pop();
					idx.pop();
				}
				break;
			}
			}
			if (!v) {
				break;
			}
		}
		if (v && stk.empty()) {
			cout << "Success\n";
		}
		if (v && !stk.empty()) {
			int t,it;
			while (!stk.empty()) {
				t = stk.top();
				it = idx.top();
				stk.pop();
				idx.pop();
			}
			cout << it + 1 << endl;
		}
	}
	return 0;
}