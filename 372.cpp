#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int csNum;
	scanf("%d",&csNum);
	for (int c = 0; c < csNum; c++) {
		int n;
		scanf("%d",&n);
		int* arr = new int[n];
		int highCount = 0;
		int lowCount = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i < n; i++) {
			if (arr[i] > arr[i - 1]) {
				highCount++;
			}
			else if (arr[i] < arr[i-1]){
				lowCount++;
			}
		}
		printf("Case %d: %d %d\n", c + 1, highCount, lowCount);
	}
	return 0;
}