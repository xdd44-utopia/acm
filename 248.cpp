#include<iostream>
#include<algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

struct rect {
	point start;
	point end;
};

/*

bool isCollide(const rect& a, const rect& b) { //rects
	if ((a.start.x > b.end.x) || (a.end.x < b.start.x) || (a.start.y > b.end.y) ||
		(a.end.y < b.start.y))
	{
		return false;
	}
	else
	{
		return true;
	}
}

*/
bool onSegment(point p, point q, point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

int orientation(point p, point q, point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;

	return (val > 0) ? 1 : 2;
}

bool isCollide(const rect& a, const rect& b) {
	int o1 = orientation(a.start, a.end, b.start);
	int o2 = orientation(a.start, a.end, b.end);
	int o3 = orientation(b.start, b.end, a.start);
	int o4 = orientation(b.start, b.end, a.end);

	if (o1 != o2 && o3 != o4)
		return true;

	if ((o1 == 0 && onSegment(a.start, b.start, a.end)) ||
		(o2 == 0 && onSegment(a.start, b.end, a.end)) ||
		(o3 == 0 && onSegment(b.start, a.start, b.end)) ||
		(o4 == 0 && onSegment(b.start, a.end, b.end))) {
		return true;
	}

	return false;
}

int main() {
	int caseNum;
	cin >> caseNum;

	for (int c = 0; c < caseNum; c++) {
		rect line;
		rect line1, line2, line3, line4;
		int left, right, top, bottom;
		cin >> line.start.x >> line.start.y >> line.end.x >> line.end.y >> left >> top >> right >> bottom;
		if (left > right) {
			swap(left, right);
		}
		if (top < bottom) {
			swap(top, bottom);
		}
		line1.start.x = left;
		line1.start.y = top;
		line1.end.x = right;
		line1.end.y = top;

		line2.start.x = right;
		line2.start.y = top;
		line2.end.x = right;
		line2.end.y = bottom;

		line3.start.x = left;
		line3.start.y = bottom;
		line3.end.x = right;
		line3.end.y = bottom;

		line4.start.x = left;
		line4.start.y = top;
		line4.end.x = left;
		line4.end.y = bottom;
		if (isCollide(line, line1) || isCollide(line, line2) || isCollide(line, line3) || isCollide(line, line4)) {
			cout << "T\n";
		}
		else if (line.start.x > left && line.start.x < right && line.start.y < top && line.start.y > bottom) {
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}
	}

	return 0;
}