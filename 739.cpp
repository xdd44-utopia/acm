#include<iostream>

using namespace std;

class Node {
private:
	int tag;
	Node* next;
public:
	Node(int t) {
		tag = t;
	}
	int getTag() {
		return tag;
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
	Node* first;
	int count = 1;
public:
	List(Node* student){
		first = student;
		first->setNext(first);
	}
	void insert(Node* student, int pos, bool isInit) {
		Node* p = first;
		for (int i = 1; i < pos; i++) {
			p = p->getNext();
		}
		student->setNext(p->getNext());
		p->setNext(student);
		if (!isInit) {
			first = student;
		}
		count++;
	}
	void remove(int pos) {
		Node* p = first;
		for (int i = 1; i < pos - 1; i++) {
			p = p->getNext();
		}
		p->setNext(p->getNext()->getNext());
		first = p->getNext();
		count--;
	}
	void print(int pos) {
		Node* p = first;
		for (int i = 1; i < pos; i++) {
			p = p->getNext();
		}
		cout << p->getTag() << endl;
		first = p;
	}
	void printAll() {
		cout << "Print: ";
		Node* p = first;
		for (int i = 0; i < count; i++) {
			cout << p->getTag() << " ";
			p = p->getNext();
		}
		cout << endl;
	}
	int getCount() {
		return count;
	}
};

int main() {
	int n;
	cin >> n;
	int t;
	cin >> t;
	List* ls = new List(new Node(t));
	for (int i = 1; i < n; i++) {
		cin >> t;
		ls->insert(new Node(t), i, 1);
		ls->printAll();
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ope;
		cin >> ope;
		switch (ope) {
			case 1:{
				int pos, tag;
				cin >> pos >> tag;
				pos = pos % (ls->getCount());
				if (pos == 0) {
					pos = ls->getCount();
				}
				ls->insert(new Node(tag), pos, 0);
				break;
			}
			case 2:{
				int pos;
				cin >> pos;
				pos = pos % (ls->getCount());
				if (pos == 0) {
					pos = ls->getCount();
				}
				ls->remove(pos);
				break;
			}
			case 3:{
				int pos;
				cin >> pos;
				pos = pos % (ls->getCount());
				if (pos == 0) {
					pos = ls->getCount();
				}
				ls->print(pos);
				break;
			}
		}

		ls->printAll();
	}
	system("pause");
	return 0;
}