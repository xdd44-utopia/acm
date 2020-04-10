#include <iostream>
#include <cstring>
#define MAX 600
#define RANGE 3500000
//3448275
using namespace std;

int main() {
	int* prime = new int[5761460];
	int* isNotPrime = new int[RANGE];
	memset(isNotPrime, 0, sizeof(int) * RANGE);
	prime[0] = 0;
	//isNotPrime[3] = 1;
	int target;

	for (int i = 3; i <= MAX; i+=2) {
		if (((isNotPrime[i % RANGE] >> (i / RANGE)) & 1) == 0) {
			prime[++prime[0]] = i;
			cout << i << endl;
		}
		for (int j = 1; j <= prime[0] && i*prime[j] <= MAX; j++) {
			isNotPrime[(i*prime[j]) % RANGE] += 1 << (i*prime[j] / RANGE);
			//cout << " " << i*prime[j] << endl;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}

	while (cin >> target) {
		bool success = false;
		if (target <= 4) {
			cout << target << " is not the sum of two primes!" << endl;
			continue;
		}
		if (target % 2 == 1) {
			if (((isNotPrime[(target - 2) % RANGE] >> ((target - 2) / RANGE)) & 1) == 0) {
				cout << target << " is the sum of " << 2 << " and " << target - 2 << "." << endl;
			}
			else {
				cout << target << " is not the sum of two primes!" << endl;
			}
			continue;
		}
		else {
			int start = target / 2;
			if (start % 2 == 0) {
				start++;
			}
			else {
				start += 2;
			}
			for (int i = start; i < target; i += 2) {
				if (((isNotPrime[i % RANGE] >> (i / RANGE)) & 1) == 0 && ((isNotPrime[(target - i) % RANGE] >> ((target - i) / RANGE)) & 1) == 0 && target - i > 2) {
					cout << target << " is the sum of " << target - i << " and " << i << "." << endl;
					success = true;
					break;
				}
			}
			if (!success) {
				cout << target << " is not the sum of two primes!" << endl;
			}
		}
	}
	delete[] prime;
	delete[] isNotPrime;
	return 0;
}