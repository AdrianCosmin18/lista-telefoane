#include"iList.h"


class Node
{
private:
	Telefon* t;
	Node* next;

public:

	Telefon* get_telefon() { return t; }
	Node* get_next() { return next; }

	void set_telefon(Telefon* tel) { t = tel; }
	void set_next(Node* n) { next = n; }
};

