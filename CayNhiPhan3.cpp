#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* pleft;
	Node* pRight;
};

typedef Node* Tree;

Tree makeNode(int x) {
	Node* tmp = new Node();
	tmp->data = x;
	tmp->pleft = NULL;
	tmp->pRight = NULL;
	return tmp;
}

void KhoiTaoCay(Tree& l) {
	l = NULL;
}

bool ktSNT(int x) {
	if (x == 2 || x == 3) return true;
	if (x % 2 == 0 || x % 3 == 0 || x < 2) return false;
	for (int i = 5; i * i <= x; i += 6) {
		if (x % i == 0 || x % (i + 2) == 0) return false;
	}
	return true;
}

void KiemTraTonTai(Tree l, int key, bool &kt) {
	if (l != NULL) {
		if (l->data == key) {
			kt = true;
		}
		else {
			if (l->data > key) KiemTraTonTai(l->pleft, key,kt);
			else if (l->data < key) KiemTraTonTai(l->pRight, key, kt);
		}
	}
	
}

void demSNTtrongCay(Tree l, int &dem) {
	if (l != NULL) {
		if (ktSNT(l->data)) dem++;
		demSNTtrongCay(l->pleft,dem);
		demSNTtrongCay(l->pRight, dem);
	}
}

void addTree(Tree& l, int x) {
	if (l == NULL) {
		Tree p = makeNode(x);
		l = p;
	}
	else {
		if (l->data > x) addTree(l->pleft, x);
		else if (l->data < x) addTree(l->pRight, x);
	}
}

void duyetCay(Tree& l) {
	if (l != NULL) {
		duyetCay(l->pleft);
		cout << l->data << " ";
		duyetCay(l->pRight);
	}
}

void DiTimNodeTheMang(Node*&x, Node*& y) {
	if (y->pleft != NULL) DiTimNodeTheMang(x, y->pleft);
	else {
		x->data = y->data;
		x = y;
		y = y->pRight;
	}
}

void xoaNode(Tree& l, int key) {
	if (l != NULL) {
		if (l->data == key) {
			Node* x = l;
			if (l->pleft == NULL) l = l->pRight;
			else if (l->pRight == NULL) l = l->pleft;
			else {
				DiTimNodeTheMang(x, l->pRight);
			}
			delete x;
		}
		else {
			if (l->data > key) xoaNode(l->pleft, key);
			else if (l->data < key) xoaNode(l->pRight, key);
		}

	}
}

int main() {
	Tree l;
	KhoiTaoCay(l);
	int x;
	while (cin >> x, x != 0) {
		addTree(l, x);
	}
	duyetCay(l);
	cout << "\nNhap gia tri can xoa: ";
	cin >> x;
	xoaNode(l, x);
	cout << endl;
	duyetCay(l);
	
}

