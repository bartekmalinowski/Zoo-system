#include "Zwierze.h"
#include "Ssak.h"
#include "Gad.h"

//konstruktor bezargumentowy
Zwierze::Zwierze() : imie(""), gatunek(""), pochodzenie(""), dieta(""), dl_zycia(0), sezon("") {};

Zwierze::Zwierze(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s) {
	imie = i;
	gatunek = g;
	pochodzenie = p;
	dieta = d;
	dl_zycia = dl;
	sezon = s;
}

std::string Zwierze::getImie() const {
	return imie;
}
std::string Zwierze::getGatunek() const {
	return gatunek;
}
std::string Zwierze::getPochodzenie() const {
	return pochodzenie;
}
std::string Zwierze::getDieta() const {
	return dieta;
}
int Zwierze::getDlZycia() const {
	return dl_zycia;
}
std::string Zwierze::getSezon() const {
	return sezon;
}

void Zwierze::pokazInfo() const {
	std::cout << "-Imie: " << imie << std::endl;
	std::cout << "-Gatunek: " << gatunek << std::endl;
	std::cout << "-Pochodzenie: " << pochodzenie << std::endl;
	std::cout << "-Dieta: " << dieta << std::endl;
	std::cout << "-Dlugosc zycia: " << dl_zycia << " lat" << std::endl;
	std::cout << "-Pora roku w ktorej wystepuje w zoo: " << sezon << std::endl;
}

Zwierze::~Zwierze() {
	
}