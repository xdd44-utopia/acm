#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y;
};

Point* points;
Point origin;


int orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	return val > 0 ? 1 : (val < 0 ? -1 : 0); //val = 0 linear, val = 1 right, val = -1 left
}

bool cmp(Point a, Point b) {
	return orientation(origin, a, b) < 0;
}

bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}


double angle(Point p, Point q, Point r) {
	Point a;
	a.x = q.x - p.x;
	a.y = q.y - p.y;
	Point b;
	b.x = r.x - q.x;
	b.y = r.y - q.y;

	return (double)(a.x * b.x + a.y * b.y) / sqrt((double)(a.x * a.x + a.y * a.y)) / sqrt((double)(b.x * b.x + b.y * b.y));
}

double crossProduct(Point a, Point b) {
	return (double)(a.x * b.y - a.y * b.x);
}

int main() {
	int n;
	int caseNum = 0;
	while (cin >> n) {
		caseNum++;
		if (n == 0) {
			break;
		}

		double area = 0;

		points = new Point[n];
		int minx = 2147483647;
		int miny = 2147483647;
		int mini = 0;
		for (int i = 0; i < n; i++) {
			cin >> points[i].x >> points[i].y;
			if (i > 0) {
				area += crossProduct(points[i], points[i - 1]) / 2;
			}
			if (points[i].y < miny || (points[i].y == miny && points[i].x < minx)) {
				minx = points[i].x;
				miny = points[i].y;
				mini = i;
			}
		}
		area += crossProduct(points[0], points[n - 1]) / 2;
		area = abs(area);
		origin = points[mini];
		points[mini] = points[--n];

		sort(points, points + n, cmp);

		stack<Point> stk;

		stk.push(origin);
		stk.push(points[0]);

		for (int i = 1; i < n; i++) {
			if (((double)(points[i].y - origin.y)) / ((double)(points[i].x - origin.x)) == ((double)(stk.top().y - origin.y)) / ((double)(stk.top().x - origin.x))) {
				if ((points[i].x - origin.x) * (points[i].x - origin.x) + (points[i].y - origin.y) * (points[i].y - origin.y) > (stk.top().x - origin.x) * (stk.top().x - origin.x) + (stk.top().y - origin.y) * (stk.top().y - origin.y)) {
					stk.pop();
				}
				else {
					continue;
				}
			}
			Point q = stk.top();
			stk.pop();
			Point p = stk.top();
			stk.pop();
			while (orientation(p, q, points[i]) > 0) {
				q = p;
				p = stk.top();
				stk.pop();
			}
			stk.push(p);
			stk.push(q);
			stk.push(points[i]);
		}

		n = stk.size();
		delete[] points;
		points = new Point[n];
		for (int i = n - 1; i >= 0; i--) {
			points[i] = stk.top();
			stk.pop();
		}

		double containerArea = 0;

		for (int i = 0; i < n; i++) {
			containerArea += crossProduct(points[i], points[(i + 1) % n]) / 2;
		}

		double ans = (containerArea - area) / containerArea * 100;
		printf("Tile #%d\n", caseNum);
		printf("Wasted Space = %.2lf %%\n\n", ans);

		delete[] points;

	}

	return 0;
}