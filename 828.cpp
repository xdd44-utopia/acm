#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[10000005];
int cnt = 0;
vector<int> radix[1024];

void generateArray(int* arr, int n, int m, int seed) {
	unsigned x = seed;
	for (int i = 1; i <= n; i++) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		arr[i] = x % m + 1;
	}
}

void clearRadix() {
	cnt = 0;
	for (int i=0;i<1024;i++) {
		radix[i].clear();
	}
}

int main() {
	
	int n,m,seed;
	cin >> n >> m >> seed;
	
	generateArray(arr, n, m, seed);
	queue<long long> working;
	
	int counter = 0;
	for (int digit = 0; digit<=20; digit+=10) {
		clearRadix();
		for (int i=1;i<=n;i++) {
			counter++;
			radix[(arr[i] >> digit) & 1023].push_back(arr[i]);
		}
		for (int i=0;i<1024;i++) {
			int num = (int)radix[i].size();
			for (int j=0;j<num;j++) {
				counter++;
				arr[++cnt] = radix[i][j];
			}
		}
	}
	cout << counter << endl;
	
	int pos = 3;
	working.push(arr[1]);
	working.push(arr[2]);
	
	while (working.size() > 1) {
		long long a = working.front();
		working.pop();
		long long b = working.front();
		working.pop();
		long long buffer = (a * 2 > b ? a * 2 : b);
		while (pos <= n && arr[pos] < buffer) {
			working.push(arr[pos]);
			pos++;
		}
		working.push(buffer);
		if (working.size() < 2 && pos <= n) {
			working.push(arr[pos]);
			pos++;
		}
	}
	cout << working.front() << endl;
	
	return 0;
}
