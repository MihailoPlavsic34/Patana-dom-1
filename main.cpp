#include<iostream>
#include"Klase.h"
using namespace std;

int main() {

	    cout << "Unesite naziv flote" << endl;
		string naziv;
		cin >> naziv;
		Flota Ana = naziv;

		cout << "Koloko pilota?" << endl;
		int brojp; cin >> brojp;
		Pilot** piloti = new Pilot * [brojp];
		for (int i = 0; i < brojp; i++) {
			cout << "Ime?" << endl; ;
			string imep; cin >> imep;
			cout << "Broj sati?" << endl;
			int brs; cin >> brs;
			Pilot* pilot = new Pilot{ imep, brs };  
			piloti[i] = pilot;
		};

		cout << "Promena broja sati?1 za da 0 za ne" << endl;  

		cout << "Koliko aviona?" << endl;
		int broja; cin >> broja;
		Avion** avioni = new Avion *[broja];
		for (int i = 0; i < broja; i++) {
			cout << "Naziv?" << endl; ;
			string imea; cin >> imea;
			cout << "Maks putnika?" << endl;
			int brp; cin >> brp;
			Avion* avion = new Avion{ imea, brp };
			avioni[i] = avion;
		};

		cout << "Dodavanje posade avionu, 0 za kraj";
		int l = 1;
		while (l) {
			cout << "Unesite naziv aviona" << endl;
			string naziv; cin >> naziv;
			int i = 0;
			while (avioni[i]->nazivv() != naziv) i++;
			cout << "Kapetan?" << endl;
			string captain; cin >> captain;
			int j = 0;
			while (piloti[j]->imee() != captain) j++;
			avioni[i]->kapetanaviona(piloti[j]);
			cout << "Kopilot?" << endl;
			string copilot; cin >> copilot;
			j = 0;
			while (piloti[j]->imee() != copilot) j++;
			avioni[i]->kopilotaviona(piloti[j]);
			cout << "1 za ponovan unos, 0 za kraj" << endl;  //spreci toooooo
			cin >> l;
		}
		Ana.addplanes(avioni);
		cout << "\n";
		Ana.printflota();
		cout << "\n";
		Ana.findbiggest();
	}

