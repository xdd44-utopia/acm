#include<iostream>
#include<algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

struct rect {
	point topLeft;
	point bottomRight;
};

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
	int o1 = orientation(a.topLeft, a.bottomRight, b.topLeft);
	int o2 = orientation(a.topLeft, a.bottomRight, b.bottomRight);
	int o3 = orientation(b.topLeft, b.bottomRight, a.topLeft);
	int o4 = orientation(b.topLeft, b.bottomRight, a.bottomRight);

	if (o1 != o2 && o3 != o4)
		return true;

	if ((o1 == 0 && onSegment(a.topLeft, b.topLeft, a.bottomRight)) || 
		(o2 == 0 && onSegment(a.topLeft, b.bottomRight, a.bottomRight)) ||
		(o3 == 0 && onSegment(b.topLeft, a.topLeft, b.bottomRight)) ||
		(o4 == 0 && onSegment(b.topLeft, a.bottomRight, b.bottomRight))) {
		return true;
	}

	return false; 
}

int main() {
	int caseNum;
	cin >> caseNum;

	for (int c = 0; c < caseNum; c++) {
		int n;
		cin >> n;
		bool* isIso = new bool[n];
		rect* rects = new rect[n];
		for (int i = 0; i < n; i++) {
			isIso[i] = true;
			cin >> rects[i].topLeft.x >> rects[i].topLeft.y >> rects[i].bottomRight.x >> rects[i].bottomRight.y;
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (isCollide(rects[i], rects[j])) {
					isIso[i] = false;
					isIso[j] = false;
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (isIso[i]) {
				ans++;
			}
		}

		cout << ans << endl;

		delete[] isIso;
		delete[] rects;
		
	}

	return 0;
}