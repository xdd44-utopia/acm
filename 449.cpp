#include<iostream>
#include<string>

using namespace std;

int map[52][52];

int calc(int width, int height) {

	int dIO[6] = { 0, 0,-1,-1, 1, 1 };
	int dJO[6] = { -1, 1,-1, 0,-1, 0 };
	int dIE[6] = { 0, 0,-1,-1, 1, 1 };
	int dJE[6] = { -1, 1,1, 0,1, 0 };
	int count = 0;

	for (int i = 0; i <= height + 1; i++) {
		map[i][width + 1] = 1;
	}
	for (int i = 0; i <= width + 1; i++) {
		map[height+1][i] = 1;
	}

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++) {
			for (int d = 0; d < 6; d++) {
				if ((map[i][j] == 1 && map[i + dIO[d]][j + dJO[d]] == 0 && i % 2 == 1) ||
					(map[i][j] == 1 && map[i + dIE[d]][j + dJE[d]] == 0 && i % 2 == 0)) {
					count++;
				}
			}
		}
	}
	return count;
}

int main() {
	int width, height;
	string input;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < 52; i++) {
		map[i][0] = 1;
		map[0][i] = 1;
	}
	height = 0;
	while (getline(cin, input)) {
		if (input == "") {
			cout << calc(width, height) << endl;
			memset(map, 0, sizeof(map));
			for (int i = 0; i < 52; i++) {
				map[i][0] = 1;
				map[0][i] = 1;
			}
			height = 0;
			continue;
		}
		height++;
		width = input.length();
		for (int i = 0; i < width; i++) {
			map[height][i + 1] = (input[i] == '#' ? 1 : 0);
		}
	}
	return 0;
}