#include "Ptak.h"

Ptak::Ptak() : latajace(false), rozpietosc_skrzydel(0.0), migracje(false) {}

Ptak::Ptak(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s, const bool& l, const double& rs, const std::string& rg, const bool& m)
	: Zwierze(i, g, p, d, dl, s), latajace(l), rozpietosc_skrzydel(rs), rodzaj_gniazda(rg), migracje(m) {}

bool Ptak::getLatajacy() const {
	return latajace;
}

double Ptak::getRozpietoscSkrzydel() const {
	return rozpietosc_skrzydel;
}

std::string Ptak::getRodzajGniazda() const {
	return rodzaj_gniazda;
}

bool Ptak::getMigracje() const {
	return migracje;
}

void Ptak::pokazInfo() const {
	Zwierze::pokazInfo();
	std::cout << "-Lata: " << (latajace ? "Tak" : "Nie") << std::endl;
	std::cout << "-Rozpietosc skrzydel: " << rozpietosc_skrzydel << " cm" << std::endl;
	std::cout << "-Rodzaj gniazda: " << rodzaj_gniazda << std::endl;
	std::cout << "-Czy migruje: " << (migracje ? "Tak" : "Nie") << std::endl;
	std::cout << std::endl;
}

Ptak::~Ptak() {
	std::cout << "Destrukcja ptaka." << std::endl;
}
