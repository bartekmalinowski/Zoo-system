#ifndef PERSONEL_H
#define PERSONEL_H

#include "Interfejs.h"
#include <string>

/**
 * @class Personel
 * @brief Klasa reprezentująca personel obsługujący aplikację.
 */
class Personel {
    std::string login; 
    std::string haslo; 

public:
    /**
     * @brief Konstruktor domyślny.
     */
    Personel();

    /**
     * @brief Konstruktor inicjalizujący login i hasło personelu.
     * @param login Login personelu.
     * @param haslo Hasło personelu.
     */
    Personel(const std::string& login, const std::string& haslo);

    /**
    * @brief Destruktor.
    */
    ~Personel();

    /**
     * @brief Metoda do autoryzacji personelu.
     */
    void autoryzacja();
};

#endif // PERSONEL_H
