#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;i++) {
		double m;
		double avg = 0;
		double arr[10000];
		cin >> m;
		for (int j=0;j<m;j++) {
			cin >> arr[j];
			avg += arr[j];
		}
		avg /= m;
		double cnt = 0;
		for (int j=0;j<m;j++) {
			if (arr[j] > avg) {
				cnt += 1;
			}
		}
		cout << std::fixed << std::setprecision(3) << cnt * 100 / m << "%\n";
	}
	return 0;
}
