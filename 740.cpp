#include<iostream>
using namespace std;

class Node {
private:
	Node* previous;
	Node* next;
	int data;
public:
	Node(int t) {
		data = t;
	}
	void setNext(Node* t) {
		next = t;
	}
	void setPrevious(Node* t) {
		previous = t;
	}
	Node* getNext() {
		return next;
	}
	Node* getPrevious() {
		return previous;
	}
	int getData() {
		return data;
	}
};

class List {
private:
	Node* first;
	int count = 0;
public:
	List() {
		first = new Node(233);
		first->setNext(new Node(233));
		first->setPrevious(new Node(233));
	}
	void insert(Node* t, int pos) {
		Node* p = first;
		for (int i = 0; i < pos; i++) {
			p = p->getNext();
		}
		t->setPrevious(p);
		t->setNext(p->getNext());
		t->getNext()->setPrevious(t);
		p->setNext(t);
	}
	void remove(int pos) {
		Node* p = first;
		for (int i = 0; i < pos; i++) {
			p = p->getNext();
		}
		p->getPrevious()->setNext(p->getNext());
		p->getPrevious()->getNext()->setPrevious(p->getPrevious());
	}
	void reverse(int s, int t) {
		Node* p = first->getNext();
		Node* tnode;
		Node* start = first;
		for (int i = 1; i < t; i++) {
			if (i == s - 1) {
				start = p;
			}
			if (i >= s) {
				tnode = p->getPrevious();
				p->setPrevious(p->getNext());
				p->setNext(tnode);
				p = p->getPrevious();
			}
			else {
				p = p->getNext();
			}
		}
		p->getNext()->setPrevious(start->getNext());
		start->getNext()->setNext(p->getNext());
		p->setNext(p->getPrevious());
		p->setPrevious(start);
		start->setNext(p);
	}
	void print(int pos) {
		Node* p = first;
		for (int i = 0; i < pos; i++) {
			p = p->getNext();
		}
		cout << p->getData() << endl;
	}
	void printAll() {
		cout << "Print: ";
		Node* p = first->getNext();
		while (p->getData() != 233) {
			cout << p->getData() << " ";
			p = p->getNext();
		}
		cout << endl;
	}
};

int main() {
	int n;
	cin >> n;
	List* ls = new List();
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ls->insert(new Node(t), i);
		//ls->printAll();
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		switch (t) {
		case 1: {
			int pos, data;
			cin >> pos >> data;
			ls->insert(new Node(data), pos);
			break;
		}
		case 2: {
			int pos;
			cin >> pos;
			ls->remove(pos);
			break;
		}
		case 3: {
			int s, e;
			cin >> s >> e;
			ls->reverse(s, e);
			break;
		}
		case 4: {
			int pos;
			cin >> pos;
			ls->print(pos);
			break;
		}
		}

		//ls->printAll();
	}
	system("pause");
	return 0;
}