#include <iostream>
#include<string>
using namespace std;


class Telefon
{

private:

	string marca;
	string model;
	int memorie;

public:

	string get_marca() { return marca; }
	string get_model() { return model; }
	int get_memorie() { return memorie; }

	void set_marca(string m) { marca = m; }
	void set_model(string m) { model = m; }
	void set_memorie(int m) { memorie = m; }

	Telefon():marca{"anonima"}, model{"anonim"}, memorie{0}{}

	Telefon(string marc, string mod, int mem):marca{marc}, model{mod}, memorie{mem}{}

	Telefon(string prp) {

		string v[4];
		int k = -1;
		int poz = prp.find(',');

		while (poz != string::npos) {

			k++;
			v[k] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}

		v[2] = prp;

		marca = v[0];
		model = v[1];
		memorie = stoi(v[2]);
	}

	virtual string describe() {

		string text = "";
		text = "\nMarca : " + marca;
		text += "\nModel : " + model;
		text += "\nMemorie : " + to_string(memorie) + " GB";
		text += "\n";

		return text;
	}


	//suprascriem operatorii de comparare
	bool operator< (Telefon t) {

		return (this->memorie < t.memorie);
	}

	bool operator== (Telefon t) {

		return (this->marca == t.marca && this->model == t.model && this->memorie == t.memorie);
	}//equals


	friend ostream& operator<<(ostream& os, const Telefon& t) {


		string text = "";
		text = "\nMarca : " + t.marca;
		text += "\nModel : " + t.model;
		text += "\nMemorie : " + to_string(t.memorie) + " GB";
		text += "\n";

		os << text;

		return os;
	}



};

