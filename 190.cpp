#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int caseNum;
	bool flag = false;
	cin >> caseNum;
	string op = "";
	getline(cin, op);
	getline(cin, op);
	for (int c = 0; c < caseNum; c++) {
		string answer = "";
		char ch;
		stack<char> stk;
		stk.push('#');
		while (getline(cin, op)) {
			if (op.length() == 0) {
				break;
			}
			ch = op[0];
			switch (ch) {
			case '(':
				stk.push(ch);
				break;
			case ')':
				while (stk.top() != '(' && stk.top() != '#') {
					answer = answer + stk.top();
					stk.pop();
				}
				stk.pop();
				break;
			case '+': case '-':
				while (stk.top() != '(' && stk.top() != '#') {
					answer = answer + stk.top();
					stk.pop();
				}
				stk.push(ch);
				break;
			case '*': case '/':
				while (stk.top() != '(' && stk.top() != '#' && stk.top() != '+' && stk.top() != '-') {
					answer = answer + stk.top();
					stk.pop();
				}
				stk.push(ch);
				break;
			default:
				answer = answer + ch;
			}
		}
		while (stk.top() != '#') {
			answer = answer + stk.top();
			stk.pop();
		}
		if (flag) {
			cout << endl;
		}
		else {
			flag = true;
		}
		cout << answer << endl;
	}
	return 0;
}