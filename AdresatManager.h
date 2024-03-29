#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatManager {
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    int pobierzIdOstatniegoAdresataZPliku();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatManager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};

    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);

    int pobierzIdOstatniegoAdresataZAdresatManagera();
    void pobierzAdresatowZalogowanegoUzytkownika();
    void dodajAdresata();
    void wypiszWszystkichAdresatow();

    void wylogowanieUzytkownika();
};

#endif

