#include <iostream>
#include <string>

using namespace std;

int main() {
	
	int caseNum;
	cin >> caseNum;
	
	while (caseNum--) {
		string str1;
		string str2;
		cin >> str1;
		cin >> str2;
		int len1 = (int)str1.length();
		int len2 = (int)str2.length();
		
		int f[1005][1005];
		for (int i=0;i<=len1;i++) {
			for (int j=0;j<=len2;j++) {
				if (i==0) {
					f[i][j] = j;
				}
				else if (j==0) {
					f[i][j] = i;
				}
				else if (str1[i-1] == str2[j-1]) {
					f[i][j] = f[i-1][j-1] + 1;
				}
				else {
					f[i][j] = (f[i-1][j] < f[i][j-1] ? f[i-1][j] : f[i][j-1]) + 1;
				}
			}
		}
		
		cout << f[len1][len2] << endl;
	}
	
	return 0;
}
