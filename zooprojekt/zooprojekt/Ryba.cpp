#include "Ryba.h"
#include <iostream>

Ryba::Ryba() : jajorodne(false), dlugosc(0.0) {}

Ryba::Ryba(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s, const bool& j, const double& dlug, const std::string& skrz)
    : Zwierze(i, g, p, d, dl, s), jajorodne(j), dlugosc(dlug), rodzaj_skrzeli(skrz) {}

bool Ryba::getJajorodne() const {
    return jajorodne;
}

void Ryba::setJajorodne(bool j) {
    jajorodne = j;
}

double Ryba::getDlugosc() const {
    return dlugosc;
}

void Ryba::setDlugosc(double dlug) {
    dlugosc = dlug;
}

std::string Ryba::getRodzajSkrzeli() const {
    return rodzaj_skrzeli;
}

void Ryba::setRodzajSkrzeli(const std::string& skrz) {
    rodzaj_skrzeli = skrz;
}



void Ryba::pokazInfo() const {
    Zwierze::pokazInfo();
    std::cout << "-Jajorodne: " << (jajorodne ? "Tak" : "Nie") << std::endl;
    std::cout << "-Dlugosc: " << dlugosc << " cm" << std::endl;
    std::cout << "-Rodzaj skrzeli: " << rodzaj_skrzeli << std::endl;
    std::cout << std::endl;
}

Ryba::~Ryba() {
    std::cout << "Destrukcja ryby." << std::endl;
}
