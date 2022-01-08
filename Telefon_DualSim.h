#include"List.h"


class Telefon_DualSim: public Telefon
{
private:

	bool dual_sim;

public:

	bool get_dual_sim() { return dual_sim; }
	void set_dual_sim(bool ds) { dual_sim = ds; }

	Telefon_DualSim():Telefon(), dual_sim{false}{}

	Telefon_DualSim(string marca, string model, int mem, bool dual): Telefon(marca, model, mem), dual_sim{dual}{}

	Telefon_DualSim(string prp) {

		string v[4];
		int k = -1;
		int poz = prp.find(',');

		while (poz != string::npos) {

			k++;
			v[k] = prp.substr(0, poz);
			prp.erase(0, poz + 1);
			poz = prp.find(',');
		}

		v[3] = prp;

		set_marca(v[0]);
		set_model(v[1]);
		set_memorie(stoi(v[2]));
		if (v[3] == "true") {dual_sim = true;}
		else {dual_sim = false;}
	}

	string describe()override {

		string text = "";
		text = "\nMarca : " + get_marca();
		text += "\nModel : " + get_model();
		text += "\nMemorie : " + to_string(get_memorie()) + " GB";
		if (dual_sim == true) { text += "\nDual SIM : Da"; }
		else { text += "\nDual SIM : Nu"; }
		text += "\n";

		return text;
	}

};

