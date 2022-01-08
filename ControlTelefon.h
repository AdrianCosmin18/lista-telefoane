#include"Telefon_DualSim.h"
#include<fstream>
#include<ctype.h>
class ControlTelefon
{
private:
	List* list;

public:

	ControlTelefon() {

		list = new List();
		load();
	}

	void load() {

		ifstream f("telefoane.txt");
		while (!f.eof()) {

			string m;
			getline(f, m);
			if (m != "") {

				if (isalpha(m[m.length() - 1])) {

					list->add(new Telefon_DualSim(m));
				}
				else {

					list->add(new Telefon(m));
				}
				
			}
		}
	}

	void traverse() {

		Node* itr = list->get_head();

		while (itr != NULL) {

			try {

				Telefon_DualSim* td = (Telefon_DualSim*)itr->get_telefon();
				cout << td->describe();
			}
			catch (int n) {
				cout << "nu exista acest telefon";
			}

			itr = itr->get_next();
		}

	}

	void add_telefon(Telefon* t) {

		try {

			Telefon_DualSim* td = (Telefon_DualSim*)t;
			list->add(td);
		}
		catch (int n) {
			
			list->add(t);
		}
	}

	void remove(string marca, string model) {

		int index = list->indexOf(marca, model);
		
		if (index == 0) {

			list->remove_first();
		}
		else if(index != -1){

			list->remove(index);
		}
		else {

			cout << "\nNu exista acest telefon";
		}
	}

	void modify(string marca, string model, int memorie, bool dual_sim) {

		int index = list->indexOf(marca, model);
		if(index != -1) {

			Telefon* t_vechi = list->get_telefon(index);
			Telefon_DualSim* t_nou = new Telefon_DualSim(marca, model, memorie, dual_sim);
			list->replace(t_nou, index);
		}
		else {

			cout << "\nNu exista aceast telefon";
		}
	}

	Telefon* GetTelefonByMarcaAndModel(string marca, string model) {

		int index = list->indexOf(marca, model);

		if (index != -1) {

			return list->get_telefon(index);
		}
		else
			return NULL;

	}
};

