#pragma once
#include "Zwierze.h"

/**
 * @class Gad
 * @brief Reprezentuje gadzi zwierzę.
 * @details Dziedziczy po klasie Zwierze.
 */
class Gad : public Zwierze {
	bool jadowite;
	int dl_ciala;
	std::string s_ruchu;

public:
	/**
	 * @brief Konstruktor domyślny.
	 */
	Gad();

	/**
	 * @brief Konstruktor inicjalizujący właściwości gada.
	 * @param imie Imię gada.
	 * @param gatunek Gatunek gada.
	 * @param pochodzenie Pochodzenie gada.
	 * @param dieta Dieta gada.
	 * @param dl_zycia Długość życia gada.
	 * @param sezon Sezon, w którym występuje gad.
	 * @param jadowite Flaga określająca czy gad jest jadowity.
	 * @param s_ruchu Sposób ruchu gada.
	 * @param dl_ciala Długość ciała gada.
	 */
	Gad(const std::string&, const std::string&, const std::string&, const std::string&, const int&, const std::string&, const bool&, const std::string&, const int&);

	/**
	 * @brief Destruktor.
	 */
	~Gad();

	/**
	 * @brief Pobiera informację, czy zwierzę jest jadowite.
	 * @return Wartość true, jeśli zwierzę jest jadowite. Wartość false w przeciwnym razie.
	 */
	bool getJadowite() const;

	/**
	 * @brief Pobiera długość ciała zwierzęcia.
	 * @return Długość ciała zwierzęcia.
	 */
	int getDlCiala() const;

	/**
	 * @brief Pobiera sposób poruszania się zwierzęcia.
	 * @return Sposób poruszania się zwierzęcia.
	 */
	std::string getSposobRuchu() const;

	/**
	 * @brief Wyświetla informacje o gadziem zwierzęciu.
	 */
	void pokazInfo() const override;
};