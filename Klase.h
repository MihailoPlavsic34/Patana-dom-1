#include<iostream>
#include<string>
using namespace std;

class Pilot {
public:
	Pilot() { ime = ""; sati = 0; bool letilit = false; };  
	Pilot(string pime, int psati, bool pletili = false) {  
		ime = pime;
		sati = psati;
		letili = pletili;
	};
	void printpilot() const;
	void povecajsati(int s);
	int satii();  
	bool letilii();  
	void promeniletili(bool a);
	string imee();  
private:
	string ime;
	int sati;
	bool letili;
};

class Avion {
public:
	Avion() { naziv = ""; max = 0; kapetan, kopilot = nullptr; }; 
	Avion(string anaziv, int amax, Pilot* kapetan = nullptr, Pilot* kopilot = nullptr) {  
																					
		naziv = anaziv;																
		max = amax;																	
		kapetan = nullptr;															
		kopilot = nullptr;															
	};
	~Avion() { delete kapetan, delete kopilot; };  
	void printavion() const;
	void kapetann();
	void kopiloot();
	string nazivv(); 
	void kapetanaviona(Pilot* kapetann);
	void kopilotaviona(Pilot* kopilott);
	int maxx();
private:
	string naziv;
	int max;  
	Pilot* kapetan = nullptr;
	Pilot* kopilot = nullptr;
};

class Flota { ///poptaviii
public:
	Flota() { naziv = ""; int broj = 0;  avioni = nullptr; };  
	Flota(string fnaziv) { 
		naziv = fnaziv;
						
	};

	Flota(const Flota& Flota) {  
		avioni = new Avion * [broj];
		for (int i = 0; i < broj; i++) { avioni[i] = Flota.avioni[i]; }; 
		broj = Flota.broj;														
		naziv = Flota.naziv;
	};
	~Flota() { delete[] avioni; avioni = nullptr; broj = 0; }; 
	void printflota();
	int ukupnoaviona();
	int maxputnika();
	int findbiggest();
	void addplanes(Avion** avionii);
private:
	string naziv;
	int broj;
	Avion** avioni = nullptr; 
};
