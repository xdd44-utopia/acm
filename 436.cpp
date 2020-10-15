#include<iostream>

using namespace std;

const long N = 1000000;
long prime[N] = { 0 }, num_prime = 0;
int isNotPrime[N] = { 1, 1 };
int isCircular[N] = { 0 };
int isChecked[N] = { 0 };
int sum[N];

int nextN(int x) {
	int t;
	if (x < 1000) {
		t = (x % 100) * 10 + x / 100;
		return (t >= 100 ? t : -1);
	}
	else if (x < 10000) {
		t = (x % 1000) * 10 + x / 1000;
		return (t >= 1000 ? t : -1);
	}
	else if (x < 100000) {
		t = (x % 10000) * 10 + x / 10000;
		return (t >= 10000 ? t : -1);
	}
	else {
		t = (x % 100000) * 10 + x / 100000;
		return (t >= 100000 ? t : -1);
	}
}

int main()
{
	for (long i = 2; i < N; i++)
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;

		for (long j = 0; j < num_prime && i * prime[j] < N; j++)
		{
			isNotPrime[i * prime[j]] = 1;
			if (!(i % prime[j]))               
				break;
		}
	}

	for (int i = 100; i < N; i++) {
		if (!isChecked[i] && !isNotPrime[i]) {
			int t = i;
			bool isThisCircular = true;
			do {
				isChecked[t] = true;
				if (isNotPrime[t]) {
					isThisCircular = false;
				}
				t = nextN(t);
				if (t == -1) {
					isThisCircular = false;
					break;
				}
			} while (t != i);
			if (isThisCircular) {
				do {
					isCircular[t] = true;
					t = nextN(t);
				} while (t != i);
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt += isCircular[i];
		sum[i] = cnt;
	}

	int x, y;
	while (1) {
		cin >> x;
		if (x == -1) {
			break;
		}
		cin >> y;
		switch (sum[y] - sum[x - 1]) {
		case 0:cout << "No Circular Primes.\n"; break;
		case 1:cout << "1 Circular Prime.\n"; break;
		default:cout << sum[y] - sum[x - 1] << " Circular Primes.\n";
		}
	}

	return 0;
}