#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {
    vector <Adresat> adresaciZalogowanegoUzytkownika;
    const string nazwaPlikuZAdresatami;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty(fstream &plikTekstowy);
    string pobierzLiczbe();
    int konwersjaStringNaInt();

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    void znajdzWPlikuIdOstatniegoAdresata();


public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};

    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
    int pobierzZPlikuIdOstatniegoAdresata();

    void dopiszAdresataDoPliku(Adresat adresat);

    vector <Adresat> pobierzAdresatowZalogowanegoUzytkownika();
    void wyczyszczRejestrAdresatowZalogowanegoUzytkownika();

    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
