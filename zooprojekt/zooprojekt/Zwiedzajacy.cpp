#include "Zwiedzajacy.h"

Zwiedzajacy::Zwiedzajacy(const std::string& im, const std::string& naz, const std::string& nr_tel) {
    imie = im;
    nazwisko = naz;
    numer = nr_tel;
    czyBiletKupiony = false;
}
std::string Zwiedzajacy::getImie() const {
    return imie;
}
std::string Zwiedzajacy::getNazwisko() const {
    return nazwisko;
}
std::string Zwiedzajacy::getNrTel() const {
    return numer;
}

Zwiedzajacy::~Zwiedzajacy() {}