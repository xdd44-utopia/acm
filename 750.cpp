#include<iostream>
using namespace std;

int* father;
bool* visited;
int n;

int main() {
	int caseNum;
	int root;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		cin >> root >> n;
		father = new int[n+1];
		visited = new bool[n+1];
		for (int i = 0; i < n+1; i++) {
			father[i] = i;
			visited[i] = false;
		}
		for (int i = 0; i < n - 1; i++) {
			int tChild, tFather;
			cin >> tChild >> tFather;
			father[tChild] = tFather;
		}
		int a, b;
		cin >> a >> b;
		while (1) {
			visited[a] = true;
			if (a == father[a]) {
				break;
			}
			a = father[a];
		}
		while (!visited[b]) {
			b = father[b];
		}
		cout << b << endl;
		delete[] father;
		delete[] visited;
	}
}