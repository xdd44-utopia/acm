#include <iostream>
#include <string>
using namespace std;

int getMax(const string& sample, int pos) {
	if (pos == sample.length()) return pos;
	int max = 0;
	int maxpos = 0;
	for (int i = pos; i < sample.length(); i++) {
		if (max < sample[i]) {
			max = sample[i];
			maxpos = i;
		}
	}
	return maxpos;
}

int main() {
	int n;
	cin >> n;
	string sample;
	getline(cin, sample);
	for (int c = 0; c < n; c++) {
		string result = "";
		int pos = 0;
		getline(cin, sample);
		while (getMax(sample, pos) < sample.length()) {
			pos = getMax(sample, pos);
			result = result + sample[pos];
			pos++;
		}
		cout << result << endl;
	}
	return 0;
}