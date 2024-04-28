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
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;

    int idOstatniegoAdresata;

    Adresat podajDaneNowegoAdresata();
    int pobierzIdOstatniegoAdresataZPliku();
    int podajIdWybranegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    bool menuEdycjiAdresata(bool czyWprowadzonoZmiany, int pozycjaDoEdycji);

public:
    AdresatManager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika), plikZAdresatami(nazwaPlikuZAdresatami, ID_ZALOGOWANEGO_UZYTKOWNIKA) {
        pobierzAdresatowZalogowanegoUzytkownika();
    };

    int pobierzIdOstatniegoAdresataZAdresatManagera();
    void pobierzAdresatowZalogowanegoUzytkownika();

    void dodajAdresata();
    void wypiszWszystkichAdresatow();

    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void usunAdresata();
    void edytujAdresata();

};

#endif

