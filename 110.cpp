#include <iostream>
#include <string>

using namespace std;

int main() {

	string input, str, longestStr;
	int longest = 0;
	while (getline(cin, input)) {
		input = input + " ";
		str = "";
		for (int i = 0; i < input.length(); i++) {
			if (!((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122) || input[i] == '-')) {
				if (str.length() > longest) {
					longest = str.length();
					longestStr = str;
				}
				if (str == "E-N-D") {
					break;
				}
				str = "";
			}
			else {
				str = str + input[i];
			}
		}
		if (str == "E-N-D") {
			break;
		}
	}

	for (int i = 0; i < longestStr.length(); i++) {
		cout << ((longestStr[i] >= 65 && longestStr[i] <= 90) ? (char)(longestStr[i] + 32) : (char)longestStr[i]);
	}

	cout << endl;

	return 0;

}