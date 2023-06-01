#pragma once
#include "Zwierze.h"

/**
 * @class Ssak
 * @brief Klasa reprezentująca ssaki.
 */
class Ssak : public Zwierze {
	bool zagrozone; 
	int liczba_pazurow; 
	std::string tryb_zycia;

public:
	/**
	 * @brief Konstruktor domyślny.
	 */
	Ssak();

	/**
	 * @brief Konstruktor inicjalizujący właściwości ssaka.
	 * @param imie Imię ssaka.
	 * @param gatunek Gatunek ssaka.
	 * @param pochodzenie Pochodzenie ssaka.
	 * @param dieta Dieta ssaka.
	 * @param dl_zycia Długość życia ssaka.
	 * @param sezon Sezon, w którym występuje ssak.
	 * @param zagrozone Flaga określająca, czy ssak jest zagrożony.
	 * @param liczba_pazurow Liczba pazurów ssaka.
	 * @param tryb_zycia Tryb życia ssaka.
	 */
	Ssak(const std::string&, const std::string&, const std::string&, const std::string&, const int&, const std::string&, const bool&, const int&, const std::string&);

	/**
	 * @brief Destruktor.
	 */
	~Ssak();

	/**
	 * @brief Metoda do pobierania informacji o tym, czy ssak jest zagrożony.
	 * @return Wartość logiczna określająca, czy ssak jest zagrożony.
	 */
	bool getZagrozony() const;

	/**
	 * @brief Metoda do pobierania informacji o liczbie pazurów ssaka.
	 * @return Liczba pazurów ssaka.
	 */
	int getLiczbaPazurow() const;

	/**
	 * @brief Metoda do pobierania informacji o trybie życia ssaka.
	 * @return Tryb życia ssaka.
	 */
	std::string getTrybZycia() const;

	/**
	 * @brief Metoda wyświetlająca informacje o ssaku.
	 */
	void pokazInfo() const override;
};
