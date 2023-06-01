#include "Interfejs.h"

Interfejs::Interfejs() {}

int Interfejs::menu() {
    int wybor = 0;
    Personel personel;
    
    do {
        std::cout << "==========================" << std::endl;
        std::cout << "Witaj w Zoo!" << std::endl;
        std::cout << "1. Zwiedzajacy" << std::endl;
        std::cout << "2. Pracownik" << std::endl;
        std::cout << "3. Wyjscie" << std::endl;
        std::cout << "==========================" << std::endl;

        std::cin >> wybor;

        switch (wybor) {
        case 1:
            system("cls");
            menuUzytkownik();
            break;
        case 2:
            system("cls");
            personel.autoryzacja();
            break;
        case 3:
            system("cls");
            std::cout << "Koniec programu" << std::endl;
            exit(0);
            break;
        default:
            std::cout << "Niepoprawny wybor." << std::endl;
        }
    } while (wybor != 3);
    return 0;
}

int Interfejs::menuUzytkownik(){
    int wybor = 0;
    Event event;
    do {
        std::cout << "==========================" << std::endl;
        std::cout << "Wybierz opcje:" << std::endl;
        std::cout << "1. Zobacz dostepne zwierzeta" << std::endl;
        std::cout << "2. Cennik" << std::endl;
        std::cout << "3. Aktualne wydarzenia" << std::endl;
        std::cout << "4. Godziny otwarcia Zoo" << std::endl;
        std::cout << "5. Kub bilet przez internet" << std::endl;
        std::cout << "6. Twoje kupione bilety" << std::endl;
        std::cout << "7. Wyjscie" << std::endl;
        std::cout << "==========================" << std::endl;

        std::cin >> wybor;

        switch (wybor) {
        case 1:
            system("cls");
            wyswietlImionaZwierzat();
            break;
        case 2:
            system("cls");
            wyswietlCennik();
            break;
        case 3:
            system("cls");
            wyswietlWydarzenia();
            break;
        case 4:
            system("cls");
            event.godzinyOtwarcia();
            break;
        case 5:
            system("cls");
            kupBiletPrzezInternet();
            break;
        case 6:
            system("cls");
            wyswietlKupioneBilety();
            break;
        case 7:
            system("cls");
            wyczyscPlikBiletow();
            exitu();
            break;
        default:
            std::cout << "Nieprawidlowa opcja, sprobuj ponownie." << std::endl;
            break;
        }
    } while (wybor != 7);
    return 0;
}

int Interfejs::menuPersonel() {
    int wybor = 0;
    int numer = 0;
    std::string imie, typ, nazwa;
    do {
        std::cout << "==========================" << std::endl;
        std::cout << "Wybierz opcje:" << std::endl;
        std::cout << "1. Dodaj zwierze" << std::endl;
        std::cout << "2. Usun zwierze" << std::endl;
        std::cout << "3. Dodaj bilet" << std::endl;
        std::cout << "4. Usun bilet" << std::endl;
        std::cout << "5. Dodaj wydarzenie" << std::endl;
        std::cout << "6. Usun wydarzenie" << std::endl;
        std::cout << "7. Powrot do menu" << std::endl;
        std::cout << "8. Wyjscie" << std::endl;
        std::cout << "==========================" << std::endl;

        std::cin >> wybor;

        switch (wybor) {
        case 1:
            system("cls");
            dodajZwierze();
            break;
        case 2:
            usunZwierze(numer);
            break;
        case 3:
            dodajBilet();
            break;
        case 4:
            usunBilet(typ);
            break;
        case 5:
            dodajEvent();
            break;
        case 6:
            usunEvent(nazwa);
            break;
        case 7:
            menu();
            break;
        case 8:
            exitp();
            break;
        default:
            std::cout << "Nieprawidlowa opcja, sprobuj ponownie." << std::endl;
            break;
        }
    } while (wybor != 7);
    return 0;
}

