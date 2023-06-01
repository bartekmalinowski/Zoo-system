//#include <iostream>
//#include <string>
//#include <vector>
//#include "Zwierze.h"
//#include "Bilet.h"
//#include "Event.h"
//
//class Zoo {
//public:
//	Zoo();
//	Zoo(const std::string& nazwa, const std::string& adres);
//
//	void dodajZwierze(const Zwierze& zwierze);
//	void usunZwierze(const std::string& imie);
//	std::vector<Zwierze> getZwierzeta() const;
//	std::vector<Zwierze> szukajZwierzatPoImieniu(const std::string& imie) const;
//
//	void dodajBilet(const Bilet& bilet);
//	void usunBilet(const std::string& typ);
//	std::vector<Bilet> getBilety() const;
//
//	void dodajEvent(const Event& event);
//	void usunEvent(const std::string& nazwa);
//	std::vector<Event> getEvents() const;
//	std::vector<Event> szukajEventuPoNazwie(const std::string& nazwa);
//
//	void pokazGodzinyOtwarcia() const;
//	void pokazCaleInfo() const;
//private:
//	std::string nazwa;
//	std::string adres;
//
//	std::vector<Zwierze> zwierzeta;
//	std::vector<Bilet> bilety;
//	std::vector<Event> eventy;
//	std::vector<std::string> godzinyotwarcia;
//};

#ifndef ZOO_H
#define ZOO_H

#include <string>
#include <vector>

#include "Zwierze.h"
#include "Bilet.h"
#include "Event.h"
#include "Plaz.h"
#include "Ryba.h"
#include "Ssak.h"
#include "Gad.h"
#include "Ptak.h"
#include "Ryba.h"

class Zoo {
public:
    Zoo();
    ~Zoo();
    void dodajZwierze();
    void usunZwierze(std::string imie);
    void wyszukajZwierze(std::string& imie);
    //void wyszukajZwierze(const std::string&) const;
    void dodajBilet();
    void usunBilet(std::string typ);
   void dodajEvent();
   //void usunEvent(std::string nazwa);
   // void wyszukajEvent(std::string nazwa);
private:
    std::vector<Zwierze*> zwierzeta;
    std::vector<Bilet*> bilety;
   std::vector<Event*> wydarzenia;
};

#endif
