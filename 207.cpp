#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct plc {
	string name = "";
	int index;
	bool confirmed;
	int adj[200];
	int adjDist[200];
	int adjCount = 0;
	int previous;
	int dist;
};

struct compare {
	bool operator()(const plc &a, const plc &b){
		return a.dist > b.dist;
	}
};

plc* place;
int n;
int office;
int hall;
int ans;
string routine;

void init() {
	for (int i = 0; i < n; i++) {
		place[i].index = i;
		place[i].confirmed = false;
		place[i].dist = 2147483647;
	}
}

void print(int start, int end) {
	if (place[end].previous != start) {
		print(start, place[end].previous);
	}
	routine = routine + " -> " + place[end].name;
}

void seperate(const string& line, int& place1, int& place2, int& dist1, int& dist2) {
	for (int i = 0; i < n; i++) {
		bool isThis = true;
		for (int j = 0; j < place[i].name.length(); j++) {
			if (place[i].name[j] != line[j]) {
				isThis = false;
				break;
			}
		}
		if (isThis) {
			place1 = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		bool isThis = true;
		for (int j = 0; j < place[i].name.length(); j++) {
			if (place[i].name[j] != line[j + place[place1].name.length() + 1]) {
				isThis = false;
				break;
			}
		}
		if (isThis) {
			place2 = i;
			break;
		}
	}
	int pos = place[place1].name.length() + place[place2].name.length() + 2;
	dist1 = 0;
	dist2 = 0;
	while (pos < line.length() && line[pos] != ' ') {
		dist1 = dist1 * 10 + int(line[pos++]) - 48;
	}
	if (pos < line.length()) {
		pos++;
		while (pos < line.length()) {
			dist2 = dist2 * 10 + int(line[pos++]) - 48;
		}
	}
	else {
		dist2 = -1;
	}
}

int main() {
	cin >> caseNum;
	for (int c=0;c<caseNum;c++) {
		ans = 0;
		place = new plc[n];
		for (int i = 0; i < n; i++) {
			getline(cin, place[i].name);
			if (place[i].name == "office") {
				office = i;
			}
			if (place[i].name == "hall") {
				hall = i;
			}
		}
		init();
		int m;
		cin >> m;
		getline(cin, whyOnEarthMustGetlineGetTheFuckingNewLineCharacter);
		for (int i = 0; i < m; i++) {
			string line;
			int place1, place2, dist1, dist2;
			getline(cin, line);
			seperate(line, place1, place2, dist1, dist2);
			place[place1].adj[place[place1].adjCount] = place2;
			place[place1].adjDist[place[place1].adjCount++] = dist1;
			if (dist2 > -1) {
				place[place2].adj[place[place2].adjCount] = place1;
				place[place2].adjDist[place[place2].adjCount++] = dist2;
			}
		}

		priority_queue<plc, vector<plc>, compare> pq;
		place[office].dist = 0;
		pq.push(place[office]);
		while (!pq.empty()) {
			plc t = pq.top();
			pq.pop();
			if (t.index == hall) {
				print(office, hall);
				ans += t.dist;
				break;
			}
			if (place[t.index].confirmed) {
				continue;
			}
			place[t.index].confirmed = true;
			for (int i = 0; i < t.adjCount; i++) {
				if (t.adjDist[i] + t.dist < place[t.adj[i]].dist) {
					place[t.adj[i]].dist = t.adjDist[i] + t.dist;
					place[t.adj[i]].previous = t.index;
					pq.push(place[t.adj[i]]);
				}
			}
		}
		
		while (!pq.empty()) {
			pq.pop();
		}
		init();
		place[hall].dist = 0;
		pq.push(place[hall]);
		while (!pq.empty()) {
			plc t = pq.top();
			pq.pop();
			if (t.index == office) {
				print(hall, office);
				ans += t.dist;
				cout << ans << endl << routine << endl << endl;
				break;
			}
			if (place[t.index].confirmed) {
				continue;
			}
			place[t.index].confirmed = true;
			for (int i = 0; i < t.adjCount; i++) {
				if (t.adjDist[i] + t.dist < place[t.adj[i]].dist) {
					place[t.adj[i]].dist = t.adjDist[i] + t.dist;
					place[t.adj[i]].previous = t.index;
					pq.push(place[t.adj[i]]);
				}
			}
		}


		delete[] place;
	}
}