void Interfejs::dodajBilet() {
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

void Interfejs::usunBilet(std::string typ) {
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

    if (znaleziono) {
        std::cout << "Bilet o nazwie" << typ << " zostal usuniety." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono biletu o nazwie " << typ << "." << std::endl;
    }
}

void Interfejs::dodajEvent() {
    std::string nazwa, czas, data;

    std::cout << "Podaj nazwe eventu: ";
    std::getline(std::cin.ignore(), nazwa);
    std::cout << "Podaj godzine eventu: ";
    std::getline(std::cin, czas);
    std::cout << "Podaj date eventu: ";
    std::getline(std::cin, data);


    std::ofstream plik("wydarzenia.txt", std::ios::app);
    if (!plik.is_open()) {
        std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
        return;
    }
    plik << nazwa << "," << czas << "," << data << "\n";

    plik.close();
}

void Interfejs::usunEvent(std::string nazwa) {
    std::cout << "Podaj nazwe wydarzenia: ";
    std::cin.ignore();
    std::getline(std::cin, nazwa);

    bool znaleziono = false;

    // Otwieramy plik do odczytu
    std::ifstream plik("wydarzenia.txt");

    // Wczytujemy zawartosc pliku do wektora
    std::vector<std::string> zawartosc;
    std::string linia;
    while (std::getline(plik, linia)) {
        if (linia.find(nazwa) == std::string::npos) {
            zawartosc.push_back(linia);
        }
        else {
            znaleziono = true;
        }
    }

    plik.close();

    // Nadpisujemy plik nowa zawartoscia
    std::ofstream nowy_plik("wydarzenia.txt");
    for (const auto& linia : zawartosc) {
        nowy_plik << linia << std::endl;
    }
    nowy_plik.close();

    if (znaleziono) {
        std::cout << "Wydarzenie o nazwie " << nazwa << " zostalo usuniete." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono wydarzenia o nazwie " << nazwa << "." << std::endl;
    }
}

void Interfejs::dodajZwierze() {
    std::string imie, gatunek, pochodzenie, dieta, sezon;
    int dl_zycia = 0;

    // Pobierz dane o zwierzęciu od użytkownika
    std::cout << "Podaj imie: ";
    std::cin.ignore();
    std::getline(std::cin, imie);
    std::cout << "Podaj gatunek: ";
    std::getline(std::cin, gatunek);
    std::cout << "Podaj pochodzenie: ";
    std::getline(std::cin, pochodzenie);
    std::cout << "Podaj diete: ";
    std::getline(std::cin, dieta);
    std::cout << "Podaj dlugosc zycia: ";
    std::cin >> dl_zycia;
    std::cout << "Podaj sezon: ";
    std::cin.ignore();
    std::getline(std::cin, sezon);


    // Zapytaj o dodatkowe właściwości w zależności od typu zwierzęcia
    std::string rodzaj;
    std::cout << "Podaj rodzaj zwierzecia (ryba, gad, plaz, ptak, ssak): ";
    std::cin >> rodzaj;

    if (rodzaj == "ryba") {
        bool jajorodne;
        double dlugosc;
        std::string rodzaj_skrzeli;
        std::string zywienie;
        std::cout << "Czy zwierze jest jajorodne (1 - Tak/0 - Nie): ";
        std::cin >> jajorodne;
        std::cout << "Dlugosc: ";
        std::cin >> dlugosc;
        std::cout << "Rodzaj skrzeli: ";
        std::cin.ignore();
        std::getline(std::cin, rodzaj_skrzeli);
        zwierzeta.push_back(new Ryba(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jajorodne, dlugosc, rodzaj_skrzeli));
    }
    else if (rodzaj == "gad") {
        bool jadowite;
        std::string s_ruchu;
        int dl_ciala;
        std::cout << "Czy zwierze jest jadowite (1 - Tak/0 - Nie): ";
        std::cin >> jadowite;
        std::cout << "Jak zwierze sie porusza: ";
        std::cin.ignore();
        std::getline(std::cin, s_ruchu);
        std::cout << "Jak dlugie jest zwierze: ";
        std::cin >> dl_ciala;
        zwierzeta.push_back(new Gad(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jadowite, s_ruchu, dl_ciala));
    }
    else if (rodzaj == "plaz") {
        std::string kolor_skory;
        std::string sp_rozmnazania;
        bool wodne;
        std::cout << "Czy zwierze zyje w wodzie (1 - Tak/0 - Nie): ";
        std::cin >> wodne;
        std::cout << "Jakiego koloru zwierze ma skore: ";
        std::cin.ignore();
        std::getline(std::cin, kolor_skory);
        std::cout << "W jaki spoosb zwierze sie rozmnarza: ";
        std::cin.ignore();
        std::getline(std::cin, sp_rozmnazania);
        zwierzeta.push_back(new Plaz(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, wodne, kolor_skory, sp_rozmnazania));
    }
    else if (rodzaj == "ptak") {
        bool lata;
        double rozpietosc;
        std::string rodzajGniazda;
        bool migracje;
        std::cout << "Czy zwierze lata (1 - Tak/0 - Nie): ";
        std::cin >> lata;
        std::cout << "Podaj rozpietosc skrzydel: ";
        std::cin >> rozpietosc;
        std::cout << "Podaj rodzaj gniazda: ";
        std::cin.ignore();
        std::getline(std::cin, rodzajGniazda);
        std::cout << "Czy zwierze wykonuje migracje (1 - Tak/0 - Nie): ";
        std::cin >> migracje;
        zwierzeta.push_back(new Ptak(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, lata, rozpietosc, rodzajGniazda, migracje));
    }
    else if (rodzaj == "ssak") {
        bool zagrozone;
        int liczba_pazurow;
        std::string tryb_zycia;
        std::cout << "Czy zwierze jest zagrozone (1 - Tak/0 - Nie): ";
        std::cin >> zagrozone;
        std::cout << "Podaj liczbe pazurow: ";
        std::cin >> liczba_pazurow;
        std::cout << "Podaj tryb zycia zwierzaka: ";
        std::cin.ignore();
        std::getline(std::cin, tryb_zycia);
        zwierzeta.push_back(new Ssak(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, zagrozone, liczba_pazurow, tryb_zycia));
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
        plik << ryba->getJajorodne() << "," << ryba->getDlugosc() << "," << ryba->getRodzajSkrzeli() << std::endl;
    }
    else if (rodzaj == "gad") {
        Gad* gad = dynamic_cast<Gad*>(zwierzeta.back());
        plik << gad->getJadowite() << "," << gad->getSposobRuchu() << "," << gad->getDlCiala() << std::endl;
    }
    else if (rodzaj == "plaz") {
        Plaz* plaz = dynamic_cast<Plaz*>(zwierzeta.back());
        plik << plaz->getWodne() << "," << plaz->getKolorSkory() << "," << plaz->getSpRozmnazania() << std::endl;
    }
    else if (rodzaj == "ptak") {
        Ptak* ptak = dynamic_cast<Ptak*>(zwierzeta.back());
        plik << ptak->getLatajacy() << "," << ptak->getRozpietoscSkrzydel() << "," << ptak->getRodzajGniazda() << "," << ptak->getMigracje() << std::endl;
    }
    else if (rodzaj == "ssak") {
        Ssak* ssak = dynamic_cast<Ssak*>(zwierzeta.back());
        plik << ssak->getZagrozony() << "," << ssak->getLiczbaPazurow() << "," << ssak->getTrybZycia() << std::endl;
    }
    plik.close();

}

void Interfejs::usunZwierze(int numer) {
    std::ifstream plik("zwierzeta.txt");
    if (!plik.is_open()) {
        std::cout << "Blad odczytu pliku." << std::endl;
        return;
    }
    std::vector<std::string> imionaZwierzat;
    std::vector<std::unique_ptr<Zwierze>> zwierzeta;

    std::string linia;
    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);
        std::string typ, imie;
        std::getline(iss, typ, ',');
        std::getline(iss, imie, ',');

        if (typ == "ryba") {
            std::string gatunek, pochodzenie, dieta, sezon;
            int dl_zycia;
            bool jajorodne;
            double dlugosc;
            std::string rodzaj_skrzeli;
            std::string zywienie;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> jajorodne;
            iss.ignore();
            iss >> dlugosc;
            iss.ignore();
            std::getline(iss, rodzaj_skrzeli, ',');
            std::getline(iss, zywienie);

            zwierzeta.push_back(std::make_unique<Ryba>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jajorodne, dlugosc, rodzaj_skrzeli));
        }

        else if (typ == "ssak") {
            std::string gatunek, pochodzenie, dieta, sezon;
            int dl_zycia;
            bool zagrozone;
            int liczba_pazurow;
            std::string tryb_zycia;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> zagrozone;
            iss.ignore();
            iss >> liczba_pazurow;
            iss.ignore();
            std::getline(iss, tryb_zycia);

            zwierzeta.push_back(std::make_unique<Ssak>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, zagrozone, liczba_pazurow, tryb_zycia));
        }
        else if (typ == "gad") {
            std::string gatunek, pochodzenie, dieta, sezon, s_ruchu;
            int dl_zycia, dl_ciala;
            bool jadowite;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> jadowite;
            iss.ignore();
            std::getline(iss, s_ruchu, ',');
            iss >> dl_ciala;

            zwierzeta.push_back(std::make_unique<Gad>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jadowite, s_ruchu, dl_ciala));
        }
        else if (typ == "plaz") {
            std::string gatunek, pochodzenie, dieta, sezon, kolor_skory, sp_rozmnazania;
            int dl_zycia;
            bool wodne;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> wodne;
            iss.ignore();
            std::getline(iss, kolor_skory, ',');
            std::getline(iss, sp_rozmnazania);

            zwierzeta.push_back(std::make_unique<Plaz>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, wodne, kolor_skory, sp_rozmnazania));
        }

        else if (typ == "ptak") {
            std::string gatunek, pochodzenie, dieta, sezon;
            int dl_zycia;
            bool latajace;
            double rozpietosc_skrzydel;
            std::string rodzaj_gniazda;
            bool migracje;
            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> latajace;
            iss.ignore();
            iss >> rozpietosc_skrzydel;
            iss.ignore();
            std::getline(iss, rodzaj_gniazda, ',');
            iss >> migracje;

            zwierzeta.push_back(std::make_unique<Ptak>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, latajace, rozpietosc_skrzydel, rodzaj_gniazda, migracje));
        }

        imionaZwierzat.push_back(imie);
    }

    plik.close();

    std::sort(imionaZwierzat.begin(), imionaZwierzat.end());

    std::cout << "Lista zwierzat:" << std::endl;
    for (int i = 0; i < imionaZwierzat.size(); i++) {
        std::cout << i + 1 << ". " << imionaZwierzat[i] << std::endl;
    }

    std::cout << "Podaj numer zwierzecia do usuniecia: ";
    std::cin >> numer;

    if (numer >= 1 && numer <= imionaZwierzat.size()) {
        std::string imie = imionaZwierzat[numer - 1];

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
                zwierzeta.erase(it);
                break;
            }
        }

        if (znaleziono) {
            std::cout << "Zwierze o imieniu " << imie << " zostalo usuniete." << std::endl;
            system("cls");
        }
        else {
            std::cout << "Nie znaleziono zwierzecia o imieniu " << imie << "." << std::endl;
        }
    }
    else {
        std::cout << "Niepoprawny numer zwierzecia!" << std::endl;
    }

}

