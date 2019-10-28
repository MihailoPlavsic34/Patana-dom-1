#include<iostream>
#include<string>
using namespace std;

class Pilot {
public:
	Pilot() { ime = ""; sati = 0; bool letilit = false; };  //podrazumevani
	Pilot(string pime, int psati, bool pletili = false) {  //konvertujuci, pletili podrazumevano false
		ime = pime;
		sati = psati;
		letili = pletili;
	};
	~Pilot() {};  //destruktor, nek sttoji?
	void printpilot() const;
	void povecajsati(int s);
	int satii();  //moze se dohvatiti
	bool letilii();  //moze da dohvati
	void promeniletili(bool a);
	string imee();  //moze se dohvatiti
private:
	string ime;
	int sati;
	bool letili;
};

class Avion {
public:
	Avion() { naziv = ""; max = 0; kapetan, kopilot = nullptr; };  //podrazumevani
	Avion(string anaziv, int amax, Pilot*kapetan=nullptr, Pilot*kopilot=nullptr) {  //konvertujuci, da li ako ovde ne definisem nista za pilot i kopilot je nullptr ili ne? 
																					// #1edit: Da jer si ih inicijalizovala dole kao null. Da nisi to uradila morala bi da u def napises =nullptr kao sto je dodato!
		naziv = anaziv;																//ovo ima svoje mane jer sad ili moras da izostavis sve pok u pozivu konstruktora, ili samo kopilota, prica iz knjige za poz f-ja sa predef vrednostima!
		max = amax;																	// mozda je bolje da ostane funkcija kakva jeste, ida samo dodas dole kopilot = nullptr; kapetan = nullptr;
		kapetan = nullptr;															//tada svi konstruktori koji ne inicijalizuju ta polja ostavljaju vrednosti nullptr zaci NOJS
		kopilot = nullptr;															//ja sam ostavio sav tri nacina ti ostavi onaj koji ti se vise svidja! Malo konfuzno nemam mesta lepo uzivo cemo :)
	};
	~Avion() { delete kapetan, delete kopilot; };  //destruktor?
	void printavion() const;
	void kapetann();
	void kopiloot();
	string nazivv(); // **Pataric glas** NaziIIVVV, MihaIIIlOOOO
	void kapetanaviona(Pilot* kapetann);
	void kopilotaviona(Pilot* kopilott);
	int maxx();
private:
	string naziv;
	int max;  //maksimalan broj putnika koje moze da primi
	Pilot* kapetan=nullptr;
	Pilot* kopilot=nullptr;
};

class Flota {
public:
	Flota() { naziv = ""; int broj = 0;  avioni = nullptr; };  //podrazumevani
	Flota(string fnaziv) {  //konvertujuci, avioni se naknadno dodaju
		naziv = fnaziv; //morala bi da dodas kao dole pod //## sto sam stavio jer ovim pozivom ti ostaje pok avioni neinicijalizovan!
						//mogla si i u ovom konstruktoru bez problema to al ja voim dole jer se onda odnosi na sve konstruktore, pa ako nekad zab ne puca program i to!
	};
	Flota(const Flota& Flota) {  //kopirajuci
		for (int i = 0; i < broj; i++) { avioni[i] = Flota.avioni[i]; }; //samo me zanima gde si inicijalizovala onaj avioni niz, jer ovako presipas u suplju memoriju!
		broj = Flota.broj;												//i da bukvalno imam istu gresku... bravo Mihailo!				
		naziv = Flota.naziv;
	};
	~Flota() { delete[] avioni; avioni = nullptr; broj = 0; }; //destruktor obavezno!!!
	void printflota();
	int ukupnoaviona();
	int maxputnika();
	int findbiggest();
	void addplane(Avion* a);
private:
	string naziv;
	int broj;
	Avion** avioni =nullptr; //##
};
