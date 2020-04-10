#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int* heap = new int[250000];
		memset(heap, 0, sizeof(int) * 250000);

		char cmd;
		int count = 1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> cmd;
			int pos;
			switch (cmd) {
			case 'a':
				cin >> heap[count];
				sum += heap[count];
				pos = count;
				while (pos > 1 && heap[pos / 2] < heap[pos]) {
					int t = heap[pos];
					heap[pos] = heap[pos / 2];
					heap[pos / 2] = t;
					pos /= 2;
				}
				count++;
				break;
			case 'p':
				/*
				cout << "pop " << heap[1] << endl;
				for (int j = 0; j < count; j++) {
					cout << heap[j] << " ";
				}
				cout << endl;
				*/
				sum -= heap[1];
				heap[1] = heap[count - 1];
				count--;
				pos = 1;
				while (pos * 2 < count && (heap[pos * 2] > heap[pos] || heap[pos * 2 + 1] > heap[pos])) {
					int tar = pos * 2;
					if (tar + 1 < count && heap[tar + 1] > heap[tar]) {
						tar++;
					}
					int t = heap[tar];
					heap[tar] = heap[pos];
					heap[pos] = t;
					pos = tar;
				}
				break;
			case 'r':
				cout << sum << endl;
				break;
			}
		}

		delete[] heap;
	}
	return 0;
}