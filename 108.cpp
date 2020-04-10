#include<iostream>
#include<string>

using namespace std;

class Node {
private:
	string name;
	int year, month, day;
	Node *next;
public:
	Node(const string& n, int y, int m, int d) {
		name = n;
		year = y;
		month = m;
		day = d;
	}
	bool isYounger(Node *tnode) {
		if (year < tnode->getYear()) {
			return false;
		}
		else if (year > tnode->getYear()) {
			return true;
		}
		else if (month < tnode->getMonth()) {
			return false;
		}
		else if (month > tnode->getMonth()) {
			return true;
		}
		else if (day < tnode->getDay()) {
			return false;
		}
		else {
			return true;
		}
	}
	string getName() {
		return name;
	}
	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node* tnode) {
		next = tnode;
	}
};

class List {
private:
	Node *first;
public:
	List() {
		first = new Node("233", 99999, 99999, 99999);
		first->setNext(new Node("233", 0, 0, 0));
	}
	void insert(Node * tnode) {
		Node *p = first;
		while (p->getNext() != NULL && p->getNext()->isYounger(tnode)) {
			p = p->getNext();
		}
		tnode->setNext(p->getNext());
		p->setNext(tnode);
	}
	void print() {
		Node *p = first->getNext();
		cout << p->getName() << endl;
		while (p->getNext()->getDay() != 0) {
			p = p->getNext();
		}
		cout << p->getName() << endl;
	}
};

int main() {
	List* people = new List();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int year, month, day;
		cin >> name >> day >> month >> year;
		Node* person = new Node(name, year, month, day);
		people->insert(person);
	}
	people->print();
	return 0;
}