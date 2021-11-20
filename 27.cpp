#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int a,b,c,n;
		cin >> a >> b >> c >> n;
		int ans = 0;
		bool isVisited[1000];
		for (int i=0;i<n;i++) {
			int current = 0;
			int p = i;
			for (int j=0;j<n;j++) {
				isVisited[j] = false;
			}
			while (!isVisited[p]) {
				current++;
				isVisited[p] = true;
				p = (a * p * p + b * p + c) % n;
			}
			ans = ans > current ? ans : current;
		}
		cout << ans << endl;
	}
	return 0;
}
