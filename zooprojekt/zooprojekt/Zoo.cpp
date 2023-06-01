#include "Zoo.h"


Zoo::Zoo() {}

Zoo::~Zoo() {
    for (auto it = zwierzeta.begin(); it != zwierzeta.end(); ++it) {
        delete* it;
    }
}



void Zoo::dodajZwierze() {
    std::string imie, gatunek, pochodzenie, dieta, sezon;
    int dl_zycia;
    bool jajorodne, jadowite, wodne, lata, zagrozone;

    // Pobierz dane o zwierzęciu od użytkownika
    std::cout << "Podaj imie: ";
    std::cin >> imie;
    std::cout << "Podaj gatunek: ";
    std::cin >> gatunek;
    std::cout << "Podaj pochodzenie: ";
    std::cin >> pochodzenie;
    std::cout << "Podaj diete: ";
    std::cin >> dieta;
    std::cout << "Podaj dlugosc zycia: ";
    std::cin >> dl_zycia;
    std::cout << "Podaj sezon: ";
    std::cin >> sezon;

    // Zapytaj o dodatkowe właściwości w zależności od typu zwierzęcia
    std::string rodzaj;
    std::cout << "Podaj rodzaj zwierzecia (ryba, gad, plaz, ptak, ssak): ";
    std::cin >> rodzaj;

    if (rodzaj == "ryba") {
        std::cout << "Czy zwierze jest jajorodne (0 - Tak/1 - Nie): ";
        std::cin >> jajorodne;
        zwierzeta.push_back(new Ryba(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jajorodne));
    }
    else if (rodzaj == "gad") {
        std::cout << "Czy zwierze jest jadowite (0 - Tak/1 - Nie): ";
        std::cin >> jadowite;
        zwierzeta.push_back(new Gad(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jadowite));
    }
    else if (rodzaj == "plaz") {
        std::cout << "Czy zwierze jest wodne (0 - Tak/1 - Nie): ";
        std::cin >> wodne;
        zwierzeta.push_back(new Plaz(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, wodne));
    }
    else if (rodzaj == "ptak") {
        std::cout << "Czy zwierze lata (0 - Tak/1 - Nie): ";
        std::cin >> lata;
        zwierzeta.push_back(new Ptak(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, lata));
    }
    else if (rodzaj == "ssak") {
        std::cout << "Czy zwierze jest zagrozone (0 - Tak/1 - Nie): ";
        std::cin >> zagrozone;
        zwierzeta.push_back(new Ssak(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, zagrozone));
    }
    else {
        std::cout << "Nieznany rodzaj zwierzecia!" << std::endl;
    }
    // zapis do pliku
    std::ofstream plik("zwierzeta.txt", std::ios::app);
    if (!plik.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
        return;
    }
    plik << rodzaj << "," << imie << "," << gatunek << "," << pochodzenie << "," << dieta << "," << dl_zycia << "," << sezon << ",";
    if (rodzaj == "ryba") {
        Ryba* ryba = dynamic_cast<Ryba*>(zwierzeta.back());
        plik << ryba->getJajorodne() << std::endl;
    }
    else if (rodzaj == "gad") {
        Gad* gad = dynamic_cast<Gad*>(zwierzeta.back());
        plik << gad->getJadowite() << std::endl;
    }
    else if (rodzaj == "plaz") {
        Plaz* plaz = dynamic_cast<Plaz*>(zwierzeta.back());
        plik << plaz->getWodne() << std::endl;
    }
    else if (rodzaj == "ptak") {
        Ptak* ptak = dynamic_cast<Ptak*>(zwierzeta.back());
        plik << ptak->getLatajacy() << std::endl;
    }
    else if (rodzaj == "ssak") {
        Ssak* ssak = dynamic_cast<Ssak*>(zwierzeta.back());
        plik << ssak->getZagrozony() << std::endl;
    }
    plik.close();

}


