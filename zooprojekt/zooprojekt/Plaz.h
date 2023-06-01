#pragma once
#include "Zwierze.h"

/**
 * @class Plaz
 * @brief Klasa reprezentująca płazy.
 */
class Plaz : public Zwierze {
	bool wodne;
	std::string kolor_skory;
	std::string sp_rozmnazania; 

public:
	/**
	 * @brief Konstruktor domyślny.
	 */
	Plaz();

	/**
	 * @brief Konstruktor inicjalizujący właściwości płaza.
	 * @param imie Imię płaza.
	 * @param gatunek Gatunek płaza.
	 * @param pochodzenie Pochodzenie płaza.
	 * @param dieta Dieta płaza.
	 * @param dl_zycia Długość życia płaza.
	 * @param sezon Sezon, w którym występuje płaz.
	 * @param kolor_skory Kolor skóry płaza.
	 * @param wodne Flaga określająca, czy płaz jest wodny.
	 * @param sp_rozmnazania Sposób rozmnażania płaza.
	 */
	Plaz(const std::string&, const std::string&, const std::string&, const std::string&, const int&, const std::string&, const bool&, const std::string&, const std::string&);

	/**
	 * @brief Destruktor.
	 */
	~Plaz();

	/**
	 * @brief Metoda do pobierania informacji o tym, czy płaz jest wodny.
	 * @return Wartość logiczna określająca, czy płaz jest wodny.
	 */
	bool getWodne() const;

	/**
	 * @brief Metoda do pobierania informacji o kolorze skóry płaza.
	 * @return Kolor skóry płaza.
	 */
	std::string getKolorSkory() const;

	/**
	 * @brief Metoda do pobierania informacji o sposobie rozmnażania płaza.
	 * @return Sposób rozmnażania płaza.
	 */
	std::string getSpRozmnazania() const;

	/**
	 * @brief Metoda wyświetlająca informacje o płazie.
	 */
	void pokazInfo() const override;
};
