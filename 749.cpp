#include<iostream>
#include<cstring>

using namespace std;

int n;
int* preorder;
int* inorder;
bool printed;

void ana(int treePos, int preLeft, int preRight, int inLeft, int inRight) {
	int find;
	for (int i = inLeft; i <= inRight; i++) {
		if (preorder[preLeft] == inorder[i]) {
			find = i;
			break;
		}
	}
	if (find > inLeft) {
		ana(treePos * 2 + 1, preLeft + 1, preLeft + find - inLeft, inLeft, find - 1);
	}
	if (find < inRight) {
		ana(treePos * 2 + 2, preLeft + find - inLeft + 1, preRight, find + 1, inRight);
	}
	if (printed) {
		cout << " ";
	}
	else {
		printed = true;
	}
	cout << preorder[preLeft];
}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		cin >> n;
		preorder = new int[n];
		inorder = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> inorder[i];
		}

		printed = false;
		ana(0, 0, n - 1, 0, n - 1);
		cout << endl;

		delete[] preorder;
		delete[] inorder;
	}
}