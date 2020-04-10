#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

int n;
int dn;
int x[2000];
int y[2000];
double dist[20500];
short ia[20500];
short ib[20500];
short father[2000];

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void print() {
	cout << "printing\n";
	for (int i = 0; i < dn; i++) {
		cout << ia[i] << " " << ib[i] << " ";
		cout << setprecision(3);
		cout << fixed;
		cout << dist[i] << endl;
	}
}

bool check(short x, short y) {
	short fx = father[x];
	short fy = father[y];
	while (fx != father[fx]) {
		fx = father[fx];
	}
	while (fy != father[fy]) {
		fy = father[fy];
	}
	father[x] = fx;
	father[y] = fy;
	if (fx == fy) {
		return true;
	}
	else {
		return false;
	}
}

void uni(short x, short y) {
	if (!check(x, y)) {
		short fx = father[x];
		short fy = father[y];
		while (fx != father[fx]) {
			fx = father[fx];
		}
		while (fy != father[fy]) {
			fy = father[fy];
		}
		father[fx] = father[fy];
	}
}

void merge(int s, int t) {
	int mid = (s + t) / 2;
	if (s < t) {
		merge(s, mid);
		merge(mid + 1, t);
		int i = 0;
		int j = mid - s + 1;
		short* tempa = new short[t - s + 1];
		short* tempb = new short[t - s + 1];
		double* temp = new double[t - s + 1];
		for (int k = 0; k < t - s + 1; k++) {
			temp[k] = dist[s + k];
			tempa[k] = ia[s + k];
			tempb[k] = ib[s + k];
		}
		int k = s;
		while (k <= t) {
			if (j > t - s || (i <= mid - s && temp[i] <= temp[j])) {
				dist[k] = temp[i];
				ia[k] = tempa[i];
				ib[k] = tempb[i];
				i++;
				k++;
			}
			else if (i > mid - s || (j <= t - s && temp[i] > temp[j])) {
				dist[k] = temp[j];
				ia[k] = tempa[j];
				ib[k] = tempb[j];
				j++;
				k++;
			}
		}
		delete[] tempa;
		delete[] tempb;
		delete[] temp;
	}
}

int main() {
	int caseNum = 0;
	while (1) {
		caseNum++;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		dn = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				dist[dn] = getDist(x[i], y[i], x[j], y[j]);
				ia[dn] = i;
				ib[dn] = j;
				dn++;
			}
		}
		merge(0, dn - 1);
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
		for (int i = 0; i < dn; i++) {
			uni(ia[i], ib[i]);
			if (check(0, 1)) {
				cout << "Scenario #" << caseNum << endl;
				cout << setprecision(3);
				cout << fixed;
				cout << "Frog Distance = " << dist[i] << endl;
				cout << endl;
				break;
			}
		}
	}
	return 0;
}