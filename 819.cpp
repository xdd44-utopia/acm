#include <iostream>
using namespace std;

int n,m;

int pre[10005];
int nex[10005];

int main() {
	
	cin >> n >> m;
	
	for (int i=1;i<=n;i++) {
		pre[i] = (i == 1 ? n : i - 1);
		nex[i] = (i == n ? 1 : i + 1);
	}
	nex[0] = 1;
	
	int pos = 0;
	
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			pos = nex[pos];
		}
		cout << pos << (i == n - 1 ? "\n" : " ");
		int next = nex[pos];
		nex[pre[pos]] = next;
		pre[next] = pre[pos];
	}
	
	return 0;
}
