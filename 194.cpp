#include<iostream>
#include<stdio.h>
using namespace std;

int row, col;
int plc[8];
int solNum;

bool valid(int r, int c) {
	for (int i = 0; i < 8; i++) {
		if (plc[i] != -1 && i != c && (r == plc[i] || c - r == i - plc[i] || c + r == i + plc[i])) {
			return false;
		}
	}
	return true;
}

void f(int dep) {
	if (dep == 8) {
		printf("%2d     ", ++solNum);
		for (int i = 0; i < 8; i++) {
			cout << " " << plc[i]+1;
		}
		cout << endl;
	}
	else {
		if (dep == col) {
			f(dep + 1);
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (valid(i, dep)) {
					plc[dep] = i;
					f(dep + 1);
					plc[dep] = -1;
				}
			}
		}
	}
}



int main() {
	int caseNum;
	bool first = true;
	cin >> caseNum;
	for (int c = 0; c < caseNum; c++) {
		cin >> row >> col;
		row--; col--;
		solNum = 0;
		for (int i = 0; i < 8; i++) {
			plc[i] = -1;
		}
		plc[col] = row;
		if (!first) {
			cout << endl;
		}
		first = false;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";
		f(0);
	}
	return 0;
}