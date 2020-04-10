#include <iostream>

using namespace std;

class Set {
private:
	int num;
	int* relation;
public:
	Set(int amount) {
		num = amount;
		relation = new int[amount];
		for (int i = 0; i < num; i++) {
			relation[i] = i;
		}
	}
	int Find(int x) {
		int p = relation[x];
		while (p != relation[p]) {
			p = relation[p];
		}
		relation[x] = p;
		return relation[x];
	}
	void Union(int i, int j) {
		if (Find(i) != Find(j)) {
			relation[relation[i]] = relation[relation[j]];
		}
	}
};

int con(int i, int j, int width) {
	return (i - 1)*width + j - 1;
}

int main() {

	int dx[8] = { 0,1,0,-1,1,1,-1,-1 };
	int dy[8] = {1,0,-1,0,1,-1,1,-1};
	int width, height;

	while (true) {
		cin >> width >> height;
		if (width == 0 && height == 0) {
			break;
		}

		Set* islands = new Set(width*height);
		bool map[52][52];
		for (int i = 0; i <= height + 1; i++) {
			for (int j = 0; j <= width + 1; j++) {
				map[i][j] = false;
			}
		}
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				for (int d = 0; d < 8; d++) {
					if (map[i][j] && map[i + dx[d]][j + dy[d]]) {
						islands->Union(con(i, j, width), con(i + dx[d], j + dy[d], width));
					}
				}
			}
		}

		bool* relation = new bool[width*height + 1];
		for (int j = 0; j <= width * height; j++) {
			relation[j] = 0;
		}
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				if (map[i][j]) {
					relation[islands->Find(con(i, j, width))] = true;
				}
			}
		}
		int ans = 0;
		for (int j = 0; j <= width * height; j++) {
			if (relation[j]) {
				ans++;
			}
		}
		cout << ans << endl;
		delete[] relation;
		delete islands;
	}
	system("pause");
	return 0;
}