#include "Plaz.h"

Plaz::Plaz() : wodne(false), kolor_skory(""), sp_rozmnazania("") {}

Plaz::Plaz(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s, const bool& w, const std::string& ks, const std::string& sr)
	: Zwierze(i, g, p, d, dl, s), wodne(w), kolor_skory(ks), sp_rozmnazania(sr) {}

bool Plaz::getWodne() const {
	return wodne;
}

std::string Plaz::getKolorSkory() const {
	return kolor_skory;
}

std::string Plaz::getSpRozmnazania() const {
	return sp_rozmnazania;
}

void Plaz::pokazInfo() const {
	Zwierze::pokazInfo();
	std::cout << "-Zyjace w wodzie: " << (wodne ? "Tak" : "Nie") << std::endl;
	std::cout << "-Kolor skory: " << kolor_skory << std::endl;
	std::cout << "-Sposob rozmnazania: " << sp_rozmnazania << std::endl;
	std::cout << std::endl;
}

Plaz::~Plaz() {
	//std::cout << "Destrukcja plaza." << std::endl;
}
