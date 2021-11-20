#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
	int u, v;
	int dist;
};

int father[1000];
Edge edges[250000];
int cnt;

int find(int x) {
	int fx = father[x];
	while (fx != father[fx]) {
		fx = father[fx];
	}
	return fx;
}

void join(int x, int y) {
	int fx = find(x);
	int fy = find(y);
	father[fx] = fy;
}

int getDist(int x, int y) {
	int result = 0;
	int l, r;
	l = x % 10;
	r = y % 10;
	result += min(min(abs(l - r), abs(l + 10 - r)), abs(r + 10 - l));
	l = (x % 100) / 10;
	r = (y % 100) / 10;
	result += min(min(abs(l - r), abs(l + 10 - r)), abs(r + 10 - l));
	l = (x % 1000) / 100;
	r = (y % 1000) / 100;
	result += min(min(abs(l - r), abs(l + 10 - r)), abs(r + 10 - l));
	l = x / 1000;
	r = y / 1000;
	result += min(min(abs(l - r), abs(l + 10 - r)), abs(r + 10 - l));
	return result;
}

bool compare(const Edge& i, const Edge& j) {
	return i.dist < j.dist;
}

int main() {
	
	int caseNum;
	cin >> caseNum;
	
	while (caseNum--) {
		int n;
		cin >> n;
		int arr[1000];
		for (int i=0;i<n;i++) {
			father[i] = i;
			cin >> arr[i];
		}
		
		cnt = 0;
		for (int i=0;i<n-1;i++) {
			for (int j=i+1;j<n;j++) {
				Edge et;
				et.u = i;
				et.v = j;
				et.dist = getDist(arr[i], arr[j]);
				edges[cnt++] = et;
			}
		}
		
		sort(edges, edges+cnt, compare);
		
		int size = 0;
		int ans = 0;
		for (int i=0;i<cnt;i++) {
			if (find(edges[i].u) != find(edges[i].v)) {
				join(edges[i].u, edges[i].v);
				ans += edges[i].dist;
				size++;
			}
			if (size == n-1) {
				break;
			}
		}
		
		int temp = 2147483647;
		for (int i=0;i<n;i++) {
			temp = temp < getDist(0, arr[i]) ? temp : getDist(0, arr[i]);
		}
		
		ans += temp;
		
		cout << ans << endl;
		
	}
	
	return 0;
}
