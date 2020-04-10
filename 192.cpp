#include <iostream>
using namespace std;

bool equi;

int weight(int wl, int dl, int wr, int dr) {
	if (wl == 0) {
		int twl, tdl, twr, tdr;
		cin >> twl >> tdl >> twr >> tdr;
		wl = weight(twl, tdl, twr, tdr);
		if (wl == -1) {
			equi = false;
		}
	}
	if (wr == 0) {
		int twl, tdl, twr, tdr;
		cin >> twl >> tdl >> twr >> tdr;
		wr = weight(twl, tdl, twr, tdr);
		if (wr == -1) {
			equi = false;
		}
	}
	if (wl * dl == wr * dr) {
		return wl + wr;
	}
	else {
		equi = false;
		return -1;
	}
}

int main() {
	int caseNum;
	bool first = true;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		equi = true;
		int wl, dl, wr, dr;
		cin >> wl >> dl >> wr >> dr;
		int tw = weight(wl, dl, wr, dr);
		if (first) {
			first = false;
		}
		else {
			cout << endl;
		}
		cout << (equi ? "YES" : "NO") << endl;
	}
	system("pause");
	return 0;
}