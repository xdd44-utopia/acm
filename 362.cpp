#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

struct robot {
	int x;
	int y;
};

int flow[210][210];
int residual[210][210];
int augment[210];
robot robots[210];
int len, width, n, d, cnt;
int src, sink;

double dist(robot a, robot b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int findPath() {
	queue<int> q;
	augment[src] = src; //这里我用了一维数组 augment[i]存path中i号节点的前一个节点是几号节点， 之后遍历就是从sink往src走一遍
	q.push(src);
	while (!q.empty()) { //用宽搜 在residual map中寻找一条从起点到终点的augment path
		int t = q.front();
		q.pop();
		//cout << "bfs: " << t << endl;
		if (t == sink) {
			return augment[t];
		}
		for (int i = 0; i < cnt*2+2; i++) {
			if (residual[t][i] > 0 && i != t && augment[i] == -1) {
				augment[i] = t;
				q.push(i);
			}
		}
	}
	return -1;
}

void printResidual() {
	for (int i = 0; i <= cnt*2+1; i++) {
		for (int j = 0; j <= cnt*2+1; j++) {
			cout << residual[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int caseNum = 0;
	while (cin >> len >> width >> n >> d) {
		if (len == 0 && width == 0 && n == 0 && d == 0) {
			break;
		}
		caseNum++;

		cnt = n;
		for (int i = 0; i < cnt; i++) {
			cin >> robots[i].x >> robots[i].y;
		}

		memset(flow, 0, sizeof(flow[0][0]) * 210 * 210);
		memset(residual, 0, sizeof(residual[0][0]) * 210 * 210);
		memset(augment, -1, sizeof(augment[0]) * 210);

		//这边把球场转化成水管

		for (int i = 0; i < cnt; i++) {
			residual[i * 2][i * 2 + 1] = 1;	//考虑到人直接撞过机器人算一次，相当于节点本身有1的权重， 把节点分裂成两个节点和一条1的管道
		}

		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < i; j++) {
				if (dist(robots[i], robots[j]) <= d*d) { //两个机器人特别近的时候从它们中间穿过去一定会被它们俩都打到
					residual[i * 2 + 1][j * 2] = 2;
					residual[j * 2 + 1][i * 2] = 2;
				}
				else if (dist(robots[i], robots[j]) <= 4 * d * d) { //两个机器人不是很近但没有足够远的时候，从它们中间不相交的地方穿过去可以只被打一次
					residual[i * 2 + 1][j * 2] = 1;
					residual[j * 2 + 1][i * 2] = 1;
				}
			}
		}

		src = cnt * 2;
		sink = cnt * 2 + 1;
		int ans = 0;
		for (int i = 0; i < cnt; i++) { //处理贴着场边走过去
			if (robots[i].y <= d) {
				residual[src][i * 2] = 1;
			}
			if (robots[i].y >= width - d) {
				residual[i * 2 + 1][sink] = 1;
			}
		}
		//printResidual();

		while (findPath() >= 0) { //findPath()返回sink在path中的前一个节点序号，所以大于等于0就是存在一条augment path，小于0就说明宽搜没有到达sink，也就是不存在path
			int pos = sink;
			int mincap = 2147483647;
			//cout << "augment:\n";
			while (pos != src) {
				//cout << pos << endl;
				mincap = (mincap < residual[augment[pos]][pos] ? mincap : residual[augment[pos]][pos]); //这边寻找augment path中最小的增量
				pos = augment[pos];
			}
			ans += mincap;
			pos = sink;
			while (pos != src) { //在flow和residual map中更新增量带来的改变
				flow[augment[pos]][pos] += mincap;
				residual[augment[pos]][pos] -= mincap;
				residual[pos][augment[pos]] += mincap;
				pos = augment[pos];
			}
			//printResidual();
			memset(augment, -1, sizeof(augment[0]) * 210);
		}

		cout << "Case " << caseNum << ": " << ans << endl;
	}

	return 0;
}