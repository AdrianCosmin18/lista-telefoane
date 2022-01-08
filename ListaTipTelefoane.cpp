#include"ControlTelefon.h"
#include<list>

int main() {


	//Telefon* t1 = new Telefon("samsung", "S21", 512);
	//Telefon* t2 = new Telefon("iPhone,12,128");
	//Telefon* t3 = new Telefon("iPhone,12 Pro,512");
	//Telefon* t4 = new Telefon("iPhone,13 Pro,512");
	//Telefon* t5 = new Telefon("Huawei,Honor 50,64");
	//Telefon t6("HTC,Seria 6,64");

	//List* lista = new List();
	//lista->add(t1);
	//lista->add(t2);
	//lista->add(t3);
	//lista->add(t4);
	//lista->add(t5);


	//lista->sort();
	////list->traverse();

	//Telefon_DualSim* teldual = new Telefon_DualSim("Samsung,S20,512,true");
	//Telefon* tel = teldual;

	//Telefon_DualSim* teldual2 = dynamic_cast<Telefon_DualSim*>(tel);
	//cout << tel->describe();




	//list<Telefon*>telefoane;
	//telefoane.push_back(t1);
	//telefoane.push_back(dual);

	/*for (auto x : telefoane) {

		try {

			Telefon_DualSim* teldual = (Telefon_DualSim*)x;
			cout<<teldual->describe();
		}
		catch (int n) {
			cout << "\n" << x->get_model() << "nu are optiunea de dual sim luata in considerare";
		}

	}*/
	
	ControlTelefon* ct = new ControlTelefon();
	//ct->traverse();
	cout << (*ct->GetTelefonByMarcaAndModel("iPhone", "13"));
}