void Interfejs::wyswietlImionaZwierzat() {
    std::ifstream plik("zwierzeta.txt");
    if (!plik.is_open()) {
        std::cout << "Blad odczytu pliku." << std::endl;
        return;
    }
    std::vector<std::string> imionaZwierzat;
    std::vector<std::unique_ptr<Zwierze>> zwierzeta;

    std::string linia;
    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);
        std::string typ, imie;
        std::getline(iss, typ, ',');
        std::getline(iss, imie, ',');

        if (typ == "ryba") {
            std::string gatunek, pochodzenie, dieta, sezon;
            int dl_zycia;
            bool jajorodne;
            double dlugosc;
            std::string rodzaj_skrzeli;
            std::string zywienie;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> jajorodne;
            iss.ignore();
            iss >> dlugosc;
            iss.ignore();
            std::getline(iss, rodzaj_skrzeli, ',');
            std::getline(iss, zywienie);

            zwierzeta.push_back(std::make_unique<Ryba>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jajorodne, dlugosc, rodzaj_skrzeli));
        }

        else if (typ == "ssak") {
            std::string gatunek, pochodzenie, dieta, sezon;
            int dl_zycia;
            bool zagrozone;
            int liczba_pazurow;
            std::string tryb_zycia;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> zagrozone;
            iss.ignore();
            iss >> liczba_pazurow;
            iss.ignore();
            std::getline(iss, tryb_zycia);

            zwierzeta.push_back(std::make_unique<Ssak>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, zagrozone, liczba_pazurow, tryb_zycia));
        }
        else if (typ == "gad") {
            std::string gatunek, pochodzenie, dieta, sezon, s_ruchu;
            int dl_zycia, dl_ciala;
            bool jadowite;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> jadowite;
            iss.ignore();
            std::getline(iss, s_ruchu, ',');
            iss >> dl_ciala;

            zwierzeta.push_back(std::make_unique<Gad>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, jadowite, s_ruchu, dl_ciala));
        }
        else if (typ == "plaz") {
            std::string gatunek, pochodzenie, dieta, sezon, kolor_skory, sp_rozmnazania;
            int dl_zycia;
            bool wodne;

            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> wodne;
            iss.ignore();
            std::getline(iss, kolor_skory, ',');
            std::getline(iss, sp_rozmnazania);

            zwierzeta.push_back(std::make_unique<Plaz>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, wodne, kolor_skory, sp_rozmnazania));
        }

        else if (typ == "ptak") {
            std::string gatunek, pochodzenie, dieta, sezon;
            int dl_zycia;
            bool latajace;
            double rozpietosc_skrzydel;
            std::string rodzaj_gniazda;
            bool migracje;
            std::getline(iss, gatunek, ',');
            std::getline(iss, pochodzenie, ',');
            std::getline(iss, dieta, ',');
            iss >> dl_zycia;
            iss.ignore();
            std::getline(iss, sezon, ',');
            iss >> latajace;
            iss.ignore();
            iss >> rozpietosc_skrzydel;
            iss.ignore();
            std::getline(iss, rodzaj_gniazda, ',');
            iss >> migracje;

            zwierzeta.push_back(std::make_unique<Ptak>(imie, gatunek, pochodzenie, dieta, dl_zycia, sezon, latajace, rozpietosc_skrzydel, rodzaj_gniazda, migracje));
        }

        imionaZwierzat.push_back(imie);
    }

    plik.close();

    std::sort(imionaZwierzat.begin(), imionaZwierzat.end());

    std::cout << "Lista zwierzat:" << std::endl;
    for (int i = 0; i < imionaZwierzat.size(); i++) {
        std::cout << i + 1 << ". " << imionaZwierzat[i] << std::endl;
    }
    std::string odpowiedz;
    std::cout << "Czy chcesz zobaczyc dodatkowe informacje o tym zwierzeciu? (tak/nie): ";
    std::cin >> odpowiedz;
    if (odpowiedz == "tak") {
        std::cout << "Wybierz numer zwierzecia, aby zobaczyc informacje na jego temat: ";
        int numer = 0;
        std::cin >> numer;
        system("cls");
        std::cout << std::endl;
        if (numer >= 1 && numer <= imionaZwierzat.size()) {
            std::string imie = imionaZwierzat[numer - 1];
            for (const auto& zwierze : zwierzeta) {
                if (zwierze->getImie() == imie) {
                    std::cout << "Informacje o zwierzeciu:"<< std::endl;
                    zwierze->pokazInfo();
                    break;
                }
            }
        }
        else {
            std::cout << "Niepoprawny numer zwierzecia!" << std::endl;
        }
    }
    else {
        menuUzytkownik();
    }
}

