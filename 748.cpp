#include<iostream>
#include<string>

using namespace std;

bool** map;
int px[4] = { 0,0,1,1 };
int py[4] = { 0,1,0,1 };
int n;

struct Node {
	int x, y;
	int range;
	int nodeCount;
	short data;
	bool isWhole = false;
	Node* child[4] = { NULL };
};

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}

void createTree(Node* root) {
	if (root->range == 1) {
		root->nodeCount = 1;
		root->data = map[root->x][root->y];
		root->isWhole = true;
	}
	else {
		int tRange = root->range >> 1;
		for (int i = 0; i < 4; i++) {
			root->child[i] = new Node;
			root->child[i]->range = tRange;
			root->child[i]->x = root->x + px[i] * tRange;
			root->child[i]->y = root->y + py[i] * tRange;
			createTree(root->child[i]);
		}
		if ((root->child[0]->data + root->child[1]->data + root->child[2]->data + root->child[3]->data == 0
			|| root->child[0]->data + root->child[1]->data + root->child[2]->data + root->child[3]->data == 4)
			&& root->child[0]->isWhole && root->child[1]->isWhole && root->child[2]->isWhole && root->child[3]->isWhole) {
			root->isWhole = true;
			root->data = root->child[0]->data;
			root->nodeCount = 1;
		}
		else {
			root->isWhole = false;
			root->nodeCount = root->child[0]->nodeCount + root->child[1]->nodeCount + root->child[2]->nodeCount + root->child[3]->nodeCount + 1;
		}
	}
}

void flip(Node* root, int x, int y) {
	if (root->range == 1) {
		root->data = 1 - root->data;
		map[x][y] = !map[x][y];
	}
	else {
		int tRange = root->range >> 1;
		if (x >= root->x && x < root->x + tRange && y >= root->y && y < root->y + tRange) {
			flip(root->child[0], x, y);
		}
		else if (x >= root->x && x < root->x + tRange && y >= root->y + tRange) {
			flip(root->child[1], x, y);
		}
		else if (x >= root->x + tRange && y >= root->y && y < root->y + tRange) {
			flip(root->child[2], x, y);
		}
		else {
			flip(root->child[3], x, y);
		}
		if ((root->child[0]->data + root->child[1]->data + root->child[2]->data + root->child[3]->data == 0
			|| root->child[0]->data + root->child[1]->data + root->child[2]->data + root->child[3]->data == 4)
			&& root->child[0]->isWhole && root->child[1]->isWhole && root->child[2]->isWhole && root->child[3]->isWhole) {
			root->isWhole = true;
			root->data = root->child[0]->data;
			root->nodeCount = 1;
		}
		else {
			root->isWhole = false;
			root->nodeCount = root->child[0]->nodeCount + root->child[1]->nodeCount + root->child[2]->nodeCount + root->child[3]->nodeCount + 1;
		}
	}
}

void destroyTree(Node* root) {
	if (root->range > 1) {
		for (int i = 0; i < 4; i++) {
			destroyTree(root->child[i]);
		}
	}
	delete root;
}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		cin >> n;
		n = 1 << n;
		map = new bool*[n];
		for (int i = 0; i < n; i++) {
			map[i] = new bool[n];
		}
		for (int i = 0; i < n; i++) {
			string s = "";
			while (s == "" || s == "\n") {
				cin >> s;
			}
			for (int j = 0; j < n; j++) {
				map[i][j] = (s[j] == '1') ? 1 : 0;
			}
		}

		Node* root = new Node;
		root->x = 0;
		root->y = 0;
		root->range = n;
		createTree(root);

		int testNum;
		cin >> testNum;
		for (int t = 0; t < testNum; t++) {
			int tx, ty;
			cin >> tx >> ty;
			tx--;
			ty--;
			flip(root, tx, ty);
			cout << root->nodeCount << endl;
		}

		destroyTree(root);
	}
	return 0;
}