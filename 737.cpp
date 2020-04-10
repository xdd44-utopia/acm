#include<iostream>
#include<string>

using namespace std;

class Node {
private:
	string data;
	int count = 0;
	Node* next;
public:
	Node(const string& str) {
		data = str;
		count++;
	}
	bool isBigger(const string& str) {
		if (str == "!!!ThisIsEnd") {
			return true;
		}
		if (data == str) {
			return true;
		}
		int pos = 0;
		while (1) {
			if (pos == data.length() && pos < str.length()) {
				return true;
			}
			else if (pos < data.length() && pos == str.length()) {
				return false;
			}
			else if (data[pos] < str[pos]) {
				return true;
			}
			else if (data[pos] > str[pos]) {
				return false;
			}
			else {
				pos++;
			}
		}
	}
	bool isSame(const string& str) {
		if (data == str) {
			count++;
			return true;
		}
		else {
			return false;
		}
	}
	Node* getNext() {
		return next;
	}
	string getData() {
		return data;
	}
	int getCount() {
		return count;
	}
	void setNext(Node* tnode) {
		next = tnode;
	}
};
class List {
private:
	Node* first;
public:
	List() {
		first = new Node("");
		first->setNext(new Node("!!!ThisIsEnd"));
	}
	void insert(Node* tnode) {
		Node* p = first;
		while (!tnode->isBigger(p->getNext()->getData())) {
			p = p->getNext();
		}
		if (!p->getNext()->isSame(tnode->getData())) {
			tnode->setNext(p->getNext());
			p->setNext(tnode);
		}
	}
	void print() {
		Node* p = first->getNext();
		while (p->getData() != "!!!ThisIsEnd") {
			cout << p->getData() << " " << p->getCount() << endl;
			p = p->getNext();
		}
	}
};
int main() {
	string str;
	Node* input;
	List* ls = new List();
	while (cin >> str) {
		if (str == "!") break;
		input = new Node(str);
		ls->insert(input);
	}
	ls->print();
	system("pause");
	return 0;
}