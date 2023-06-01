#include "Gad.h"

Gad::Gad() : jadowite(true), dl_ciala(0), s_ruchu("") {};

Gad::Gad(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s, const bool& j, const std::string& sr, const int& dlu) : Zwierze(i, g, p, d, dl, s), jadowite(j), s_ruchu(sr), dl_ciala(dlu) {}

bool Gad::getJadowite() const {
	return jadowite;
}

int Gad::getDlCiala() const {
	return dl_ciala;
}

std::string Gad::getSposobRuchu() const {
	return s_ruchu;
}

void Gad::pokazInfo() const {
	Zwierze::pokazInfo();
	std::cout << "-Jadowity: " << (jadowite ? "Tak" : "Nie") << std::endl;
	std::cout << "-Sposob poruszania: " << s_ruchu << std::endl;
	std::cout << "-Dlugosc ciala: " << dl_ciala << "cm" << std::endl;
	std::cout << std::endl;
}



Gad::~Gad() {
	std::cout << "Destrukcja gada." << std::endl;
}