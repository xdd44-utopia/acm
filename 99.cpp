#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double inter[300][1500];

int main() {

	int n;
	while (1) {
		cin >> n;
		if (!n) {
			break;
		}

		for (int i = 0; i < n; i++) {
			double x, y, rad;
			cin >> x >> y >> rad;
			for (int j = 0; j < 1440; j++) {
				double angle = (double)j / 4;
				angle = angle * 3.14159265 / 180;
				double chord;
				if ((x*500*cos(angle) + y*500*sin(angle))/sqrt(x*x+y*y)/500 <= 0) {
					chord = 0;
				}
				else {
					double k = tan(angle);
					double dist = abs(k * x - y) / sqrt(k * k + 1);
					if (dist >= rad) {
						chord = 0;
					}
					else {
						chord = sqrt(rad * rad - dist * dist);
					}
				}
				if (x * x + y * y > 250000) {

				}
				inter[i][j] = chord * 2;
			}
		}

		double ans = 0;
		for (int i = 0; i < 1440; i++) {
			double sum = 0;
			for (int j = 0; j < n; j++) {
				sum += inter[j][i];
			}
			ans = ans > sum ? ans : sum;
		}

		cout << fixed;
		cout << setprecision(3) << ans << endl;
	}
	return 0;
}