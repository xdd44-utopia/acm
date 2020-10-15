#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string strs[100000];

int main() {
	int cnt = 0;
	string input;
	while (getline(cin, input)) {
		input = input + " ";
		string str = "";
		for (int i = 0; i < input.length(); i++) {
			if (!((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122))) {
				strs[cnt++] = str;
				if (str == "end") {
					break;
				}
				str = "";
			}
			else {
				if (input[i] >= 65 && input[i] <= 90) {
					str = str + (char)(input[i] + 32);
				}
				else {
					str = str + input[i];
				}
			}
		}
		if (str == "end") {
			break;
		}
	}
	sort(strs, strs + cnt);
	cout << strs[0];
	for (int i = 1; i < cnt; i++) {
		if (strs[i] != strs[i - 1]) {
			cout << strs[i] << endl;
		}
	}

	return 0;
}