#include <iostream>
#include <vector>
#include <string>

/**
 * @class Zwiedzajacy
 * @brief Klasa reprezentująca zwiedzającego.
 */
class Zwiedzajacy {
    std::string imie;
    std::string nazwisko;
    std::string numer; 
    bool czyBiletKupiony; 
    std::vector<std::string> listaZwierzat; 

public:
    /**
     * @brief Konstruktor inicjalizujący dane zwiedzającego.
     * @param imie Imię zwiedzającego.
     * @param nazwisko Nazwisko zwiedzającego.
     * @param numer Numer telefonu zwiedzającego.
     */
    Zwiedzajacy(const std::string&, const std::string&, const std::string&);

    /**
    * @brief Destruktor.
    */
    ~Zwiedzajacy();

    /**
     * @brief Metoda do pobierania imienia zwiedzającego.
     * @return Imię zwiedzającego.
     */
    std::string getImie() const;

    /**
     * @brief Metoda do pobierania nazwiska zwiedzającego.
     * @return Nazwisko zwiedzającego.
     */
    std::string getNazwisko() const;

    /**
     * @brief Metoda do pobierania numeru telefonu zwiedzającego.
     * @return Numer telefonu zwiedzającego.
     */
    std::string getNrTel() const;
};
