#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct node {
	int start, end, weight;
};

node nodes[1000];
int ori[1000];

void calc(int nodeNum) {
	int sum = 1;
	if (nodes[nodeNum].start < nodes[nodeNum].end - 1) {
		int child = ori[nodes[nodeNum].start + 1];
		while (1) {
			calc(child);
			sum += nodes[child].weight;
			if (nodes[child].end == nodes[nodeNum].end - 1) {
				break;
			}
			child = ori[nodes[child].end + 1];
		}
	}
	nodes[nodeNum].weight = sum;
}

int main() {
	string str;
	while (cin >> str) {
		stack<int> stk;
		int count = 0;
		for (int i = 0; i < str.length();i++) {
			if (str[i] == '(') {
				stk.push(count);
				ori[i] = count;
				nodes[count].weight = 0;
				nodes[count++].start = i;
			}
			else {
				nodes[stk.top()].end = i;
				ori[i] = stk.top();
				stk.pop();
			}
		}
		/*
		for (int i = 0; i < count; i++) {
			cout << nodes[i].start << " " << nodes[i].end << endl;
		}
		for (int i = 0; i < str.length(); i++) {
			cout << ori[i] << " ";
		}
		cout << endl;
		*/
		calc(0);
		int ans = nodes[0].weight;
		for (int i = 1; i < count; i++) {
			ans = ans ^ nodes[i].weight;
		}
		cout << ans << endl;
	}
	return 0;
}