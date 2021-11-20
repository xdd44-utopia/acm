#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const long N = 1300000;
int num_prime = 0;
int isNotPrime[N] = {1, 1};
int prime[N];

int main()
{
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
	
	int n;
	while(scanf("%d",&n) && n)
	{
		if(!isNotPrime[n]) {
			printf("0\n");
			continue;
		}
		n=lower_bound(prime+1,prime+num_prime+1,n)-prime-1;
		printf("%d\n",prime[n+1]-prime[n]);
	}
	
	return 0;
}
