#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main() {
	char str[1000];
	int ans;
	while (cin.getline(str,1000)) {
		stack<int> stk;
		for (int i = 0; i < strlen(str); i++) {
			int x, y;
			switch (str[i]) {
			case '+':
				x = stk.top();
				stk.pop();
				y = stk.top();
				stk.pop();
				stk.push(x + y);
				break;
			case '-':
				x = stk.top();
				stk.pop();
				y = stk.top();
				stk.pop();
				stk.push(y - x);
				break;
			case '*':
				x = stk.top();
				stk.pop();
				y = stk.top();
				stk.pop();
				stk.push(x * y);
				break;
			case ' ':
				break;
			default:
				stk.push(str[i] - 48);
			}
		}
		cout << stk.top() << endl;
	}
	return 0;
}