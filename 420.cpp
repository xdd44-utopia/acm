#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

const double eps=1e-6;

int dcmp(double x){if(fabs(x)<eps)return 0;return (x>0)?1:-1;}

int main() {
	
	freopen("/Users/xdd44/Documents/Code/test/test/points.txt", "r", stdin);
	
	double d;
	double px, py, vx, vy;
	
	while (cin >> d) {
		if (d == 0) {
			break;
		}
		cin >> px >> py >> vx >> vy;
		if (dcmp(px * vy - vx * py) == 0) {
			if (px * vx + py * vy > 0) {
				if (dcmp(d - 2 + sqrt(px * px + py * py)) >= 0) {
					cout << "possible\n";
				}
				else {
					cout << "impossible\n";
				}
			}
			else {
				if (dcmp(d - sqrt(px * px + py * py)) >= 0) {
					cout << "possible\n";
				}
				else {
					cout << "impossible\n";
				}
			}
		}
		else {
			cout << "impossible\n";
		}
	}
	
	return 0;
}
