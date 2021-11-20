#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	
	freopen("/Users/xdd44/Documents/Code/259/test.in", "r", stdin);
	
	int caseNum;
	string str;
	bool firstCase = true;
	
	cin >> caseNum;
	getline(cin, str);
	
	while (caseNum--) {
		getline(cin, str);
		getline(cin, str);
		
		int n = (int)str.length();
		
		int f[1005][1005];
		for (int i=0;i<n;i++) {
			f[i][i] = 2;
		}
		for (int i=0;i<n-1;i++) {
			if ((str[i] == '(' && str[i+1] == ')') ||
				(str[i] == '[' && str[i+1] == ']') ||
				(str[i] == '{' && str[i+1] == '}')) {
				f[i][i+1] = 2;
			} else {
				f[i][i+1] = 4;
			}
		}
		
		for (int i=2;i<n;i++) {
			for (int j=0;j<n-i;j++) {
				f[j][j+i] = 2147483647;
				for (int k=j;k<j+i;k++) {
					f[j][j+i] = f[j][j+i] < f[j][k] + f[k+1][j+i] ? f[j][j+i] : f[j][k] + f[k+1][j+i];
				}
				if ((str[j] == '(' && str[j+i] == ')') ||
					(str[j] == '[' && str[j+i] == ']') ||
					(str[j] == '{' && str[j+i] == '}')) {
					f[j][j+i] = f[j][j+i] < f[j+1][j+i-1] + 2 ? f[j][j+i] : f[j+1][j+i-1] + 2;
				}
			}
		}
		
		if (firstCase) {
			firstCase = false;
		}
		else {
			cout << endl;
		}
		cout << f[0][n-1] << endl;
		
	}
	
	return 0;
}
