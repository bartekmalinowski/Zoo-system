#pragma once
#include "Zwierze.h"

/**
 * @class Ptak
 * @brief Klasa reprezentująca ptaki.
 */
class Ptak : public Zwierze {
	bool latajace; 
	double rozpietosc_skrzydel; 
	std::string rodzaj_gniazda; 
	bool migracje;

public:
	/**
	 * @brief Konstruktor domyślny.
	 */
	Ptak();

	/**
	 * @brief Konstruktor inicjalizujący właściwości ptaka.
	 * @param imie Imię ptaka.
	 * @param gatunek Gatunek ptaka.
	 * @param pochodzenie Pochodzenie ptaka.
	 * @param dieta Dieta ptaka.
	 * @param dl_zycia Długość życia ptaka.
	 * @param sezon Sezon, w którym występuje ptak.
	 * @param latajace Flaga określająca, czy ptak jest latający.
	 * @param rozpietosc_skrzydel Rozpiętość skrzydeł ptaka.
	 * @param rodzaj_gniazda Rodzaj gniazda, w którym ptak się gnieździ.
	 * @param migracje Flaga określająca, czy ptak wykonuje migracje.
	 */
	Ptak(const std::string& i, const std::string& g, const std::string& p, const std::string& d, const int& dl, const std::string& s, const bool& latajace, const double& rozpietosc_skrzydel, const std::string& rodzaj_gniazda, const bool& migracje);

	/**
	 * @brief Destruktor.
	 */
	~Ptak();

	/**
	 * @brief Metoda do pobierania informacji o tym, czy ptak jest latający.
	 * @return Wartość logiczna określająca, czy ptak jest latający.
	 */
	bool getLatajacy() const;

	/**
	 * @brief Metoda do pobierania informacji o rozpiętości skrzydeł ptaka.
	 * @return Rozpiętość skrzydeł ptaka.
	 */
	double getRozpietoscSkrzydel() const;

	/**
	 * @brief Metoda do pobierania informacji o rodzaju gniazda, w którym ptak się gnieździ.
	 * @return Rodzaj gniazda ptaka.
	 */
	std::string getRodzajGniazda() const;

	/**
	 * @brief Metoda do pobierania informacji o migracjach ptaka.
	 * @return Wartość logiczna określająca, czy ptak wykonuje migracje.
	 */
	bool getMigracje() const;

	/**
	 * @brief Metoda wyświetlająca informacje o ptaku.
	 */
	void pokazInfo() const override;
};
