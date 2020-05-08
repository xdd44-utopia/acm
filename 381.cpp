#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		int ans[100];
		int cnt = 0;
		stack<int> stk;
		int i = 0;
		int result;
		while (i < str.length()) {
			switch (str[i]) {
			case '(':
				stk.push(-1);
				break;
			case ')':
				result = stk.top();
				stk.pop();
				while (stk.top() != -1) {
					int op = stk.top();
					stk.pop();
					if (op == -2) {
						result += stk.top();
						stk.pop();
					}
					else {
						result *= stk.top();
						stk.pop();
					}
				}
				stk.pop();
				stk.push(result);
				break;
			case '+':
				result = stk.top();
				stk.pop();
				while (!stk.empty() && stk.top() != -1) {
					int op = stk.top();
					stk.pop();
					if (op == -2) {
						result += stk.top();
						stk.pop();
					}
					else {
						result *= stk.top();
						stk.pop();
					}
				}
				stk.push(result);
				stk.push(-2);
				break;
			case '*':
				stk.push(-3);
				break;
			default:
				if (str[i] - 48 < 10) {
					stk.push((int)(str[i] - 48));
				}
				else {
					stk.push((int)(str[i] - 55));
				}
			}
			i++;
		}

		result = stk.top();
		stk.pop();
		while (!stk.empty()) {
			int op = stk.top();
			stk.pop();
			if (op == -2) {
				result += stk.top();
				stk.pop();
			}
			else {
				result *= stk.top();
				stk.pop();
			}
		}

		while (result > 0) {
			ans[cnt++] = result % 16;
			result /= 16;
		}

		for (int i = cnt - 1; i >= 0; i--) {
			if (ans[i] > 9) {
				cout << (char)(ans[i] + 55);
			}
			else {
				cout << ans[i];
			}
		}
		if (cnt == 0) {
			cout << 0;
		}

		cout << endl;
	}
	return 0;
}