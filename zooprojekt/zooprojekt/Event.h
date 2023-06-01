#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

/**
 * @class Event
 * @brief Reprezentuje wydarzenie.
 */
class Event {
    std::string nazwa;
    std::string czas;
    std::string data;
public:
    /**
     * @brief Konstruktor domyślny.
     */
    Event();

    /**
     * @brief Konstruktor parametryczny.
     * @param nazwa Nazwa wydarzenia.
     * @param czas Czas wydarzenia.
     * @param data Data wydarzenia.
     */
    Event(const std::string& nazwa, const std::string& czas, const std::string& data);

    /**
     * @brief Destruktor.
     */
    ~Event();

    /**
     * @brief Pobiera nazwę wydarzenia.
     * @return Nazwa wydarzenia.
     */
    std::string getNazwa() const;

    /**
     * @brief Pobiera czas wydarzenia.
     * @return Czas wydarzenia.
     */
    std::string getCzas() const;

    /**
     * @brief Pobiera datę wydarzenia.
     * @return Data wydarzenia.
     */
    std::string getData() const;

    /**
     * @brief Odczytuje wszystkie wydarzenia z pliku.
     * @param nazwapliku Nazwa pliku.
     * @return Wektor zawierający wszystkie wydarzenia odczytane z pliku.
     */
    static std::vector<Event> odczytajWszystkieZPliku(const std::string& nazwapliku);

    /**
     * @brief Wyświetla godziny otwarcia dla danego wydarzenia.
     */
    void godzinyOtwarcia();

    /**
    * @brief Przeciążenie operatora strumieniowego dla wyjścia.
    *
    * Przeciążony operator << umożliwia wygodne wyświetlanie obiektów klasy Event
    * na strumieniu wyjściowym, takim jak std::cout czy strumienie plikowe.
    *
    * @param os Referencja do strumienia wyjściowego.
    * @param event Referencja do obiektu klasy Event, który ma być wyświetlony.
    * @return Referencja do strumienia wyjściowego po operacji wyświetlenia.
    */
    friend std::ostream& operator<<(std::ostream& os, const Event& event);
};