void Interfejs::wyswietlCennik() {
    std::vector<Bilet> listaBiletow = Bilet::odczytajWszystkieZPliku("bilety.txt");
    std::cout << "Cennnik Zoo:" << std::endl;
    for (const auto& bilet : listaBiletow){
        bilet.pokazInfo();
    }
    std::cout << std::endl;
}

void Interfejs::wyswietlWydarzenia(){
    std::vector<Event> listaEventow = Event::odczytajWszystkieZPliku("wydarzenia.txt");
    // Wyświetl wszystkie wydarzenia z listy
    std::cout << "Aktualne wydarzenia w Zoo:" << std::endl;
    for (const auto& wydarzenie : listaEventow) {
        std::cout << wydarzenie << std::endl;
    }
    std::cout << std::endl;
}

void Interfejs::kupBiletPrzezInternet() {
    std::cout << "Dostepne typy biletow do kupienia:" << std::endl;

    // Otwieramy plik z danymi biletów
    std::ifstream plik("bilety.txt");
    if (!plik.is_open()) {
        std::cout << "Blad odczytu pliku z biletami." << std::endl;
        return;
    }

    // Wczytujemy typy biletów z pliku i dodajemy do wektora rodzajeBiletow
    std::string linia;
    while (std::getline(plik, linia)) {
        std::istringstream iss(linia);
        std::string typBiletu;
        double cena;
        std::getline(iss, typBiletu, ',');
        iss >> cena;

        rodzajeBiletow.push_back(typBiletu);
        cenyBiletow.push_back(cena);
        std::cout << rodzajeBiletow.size() << ". " << typBiletu << ", " << cena << " PLN" << std::endl; // Wyświetlamy numer, nazwę biletu i cenę
    }


    plik.close(); // Zamykamy plik

    int numerBiletu;
    std::cout << "Wybierz numer typu biletu do zakupu: ";
    std::cin >> numerBiletu;

    if (numerBiletu >= 1 && numerBiletu <= rodzajeBiletow.size()) {
        std::string imie, nazwisko, numer;
        std::cout << "Podaj swoje imie: ";
        std::cin >> imie;
        std::cout << "Podaj swoje nazwisko: ";
        std::cin >> nazwisko;
        std::cout << "Podaj numer telefonu: ";
        std::cin >> numer;

        Zwiedzajacy zwiedzajacy(imie, nazwisko, numer);
        std::string typBiletu = rodzajeBiletow[numerBiletu - 1];
        double cenaBiletu = cenyBiletow[numerBiletu - 1];

        std::ofstream plikBilety("kupione_bilety.txt", std::ios::app); // Otwieramy plik w trybie dopisywania

        if (!plikBilety.is_open()) {
            std::cout << "Blad zapisu do pliku z kupionymi biletami." << std::endl;
            return;
        }

        // Zapisujemy informacje o zakupionym bilecie do pliku
        plikBilety << zwiedzajacy.getImie() << "," << zwiedzajacy.getNazwisko() << "," << zwiedzajacy.getNrTel() << "," << typBiletu << "," << cenaBiletu << std::endl;

        plikBilety.close(); // Zamykamy plik

        std::cout << "Bilet zostal zakupiony i zapisany." << std::endl;
    }
    else {
        std::cout << "Nieprawidlowy numer typu biletu." << std::endl;
    }
}

