#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int prime[1000000];
bool visited[1000000];
int cnt;

int main() {
	
	memset(visited, 0, 1000000 * sizeof(bool));
	
	for (int i=2;i<1000000;i++){
		if (!visited[i]) {
			prime[cnt++] = i;
		}
		for (int j=0;j<cnt;j++) {
			if (i * prime[j] >= 1000000) {
				break;
			}
			visited[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
	
	int a, b;
	while (cin >> a >> b) {
		if (a == 0) {
			break;
		}
		int lasta = 0;
		int lastb = 0;
		int cnta = 0;
		int cntb = 0;
		for (int i=0;i<cnt;i++){
			if (a % prime[i] == 0) {
				lasta = prime[i];
				cnta += prime[i];
			}
			if (prime[i] > a) {
				break;
			}
		}
		for (int i=0;i<cnt;i++){
			if (b % prime[i] == 0) {
				lastb = prime[i];
				cntb += prime[i];
			}
			if (prime[i] > b) {
				break;
			}
		}
		if (lasta - (cnta - lasta) > lastb - (cntb - lastb)) {
			cout << "a\n";
		}
		else {
			cout << "b\n";
		}
	}
	
	return 0;
}
