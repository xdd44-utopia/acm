#include<iostream>
#include<cstring>
using namespace std;

void print(int* arr, int left, int right) {
	for (int i = left; i < right; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int caseNum;
	cin >> caseNum;

	//cout << sizeof(int) * 10000000 / 1024 << endl;

	for (int c = 0; c < caseNum; c++) {
		int n, mod;
		cin >> n >> mod;
		int* arr = new int[n + 1];
		arr[0] = 0;
		arr[1] = 1;

		int max = 0;
		for (int i = 2; i <= n; i++) {
			arr[i] = (arr[i - 2] % mod + arr[i - 1] % mod) % mod;
			max = max > arr[i] ? max : arr[i];
		}

		int rad = 1024;
		int power[5] = { 0, 10, 20, 30, 40 };
		for (int digit = 0; max / (1 << power[digit]) > 0; digit++) {
			int* radix = new int[rad];
			int* tempArr = new int[n+1];

			memset(radix, 0, sizeof(int)*rad);

			for (int i = 1; i <= n; i++) {
				radix[(arr[i] >> power[digit]) & (rad-1)]++;
			}

			for (int d = 1; d < rad; d++) {
				radix[d] += radix[d - 1];
			}

			for (int i = n; i > 0; i--) {
				tempArr[radix[(arr[i] >> power[digit]) & (rad-1)]--] = arr[i];
			}
			
			memcpy(arr, tempArr, sizeof(int)*(n+1));

			//print(arr, 1, n + 1);

			delete[] radix;
			delete[] tempArr;
		}

		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			long long temp = arr[i] % mod;
			ans = (ans % mod + (temp * (i % mod)) % mod) % mod;
		}
		cout << ans << endl;
		delete[] arr;
	}

	system("pause");
	return 0;
}