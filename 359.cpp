#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Mem {
	int op;
	int num;
	void process(const string& str) {
		op = (str[0] - 48) * 4 + (str[1] - 48) * 2 + str[2] - 48;
		num = (str[3] - 48) * 16 + (str[4] - 48) * 8 + (str[5] - 48) * 4 + (str[6] - 48) * 2 + str[7] - 48;
	}
};

Mem mem[32];
int acc;
int pc;

void print() {
	cout << "-----------\n";
	cout << pc << endl;
	cout << mem[pc].op << " " << mem[pc].num << endl;
	cout << acc / 32 << " " << acc % 32 << endl;
	cout << "-----------\n";
}

int main() {
	
	freopen("/Users/xdd44/Documents/Code/359/sample.in", "r", stdin);
	
	string str;
	while (cin >> str) {
		mem[0].process(str);
		for (int i=1;i<32;i++) {
			cin >> str;
			mem[i].process(str);
		}
		
		acc = 0;
		pc = 0;
		
		bool done = false;
		while (!done) {
			switch (mem[pc].op) {
				case 0:
					mem[mem[pc].num].op = acc / 32;
					mem[mem[pc].num].num = acc % 32;
					pc++;
					break;
				case 1:
					acc = mem[mem[pc].num].op * 32 + mem[mem[pc].num].num;
					pc++;
					break;
				case 2:
					if (acc == 0) {
						pc = mem[pc].num;
					}
					else {
						pc++;
					}
					break;
				case 3:
					pc++;
					break;
				case 4:
					if (acc == 0) {
						acc = 255;
					}
					else {
						acc--;
					}
					pc++;
					break;
				case 5:
					acc++;
					acc %= 256;
					pc++;
					break;
				case 6:
					pc = mem[pc].num;
					break;
				case 7:
					done = true;
					break;
			}
			pc %= 32;
		}
		cout
		<< acc / 128
		<< (acc % 128) / 64
		<< (acc % 64) / 32
		<< (acc % 32) / 16
		<< (acc % 16) / 8
		<< (acc % 8) / 4
		<< (acc % 4) / 2
		<< acc % 2
		<< endl;
	}
	return 0;
}
