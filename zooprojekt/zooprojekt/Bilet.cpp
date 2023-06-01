#include "Bilet.h"


Bilet::Bilet() : typ(""), cena(0.0) {}

Bilet::Bilet(const std::string& typ, const double& cena) : typ(typ), cena(cena) {}

std::string Bilet::getTyp() const {
	return typ;
}

double Bilet::getCena() const {
	return cena;
}

void Bilet::pokazInfo() const {
    std::cout << "Bilet: " << typ << " - " << cena << " PLN" << std::endl;  
}

std::vector<Bilet> Bilet::odczytajWszystkieZPliku(const std::string& nazwapliku) {
    std::vector<Bilet> wynik;
    std::ifstream plik(nazwapliku);
    if (!plik.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku do odczytu!" << std::endl;
        return wynik;
    }
    std::string typ;
    double cena;
    std::string linia;
    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);
        if (std::getline(iss, typ, ',')) {
            iss >> cena;
            Bilet bilet(typ, cena);
            wynik.push_back(bilet);
        }
    }
    return wynik;
}

Bilet::~Bilet() {
    //std::cout << "Destrukcja biletu." << std::endl;
}