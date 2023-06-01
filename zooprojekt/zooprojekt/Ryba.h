#pragma once
#include <string>
#include "Zwierze.h"

/**
 * @class Ryba
 * @brief Klasa reprezentująca ryby.
 */
class Ryba : public Zwierze {
    bool jajorodne;
    double dlugosc; 
    std::string rodzaj_skrzeli; 

public:
    /**
     * @brief Konstruktor domyślny.
     */
    Ryba();

    /**
     * @brief Konstruktor inicjalizujący właściwości ryby.
     * @param imie Imię ryby.
     * @param gatunek Gatunek ryby.
     * @param pochodzenie Pochodzenie ryby.
     * @param dieta Dieta ryby.
     * @param dl_zycia Długość życia ryby.
     * @param sezon Sezon, w którym występuje ryba.
     * @param jajorodne Flaga określająca, czy ryba jest jajorodna.
     * @param dlugosc Długość ryby.
     * @param rodzaj_skrzeli Rodzaj skrzeli ryby.
     */
    Ryba(const std::string&, const std::string&, const std::string&, const std::string&, const int&, const std::string&, const bool&, const double&, const std::string&);

    /**
     * @brief Destruktor.
     */
    ~Ryba();

    /**
     * @brief Metoda do pobierania informacji o tym, czy ryba jest jajorodna.
     * @return Wartość logiczna określająca, czy ryba jest jajorodna.
     */
    bool getJajorodne() const;

    /**
     * @brief Metoda do ustawiania informacji o tym, czy ryba jest jajorodna.
     * @param jajorodne Wartość logiczna określająca, czy ryba jest jajorodna.
     */
    void setJajorodne(bool jajorodne);

    /**
     * @brief Metoda do pobierania informacji o długości ryby.
     * @return Długość ryby.
     */
    double getDlugosc() const;

    /**
     * @brief Metoda do ustawiania informacji o długości ryby.
     * @param dlugosc Długość ryby.
     */
    void setDlugosc(double dlugosc);

    /**
     * @brief Metoda do pobierania informacji o rodzaju skrzeli ryby.
     * @return Rodzaj skrzeli ryby.
     */
    std::string getRodzajSkrzeli() const;

    /**
     * @brief Metoda do ustawiania informacji o rodzaju skrzeli ryby.
     * @param rodzaj_skrzeli Rodzaj skrzeli ryby.
     */
    void setRodzajSkrzeli(const std::string& rodzaj_skrzeli);

    /**
     * @brief Metoda wyświetlająca informacje o rybie.
     */
    void pokazInfo() const override;
};
