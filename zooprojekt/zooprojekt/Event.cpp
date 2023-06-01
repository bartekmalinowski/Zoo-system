#include "Event.h"

Event::Event() {
	nazwa = "";
	czas = "";
	data = "";
}

Event::Event(const std::string& nazwa, const std::string& czas, const std::string& data) {
    this->nazwa = nazwa;
    this->czas = czas;
    this->data = data;
}

std::string Event::getNazwa() const {
	return nazwa;
}
std::string Event::getCzas() const {
	return czas;
}
std::string Event::getData() const {
	return data;
}

std::vector<Event> Event::odczytajWszystkieZPliku(const std::string& nazwapliku) {
    std::vector<Event> wynik;
    std::ifstream plik(nazwapliku);
    if (!plik.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku do odczytu!" << std::endl;
        return wynik;
    }
    std::string nazwa, czas, data;
    std::string linia;
    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);
        if (std::getline(iss, nazwa, ',') &&
            std::getline(iss, czas, ',') &&
            std::getline(iss, data)) {
            Event event(nazwa, czas, data);
            wynik.push_back(event);
        }
    }
    return wynik;
}

void Event::godzinyOtwarcia() {
	int wybor = 0;
	std::cout << "Zobacz godziny otwarcia 1. w zime, 2. w lato: " << std::endl;
	std::cin >> wybor;
	if (wybor == 1) {
		std::cout << "Godziny otwarcia zoo w zime:" << std::endl;
		std::cout << "Poniedzialek - Piatek: 10:00 - 15:00" << std::endl;
		std::cout << "Sobota, Niedziela: 12:00 - 17:00" << std::endl;
	}
	else if (wybor == 2) {
		std::cout << "Godziny otwarcia zoo w lato:" << std::endl;
		std::cout << "Poniedzialek - Piatek: 9:00 - 16:00" << std::endl;
		std::cout << "Sobota, Niedziela: 9:00 - 18:00" << std::endl;
	}
	else {
		std::cout << "Niepoprawny numer!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "-" << event.nazwa << " - " << event.data << " o " << event.czas;
    return os;
}

Event::~Event() {
    //std::cout << "Destrukcja wydarzenia." << std::endl;
}