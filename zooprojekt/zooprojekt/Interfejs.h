#pragma once
#ifndef INTERFEJS_H
#define INTERFEJS_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Zwierze.h"
#include "Bilet.h"
#include "Event.h"
#include "Plaz.h"
#include "Ssak.h"
#include "Gad.h"
#include "Ptak.h"
#include "Ryba.h"
#include "Personel.h"
#include "Zwiedzajacy.h"

/**
 * @class Interfejs
 * @brief Klasa reprezentująca interfejs aplikacji.
 * @details Zarządza zwierzętami, biletami, wydarzeniami i obsługą użytkownika.
 */
class Interfejs {
    std::vector<Zwierze*> zwierzeta;
    std::vector<Bilet*> bilety;
    std::vector<Event*> wydarzenia;
    std::vector<std::string> rodzajeBiletow;
    std::vector<double> cenyBiletow;
public:
    /**
     * @brief Konstruktor domyślny.
     */
    Interfejs();

    /**
     * @brief Destruktor.
     */
    ~Interfejs();

    /**
     * @brief Wyświetla menu główne aplikacji.
     * @return Wybrana opcja menu.
     */
    int menu();

    /**
     * @brief Wyświetla menu dla użytkownika.
     * @return Wybrana opcja menu użytkownika.
     */
    int menuUzytkownik();

    /**
     * @brief Wyświetla menu dla personelu.
     * @return Wybrana opcja menu personelu.
     */
    int menuPersonel();

    /**
     * @brief Dodaje zwierzę.
     */
    void dodajZwierze();

    /**
     * @brief Usuwa zwierzę o podanym imieniu.
     * @param numer Numer zwierzęcia z listy.
     */
    void usunZwierze(int numer);

    /**
     * @brief Wyświetla imiona wszystkich zwierząt.
     */
    void wyswietlImionaZwierzat();

    /**
     * @brief Dodaje bilet.
     */
    void dodajBilet();

    /**
     * @brief Usuwa bilet o podanym typie.
     * @param typ Typ biletu.
     */
    void usunBilet(std::string typ);

    /**
     * @brief Dodaje wydarzenie.
     */
    void dodajEvent();

    /**
     * @brief Usuwa wydarzenie o podanej nazwie.
     * @param nazwa Nazwa wydarzenia.
     */
    void usunEvent(std::string nazwa);

    /**
     * @brief Wyświetla cennik biletów.
     */
    void wyswietlCennik();

    /**
     * @brief Wyświetla wszystkie wydarzenia.
     */
    void wyswietlWydarzenia();

    /**
     * @brief Kupuje bilet przez internet.
     */
    void kupBiletPrzezInternet();

    /**
     * @brief Zapisuje informacje o zakupionym bilecie do pliku.
     * @param zwiedzajacy Informacje o zwiedzającym.
     * @param bilet Zakupiony bilet.
     */
    void zapiszBilet(const Zwiedzajacy& zwiedzajacy, const Bilet& bilet);

    /**
     * @brief Wyświetla informacje o wszystkich zakupionych biletach.
     */
    void wyswietlKupioneBilety();

    /**
     * @brief Wyczyść zawartość pliku z biletami.
     */
    void wyczyscPlikBiletow();

    /**
     * @brief Obsługuje wyjście z aplikacji dla użytkownika.
     */
    void exitu();

    /**
     * @brief Obsługuje wyjście z aplikacji dla personelu.
     */
    void exitp();
};

#endif
