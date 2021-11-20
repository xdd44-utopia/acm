#include <iostream>
#include <cstring>

using namespace std;

int times[105];
int cycles[105];

int main() {
	while (1) {
		int n = 0;
		int s = 2147483647;
		int temp;
		memset(times, 0, sizeof(int) * 105);
		memset(cycles, 0, sizeof(int) * 105);
		while (cin >> temp) {
			if (temp == 0) {
				break;
			}
			else {
				cycles[n++] = temp;
				s = s < temp ? s : temp;
			}
		}
		if (cycles[0] == 0) {
			break;
		}
		
		bool done = false;
		while (s <= 18000 && !done) {
			done = true;
			for (int i=0;i<n;i++) {
				while (times[i] + cycles[i] - 5 <= s) {
					times[i] += 2 * cycles[i];
				}
				if (!(times[i] <= s && s < times[i]+cycles[i]-5)) {
					s = times[i] - 1;
					done = false;
					break;
				}
			}
			s++;
		}
		if (!done) {
			cout << "Signals fail to synchronise in 5 hours\n";
		}
		else {
			s--;
			int hh = s / 3600;
			int mm = s % 3600 / 60;
			int ss = s % 60;
			if (hh < 10) {
				cout << '0';
			}
			cout << hh;
			cout << ':';
			
			if (mm < 10) {
				cout << '0';
			}
			cout << mm;
			cout << ':';
			
			if (ss < 10) {
				cout << '0';
			}
			cout << ss;
			cout << endl;
			
		}
	}
	return 0;
}
