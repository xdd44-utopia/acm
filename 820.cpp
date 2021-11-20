
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int nodeCount = 0;

struct Node {
	int idx;
	bool canSingle = true;
	bool ignore = true;
	int childCnt = 0;
	vector<int> child;
	
	void init() {
		canSingle = true;
		childCnt = 0;
		child.clear();
	}
};

Node nodes[1000];

void addNode(int idx, int pos) {
	nodes[pos].childCnt++;
	nodes[pos].child.push_back(nodeCount);
	nodes[nodeCount++].idx = idx;
}

void addChild(queue<int> &path, int pos, bool ignore) {
	nodes[pos].canSingle = ignore;
	int rootIdx = path.front();
	path.pop();
	if (path.size() == 0) {
		addNode(rootIdx, pos);
		nodes[nodeCount-1].ignore = ignore;
	}
	else {
		int isExist = false;
		for (int i=0;i<nodes[pos].childCnt;i++){
			int j = nodes[pos].child[i];
			if (nodes[j].idx == rootIdx) {
				addChild(path, j, ignore);
				isExist = true;
				break;
			}
		}
		if (!isExist) {
			addNode(rootIdx, pos);
			addChild(path, nodeCount - 1, ignore);
		}
	}
}

int dfs(int pos) {
	if (nodes[pos].canSingle) {
		return 1;
	}
	else {
		int result = 0;
		for (int i=0;i<nodes[pos].childCnt;i++) {
			result += dfs(nodes[pos].child[i]);
		}
		return result;
	}
}

void print(){
	cout << "######" << endl;
	for (int i=0;i<nodeCount;i++) {
		cout << nodes[i].idx << endl;
		cout << nodes[i].canSingle << endl;
		for (int j=0;j<nodes[i].childCnt;j++){
			cout << nodes[i].child[j] << " ";
		}
		cout << endl;
	}
}

int main() {
	
	int caseNum;
	cin >> caseNum;
	for (int c=0;c<caseNum;c++) {
		int n, m;
		cin >> n >> m;
		nodeCount = 1;
		for (int i=0;i<1000;i++) {
			nodes[i].init();
		}
		nodes[0].idx = -1;
		for (int i=0;i<n;i++) {
			queue<int> path;
			while (1) {
				int t;
				cin >> t;
				if (t > -1) {
					path.push(t);
				}
				else {
					break;
				}
			}
			addChild(path, 0, true);
		}
		
		for (int i=0;i<m;i++) {
			queue<int> path;
			while (1) {
				int t;
				cin >> t;
				if (t > -1) {
					path.push(t);
				}
				else {
					break;
				}
			}
			addChild(path, 0, false);
		}
		
		nodes[0].canSingle = false;
		cout << dfs(0) - m << endl;
		
		//print();
	}
	
	return 0;
}
