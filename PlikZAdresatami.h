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

class PlikZAdresatami : public PlikTekstowy {
    vector <Adresat> adresaciZalogowanegoUzytkownika;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "TymczasowyPlikZAdresatami.txt";
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami (Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : PlikTekstowy(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
    };

    int pobierzZPlikuIdOstatniegoAdresata();
    bool dopiszAdresataDoPliku(Adresat adresat);

    vector <Adresat> pobierzAdresatowZalogowanegoUzytkownika();
    void wyczyszczRejestrAdresatowZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    void usunAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneAdresata(Adresat adresat);
};

#endif
