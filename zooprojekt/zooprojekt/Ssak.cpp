#include "Ssak.h"

Ssak::Ssak() : zagrozone(false), liczba_pazurow(0), tryb_zycia("") {}

Ssak::Ssak(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s, const bool& z, const int& lp, const std::string& tz)
	: Zwierze(i, g, p, d, dl, s), zagrozone(z), liczba_pazurow(lp), tryb_zycia(tz) {}

bool Ssak::getZagrozony() const {
	return zagrozone;
}

int Ssak::getLiczbaPazurow() const {
	return liczba_pazurow;
}

std::string Ssak::getTrybZycia() const {
	return tryb_zycia;
}

void Ssak::pokazInfo() const {
	Zwierze::pokazInfo();
	std::cout << "-Zagrozony: " << (zagrozone ? "Tak" : "Nie") << std::endl;
	std::cout << "-Liczba pazurow: " << liczba_pazurow << std::endl;
	std::cout << "-Tryb zycia: " << tryb_zycia << std::endl;
	std::cout << std::endl;
}

Ssak::~Ssak() {
	std::cout << "Destrukcja ssaka." << std::endl;
}
