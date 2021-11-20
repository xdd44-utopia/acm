#include <iostream>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	int* arr = new int[n];
	int* ans1 = new int[n];
	int* ans2 = new int[n];
	int* nex = new int[n+2];
	int* pre = new int[n+2];
	
	for (int i=0;i<=n+1;i++) {
		nex[i] = i + 1;
		pre[i] = i - 1;
	}
	
	for (int i=0;i<n;i++) {
		cin >> arr[i];
	}
	for (int i=n-1;i>=0;i--) {
		ans1[i] = pre[arr[i]];
		ans2[i] = nex[arr[i]];
		int next = nex[arr[i]];
		nex[pre[arr[i]]] = next;
		pre[next] = pre[arr[i]];
	}
	
	for (int i=0;i<n;i++) {
		cout << ans1[i] << " " << ans2[i] << endl;
	}
	
	delete[] arr;
	delete[] ans1;
	delete[] ans2;
	delete[] nex;
	delete[] pre;
	return 0;
}
