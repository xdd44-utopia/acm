#include<iostream>
#include<queue>

using namespace std;

struct Node {
	int weight;
	Node* left = NULL;
	Node* right = NULL;
	bool isLetter = false;
};

struct compare {
	bool operator()(Node* a, const Node* b) {
		return a->weight > b->weight;
	}
};

int counting(Node* current, int dep) {
	int sum = 0;
	if (current->isLetter) {
		sum += current->weight * dep;
	}
	if (current->left != NULL) {
		sum += counting(current->left, dep + 1);
	}
	if (current->right != NULL) {
		sum += counting(current->right, dep + 1);
	}
	return sum;
}

int main() {
	int n;
	while (cin >> n) {
		priority_queue<Node*, vector<Node*>, compare> tree;
		for (int i = 0; i < n; i++) {
			Node* tNode = new Node;
			cin >> tNode->weight;
			tNode->isLetter = true;
			tree.push(tNode);
		}
		while (tree.size() > 1) {
			Node* node1 = tree.top();
			tree.pop();
			Node* node2 = tree.top();
			tree.pop();
			Node* Fnode = new Node;
			Fnode->weight = node1->weight + node2->weight;
			Fnode->left = node1;
			Fnode->right = node2;
			tree.push(Fnode);
		}
		cout << counting(tree.top(), 0) << endl;
	}
	return 0;
}