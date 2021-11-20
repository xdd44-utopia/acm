#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	freopen("/Users/xdd44/Documents/Code/411/test.in", "r", stdin);
	
	int caseNum;
	cin >> caseNum;
	
	for (int c = 1; c <= caseNum; c++) {
		long long n, m;
		int nt[50];
		int mt[50];
		int res;
		vector< vector<int> > cinema;
		cin >> n >> m >> res;
		
		for (int i=0;i<res;i++) {
			cin >> nt[i];
		}
		for (int i=0;i<res;i++) {
			cin >> mt[i];
		}
		
		for (int i=0;i<res;i++) {
			bool found = false;
			for (int j=0;j<cinema.size();j++) {
				if (cinema[j][0] == nt[i]) {
					cinema[j].push_back(mt[i]);
					found = true;
				}
			}
			if (!found) {
				vector<int> tv;
				tv.push_back(nt[i]);
				tv.push_back(mt[i]);
				cinema.push_back(tv);
			}
		}
		
		for (int i=0;i<cinema.size();i++) {
			sort(cinema[i].begin() + 1, cinema[i].end());
		}
		
		long long ans = n * (m - 1);
		for (int i=0;i<cinema.size();i++) {
			for (int j=1;j<cinema[i].size();j++) {
				if (j > 1 || (j == 1 && cinema[i][j] > 1)) {
					ans--;
				}
				if ((j < cinema[i].size() - 1 && cinema[i][j] < cinema[i][j+1] - 1) || (j == cinema[i].size() - 1 && cinema[i][j] < m)) {
					ans--;
				}
			}
		}
		
		cout << "Case #" << c << ": " << ans << endl;
	}
	
	return 0;
}
