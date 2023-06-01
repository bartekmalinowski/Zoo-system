#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

/**
 * @class Zwierze
 * @brief Klasa przechowująca informacje o zwierzętach.
 */
class Zwierze {
protected:
	std::string imie; 
	std::string gatunek; 
	std::string pochodzenie; 
	std::string dieta; 
	int dl_zycia; 
	std::string sezon; 

public:
	/**
	 * @brief Konstruktor domyślny.
	 */
	Zwierze();

	/**
	 * @brief Konstruktor inicjalizujący dane zwierzęcia.
	 * @param imie Imię zwierzęcia.
	 * @param gatunek Gatunek zwierzęcia.
	 * @param pochodzenie Pochodzenie zwierzęcia.
	 * @param dieta Dieta zwierzęcia.
	 * @param dl_zycia Długość życia zwierzęcia.
	 * @param sezon Sezon, w którym występuje zwierzę.
	 */
	Zwierze(const std::string&, const std::string&, const std::string&, const std::string&, const int&, const std::string&);

	/**
	 * @brief Destruktor.
	 */
	~Zwierze();

	/**
	 * @brief Metoda do pobierania imienia zwierzęcia.
	 * @return Imię zwierzęcia.
	 */
	std::string getImie() const;

	/**
	 * @brief Metoda do pobierania gatunku zwierzęcia.
	 * @return Gatunek zwierzęcia.
	 */
	std::string getGatunek() const;

	/**
	 * @brief Metoda do pobierania pochodzenia zwierzęcia.
	 * @return Pochodzenie zwierzęcia.
	 */
	std::string getPochodzenie() const;

	/**
	 * @brief Metoda do pobierania diety zwierzęcia.
	 * @return Dieta zwierzęcia.
	 */
	std::string getDieta() const;

	/**
	 * @brief Metoda do pobierania długości życia zwierzęcia.
	 * @return Długość życia zwierzęcia.
	 */
	int getDlZycia() const;

	/**
	 * @brief Metoda do pobierania sezonu, w którym występuje zwierzę.
	 * @return Sezon występowania zwierzęcia.
	 */
	std::string getSezon() const;

	/**
	 * @brief Metoda wirtualna do wyświetlania informacji o zwierzęciu.
	 * Metoda wymaga implementacji w klasach pochodnych.
	 */
	virtual void pokazInfo() const = 0;
};