void Interfejs::zapiszBilet(const Zwiedzajacy& zwiedzajacy, const Bilet& bilet) {
    std::ofstream plik("kupione_bilety.txt", std::ios::app);
    if (plik.is_open()) {
        plik << zwiedzajacy.getImie() << ',' << zwiedzajacy.getNazwisko() << ',' << zwiedzajacy.getNrTel() << ','
            << bilet.getTyp() << ',' << bilet.getCena() << std::endl;
        plik.close();
        std::cout << "Bilet zostal pomyslnie zapisany." << std::endl;
    }
    else {
        std::cout << "Blad zapisu biletu." << std::endl;
    }
}

void Interfejs::wyswietlKupioneBilety() {
    std::ifstream plik("kupione_bilety.txt");
    if (plik.is_open()) {
        std::string imie, nazwisko, bilet, cena;
        int nr_tel;
        int numer = 1;

        std::cout << "Twoje kupione bilety:" << std::endl;
        while (std::getline(plik, imie, ',') && std::getline(plik, nazwisko, ',') && plik >> nr_tel && std::getline(plik >> std::ws, bilet, ',') && std::getline(plik, cena)) {
            std::cout << numer << ". " << imie << " " << nazwisko << ": " << bilet << " (" << cena << " PLN)" << std::endl;
            numer++;
        }

        plik.close();
    }
    else {
        std::cout << "Nie masz jeszcze zadnych kupionych biletow." << std::endl;
    }
}

void Interfejs::wyczyscPlikBiletow() {
    std::ofstream plik("kupione_bilety.txt", std::ios::out);
    if (plik.is_open()) {
        plik.close();
        //std::cout << "Plik z kupionymi biletami zostal wyczyszczony." << std::endl;
    }
    else {
        std::cout << "Blad czyszczenia pliku z kupionymi biletami." << std::endl;
    }
}

void Interfejs::exitu() {
    std::cout << "Zapraszamy ponownie!" << std::endl;
    std::cout << "Koniec programu" << std::endl;
    exit(0);
}

void Interfejs::exitp() {
    std::cout << "Koniec programu" << std::endl;
    exit(0);
}

Interfejs::~Interfejs() {
    for (auto it = zwierzeta.begin(); it != zwierzeta.end(); ++it) {
        delete* it;
    }
    for (auto it = bilety.begin(); it != bilety.end(); ++it) {
        delete* it;
    }
    for (auto it = wydarzenia.begin(); it != wydarzenia.end(); ++it) {
        delete* it;
    }
}