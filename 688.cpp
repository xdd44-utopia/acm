#include<iostream>
#include<string>
#include<queue>

using namespace std;

bool map[8][8];

void print() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int caseNum;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		queue<int> x;
		queue<int> y;
		queue<int> dep;
		int tarx, tary;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < 8; i++) {
			string s = "";
			while (s == "" || s == "\n") {
				cin >> s;
			}
			for (int j = 0; j < 8; j++) {
				switch (s[j]) {
				case '#':
					map[i][j] = 1;
					x.push(i);
					y.push(j);
					dep.push(0);
					break;
				case '*':
					map[i][j] = 1;
					break;
				case '@':
					tarx = i;
					tary = j;
					break;
				}
			}
		}

		int dx[8] = { -2,-2,-1,-1,1,1,2,2 };
		int dy[8] = { -1,1,-2,2,-2,2,-1,1 };
		bool success = false;
		while (!x.empty()) {
			//print();
			int posx = x.front();
			int posy = y.front();
			if (posx == tarx && posy == tary) {
				cout << "Case " << c + 1 << ": " << dep.front() << endl;
				success = true;
				break;
			}
			for (int d = 0; d < 8; d++) {
				if (posx + dx[d] >= 0 && posx + dx[d] < 8 && posy + dy[d] >= 0 && posy + dy[d] < 8 && !map[posx + dx[d]][posy + dy[d]]) {
					x.push(posx + dx[d]);
					y.push(posy + dy[d]);
					dep.push(dep.front() + 1);
					map[posx + dx[d]][posy + dy[d]] = 1;
				}
			}
			x.pop();
			y.pop();
			dep.pop();
		}
		if (!success) {
			cout << "Case " << c + 1 << ": " << "IMPOSSIBLE" << endl;
		}
	}

	system("pause");
	return 0;
}