void Zoo::usunZwierze(std::string imie) {
    std::cout << "Podaj imie zwierzecia do usuniecia: ";
    std::cin >> imie;

    bool znaleziono = false;

    // Otwieramy plik do odczytu
    std::ifstream plik("zwierzeta.txt");

    // Wczytujemy zawartosc pliku do wektora
    std::vector<std::string> zawartosc;
    std::string linia;
    while (std::getline(plik, linia)) {
        if (linia.find(imie) == std::string::npos) {
            zawartosc.push_back(linia);
        }
        else {
            znaleziono = true;
        }
    }

    plik.close();

    // Nadpisujemy plik nowa zawartoscia
    std::ofstream nowy_plik("zwierzeta.txt");
    for (const auto& linia : zawartosc) {
        nowy_plik << linia << std::endl;
    }
    nowy_plik.close();

    // Usuwamy zwierze z wektora
    for (auto it = zwierzeta.begin(); it != zwierzeta.end(); it++) {
        if ((*it)->getImie() == imie) {
            delete* it;
            zwierzeta.erase(it);
            break;
        }
    }

    if (znaleziono) {
        std::cout << "Zwierze o imieniu " << imie << " zostalo usuniete." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono zwierzecia o imieniu " << imie << "." << std::endl;
    }
}
//void Zoo::wyszukajZwierze(const std::string& imie) {
//    for (const auto& zwierze : zwierzeta) {
//        if (zwierze->getImie() == imie) {
//            zwierze->pokazInfo();
//            return;
//        }
//    }
//    std::cout << "Nie znaleziono zwierzecia o imieniu: " << imie << std::endl;
//}

void Zoo::wyszukajZwierze(std::string& imie) {
    std::cout << "Podaj imie zwierzecia na temat ktorego chcesz uzyskac informacje: ";
    std::cin >> imie;

    bool znaleziono = false;

    // Otwieramy plik do odczytu
    std::ifstream plik("zwierzeta.txt");

    //for (auto& zwierze : zwierzeta) {
    //    if (zwierze->getImie() == imie) {
    //        znaleziono = true;
    //        zwierze->pokazInfo();
    //    }
    //}

    // Wczytujemy zawartosc pliku do wektora
    std::vector<std::string> zawartosc;
    std::string linia;
    while (std::getline(plik, linia)) {
        if (linia.find(imie) == std::string::npos) {
            zawartosc.push_back(linia);
        }
        else {
            znaleziono = true;
        }
    }
    // Pokazujemy info o zwierzeciu
    for (auto it = zwierzeta.begin(); it != zwierzeta.end(); it++) {
        if ((*it)->getImie() == imie) {
            (*it)->pokazInfo();
            break;
        }
    }

    plik.close();

    if (!znaleziono) {
        std::cout << "Nie znaleziono zwierzecia o podanym imieniu." << std::endl;
    }
}
void Zoo::dodajBilet() {
    std::string typ;
    double cena;

    std::cout << "Podaj typ biletu: ";
    std::cin >> typ;
    std::cout << "Podaj cene biletu: ";
    std::cin >> cena;
    
    std::ofstream plik("bilety.txt", std::ios::app);
    if (!plik.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
        return;
    }
    plik << typ << "," << cena << "\n";

    plik.close();
}

//usuwanie biletu
void Zoo::usunBilet(std::string typ) {
    std::cout << "Podaj nazwe biletu: ";
    std::cin >> typ;

    bool znaleziono = false;

    // Otwieramy plik do odczytu
    std::ifstream plik("bilety.txt");

    // Wczytujemy zawartosc pliku do wektora
    std::vector<std::string> zawartosc;
    std::string linia;
    while (std::getline(plik, linia)) {
        if (linia.find(typ) == std::string::npos) {
            zawartosc.push_back(linia);
        }
        else {
            znaleziono = true;
        }
    }

    plik.close();

    // Nadpisujemy plik nowa zawartoscia
    std::ofstream nowy_plik("bilety.txt");
    for (const auto& linia : zawartosc) {
        nowy_plik << linia << std::endl;
    }
    nowy_plik.close();

    // Usuwamy zwierze z wektora
    for (auto it = bilety.begin(); it != bilety.end(); it++) {
        if ((*it)->getTyp() == typ) {
            delete* it;
            bilety.erase(it);
            break;
        }
    }

    if (znaleziono) {
        std::cout << "Bilet o nazwie" << typ << " zostalo usuniete." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono biletu o nazwie " << typ << "." << std::endl;
    }
}

void Zoo::dodajEvent() {
    std::string nazwa, czas, data;

    std::cout << "Podaj nazwe eventu: ";
    std::cin >> nazwa;
    std::cout << "Podaj godzine eventu: ";
    std::cin >> czas;
    std::cout << "Podaj date eventu: ";
    std::cin >> data;

    std::ofstream plik("bilety.txt", std::ios::app);
    if (!plik.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
        return;
    }
    plik << nazwa << "," << czas << "," << data << "\n";

    plik.close();
}