#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for (int i=0;i<n;i++) {
		getline(cin, line);
		bool choose = true;
		int sum = 0;
		for (int i=(int)line.length()-1;i>=0;i--) {
			if (line[i] >= 48 && line[i] <= 57) {
				choose = !choose;
				if (choose) {
					int temp = line[i] - 48;
					temp *= 2;
					sum += (temp / 10) + (temp % 10);
				}
			}
		}
		choose = false;
		for (int i=(int)line.length()-1;i>=0;i--) {
			if (line[i] >= 48 && line[i] <= 57) {
				choose = !choose;
				if (choose) {
					int temp = line[i] - 48;
					sum += temp;
				}
			}
		}
		if (sum % 10 == 0) {
			cout << "Valid\n";
		}
		else {
			cout << "Invalid\n";
		}
	}
	return 0;
}
