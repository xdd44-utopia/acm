#include <iostream>
#include <algorithm>

using namespace std;

const int N = 65536;
int num_prime = 0;
int isNotPrime[N] = {1, 1};
int prime[N];

unsigned long long list[70000];

bool cmp(unsigned long long a, unsigned long long b) {
	return a < b;
}

int main() {
	
	for(int i = 2 ; i < N ; i ++)
	{
		if(! isNotPrime[i]) {
			prime[num_prime++] = i;
		}
		for(long j = 0 ; j < num_prime; j++)
		{
			if (1LL * i * prime[j] >= N ) {
				break;
			}
			isNotPrime[i * prime[j]] = 1;
			if( !(i % prime[j] ) )
				break;
		}
	}
	
	isNotPrime[0] = false;
	isNotPrime[1] = false;
	
	int count = 0;
	for (int i = 2; i < 65536; ++ i) {
		unsigned long long ans = 1LL;
		unsigned long long a1 = 0LL, a2 = 1LL;
		for (int j = 1; j < 64; ++ j) {
			ans = ans * i;
			a1 = a1 * i;
			a2 = a2 * i;
			if (a2 > 10000000000LL) {
				a1 += a2/10000000000LL;
				a2 = a2%10000000000LL;
			}
			if (isNotPrime[j]) {
				if (a1 < 1844674407LL || (a1 == 1844674407LL && a2 < 3709551616LL)) {
					list[count ++] = ans;
				}
				else {
					break;
				}
			}
		}
	}
	list[count++] = 1;
	
	sort(list, list+count, cmp);
	
	cout << list[0] << endl;
	for (int i = 1; i < count; ++ i) {
		if (list[i] != list[i-1]) {
			cout << list[i] << endl;
		}
	}
	
	return 0;
}
