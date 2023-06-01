#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

 /**
  * @class Bilet
  * @brief Reprezentuje bilet.
  */
class Bilet {
    std::string typ;
    double cena;
public:
    /**
     * @brief Konstruktor domyślny.
     */
    Bilet();

    /**
     * @brief Konstruktor parametryczny.
     * @param typ Typ biletu.
     * @param cena Cena biletu.
     */
    Bilet(const std::string& typ, const double& cena);

    /**
     * @brief Destruktor.
     */
    ~Bilet();

    /**
     * @brief Pobiera typ biletu.
     * @return Typ biletu.
     */
    std::string getTyp() const;

    /**
     * @brief Pobiera cenę biletu.
     * @return Cena biletu.
     */
    double getCena() const;

    /**
     * @brief Wyświetla informacje o bilecie.
     */
    virtual void pokazInfo() const;

    /**
     * @brief Odczytuje wszystkie bilety z pliku.
     * @param nazwapliku Nazwa pliku.
     * @return Wektor zawierający wszystkie bilety odczytane z pliku.
     */
    static std::vector<Bilet> odczytajWszystkieZPliku(const std::string& nazwapliku);
};