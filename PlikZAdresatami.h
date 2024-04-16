#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy
{
    vector <Adresat> adresaciZalogowanegoUzytkownika;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata;

    string pobierzLiczbe();
    int konwersjaStringNaInt();

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    //int zwrocNumerLiniiSzukanegoAdresata();
    //void usunWybranaLinieWPliku();
    //void usunPlik();
    //void zmienNazwePliku();

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : PlikTekstowy(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {

    };

    int pobierzZPlikuIdOstatniegoAdresata();
    bool dopiszAdresataDoPliku(Adresat adresat);

    vector <Adresat> pobierzAdresatowZalogowanegoUzytkownika();
    void wyczyszczRejestrAdresatowZalogowanegoUzytkownika();

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    //void usunAdresata();
    //void zaktualizujDaneAdresata();
};

#endif
