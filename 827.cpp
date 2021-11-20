#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int arr[100005];

void generateArray(int* arr, int n, int m, int seed) {
	unsigned x = seed;
	for (int i = 1; i <= n; i++) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		arr[i] = x % m + 1;
	}
}

int main() {
	
	int n,m,seed;
	cin >> n >> m >> seed;
	
	generateArray(arr, n, m, seed);
	sort(arr, arr + n);
	
	priority_queue<int, vector<int>, greater<int> > q;
	
	for (int i=1;i<=n;i++) {
		q.push(arr[i]);
	}
	
	while (q.size() > 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		cout << a << " " << b << endl;
		q.push((a < b / 2 ? b : a * 2));
	}
	
	cout << q.top() << endl;
	
	return 0;
}
