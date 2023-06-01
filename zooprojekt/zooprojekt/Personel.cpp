#include "Personel.h"
#include "Interfejs.h"
#include <iostream>
#include<fstream>

Personel::Personel() : login(""), haslo("") {}

Personel::Personel(const std::string& login, const std::string& haslo) :
    login(login),
    haslo(haslo)
{}

void Personel::autoryzacja() {
    std::string login, haslo;
    std::cout << "Podaj login: ";
    std::cin >> login;
    std::cout << "Podaj haslo: ";
    std::cin >> haslo;

    std::ifstream plik("hasla.txt");
    std::string dane;
    bool autoryzacja = false;
    Interfejs interfejs;

    while (std::getline(plik, dane)) {
        if (dane.find(login + "," + haslo) != std::string::npos) {
            autoryzacja = true;
            break;
        }
    }

    if (autoryzacja) {
        std::cout << "Udalo sie zalogowac!\n";
        // wywołanie funkcji interfejsu dla pracownika
        interfejs.menuPersonel();
    }
    else {
        std::cout << "Niepoprawny login lub haslo.\n";
    }
}

Personel::~Personel() {}