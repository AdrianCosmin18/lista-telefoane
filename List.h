#include"Node.h"

class List
{
private:
	Node* head = NULL;

public:
	Node* get_head() { return head; }

	void traverse() {

		Node* itr = head;
		while (itr != NULL) {

			cout << (*itr->get_telefon());
			itr = itr->get_next();
		}
	}

	void add_start(Telefon* t) {

		if (head == NULL) {

			head = new Node();
			head->set_telefon(t);
			head->set_next(NULL);
		}
		else {

			Node* node = new Node();
			node->set_telefon(t);
			node->set_next(head);

			head = node;
		}
	}

	Node* get_last_node(){

		Node* itr = head;
		Node* aux = new Node();

		while (itr != NULL) {

			aux = itr;
			itr = itr->get_next();
		}
	
		return aux;
	}

	void add(Telefon* t) {

		

		if (head == NULL) {

			Node* p = new Node();
			p->set_telefon(t);
			p->set_next(NULL);

			head = p;
		}
		else {

			Node* p = new Node();
			p->set_telefon(t);

			Node* privious = new Node();
			privious = get_last_node();
			privious->set_next(p);
		}
	}

	int indexOf(Telefon* t) {

		int poz = -1;
		Node* itr = head;

		while (itr != NULL) {

			poz++;
			if (itr->get_telefon()->operator==(*t)) { 
				
				return poz; 
			}

			itr = itr->get_next();
		}

		return -1;
	}

	int indexOf(string marca, string model) {

		Node* itr = head;
		int poz = -1;

		while (itr != NULL) {

			poz++;
			if (itr->get_telefon()->get_marca() == marca && itr->get_telefon()->get_model() == model) {

				return poz;
			}

			itr = itr->get_next();
		}

		return -1;
	}

	Node* get_node_by_poz(int p) {

		Node* itr = head;
		int poz = -1;

		while (itr != NULL) {

			poz++;
			if (p == poz) {

				return itr;
			}

			itr = itr->get_next();
		}

		return NULL;
	}

	void remove_first() {

		Node* aux = head;
		this->head = this->head->get_next();
		delete aux;
	}

	void remove(int index) {

		Node* aux = get_node_by_poz(index);
		Node* priv = get_node_by_poz(index - 1);

		priv->set_next(aux->get_next());
	}

	void remove(Telefon* t) {

		int index = indexOf(t);
		Node* aux = get_node_by_poz(index);
		Node* priv = get_node_by_poz(index - 1);

		priv->set_next(aux->get_next());
	}

	bool contains(Telefon* t){
	
		Node* itr = head;

		while (itr != NULL) {

			if (itr->get_telefon()->operator==(*t)) {

				return true;
			}

			itr = itr->get_next();
		}
	
		return false;
	}

	bool isEmpty() {

		if (head == NULL) {

			return true;
		}
		return false;
	}

	int size() {

		if (isEmpty()) { return 0; }
		else {

			int count = 0;
			Node* itr = head;

			while (itr != NULL) {

				count++;
				itr = itr->get_next();
			}

			return count;
		}
	}

	Telefon* get_telefon(int index) {

		Node* aux = get_node_by_poz(index);
		return aux->get_telefon();
	}

	void replace(Telefon* t, int index) {

		Node* aux = get_node_by_poz(index);
		aux->set_telefon(t);
	}

	void swap(Node* n1, Node* n2) {

		int poz1 = indexOf(n1->get_telefon());
		int poz2 = indexOf(n2->get_telefon());

		replace(n2->get_telefon(), poz1);
		replace(n1->get_telefon(), poz2);
	}

	//sort dupa memorie
	void sort() {

		int flag = 0;
		do {
			flag = 0;

			for (int i = 0; i < size() - 1; i++) {

				if (get_telefon(i + 1)->operator< (*get_telefon(i)))
				{

					Telefon* aux = get_telefon(i);

					replace(get_telefon(i + 1), i);

					replace(aux, i + 1);

					flag = 1;
				}
			}

		} while (flag == 1);
	}
};

