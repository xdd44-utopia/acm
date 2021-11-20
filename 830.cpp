#include <iostream>
#include <vector>

using namespace std;

struct City {
	bool visited = false;
	int reachable;
	int childCnt;
	vector<int> child;
	
	void addChild(int x) {
		childCnt++;
		child.push_back(x);
	}
};

City cities[2000];
int friends[200];
int k, n, m;

void clearing(){
	for (int i=1;i<=n;i++) {
		cities[i].visited = false;
	}
}

void dfs(int pos) {
	cities[pos].reachable++;
	cities[pos].visited = true;
	for (int i=0;i<cities[pos].childCnt;i++){
		int pointer = cities[pos].child[i];
		if (!cities[pointer].visited) {
			dfs(pointer);
		}
	}
}

int main() {
	
	cin >> k >> n >> m;
	
	for (int i=1;i<=n;i++) {
		cities[i].reachable = 0;
		cities[i].childCnt = 0;
	}
	
	for (int i=0;i<k;i++) {
		cin >> friends[i];
	}
	
	for (int i=0;i<m;i++) {
		int x,y;
		cin >> x >> y;
		cities[x].addChild(y);
	}
	
	for (int i=0;i<k;i++) {
		clearing();
		dfs(friends[i]);
	}
	
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (cities[i].reachable == k) {
			ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
