#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikManager.h"
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;

    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikManager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatManager = NULL;
    };

    ~KsiazkaAdresowa()
    {
      delete adresatManager;
      adresatManager = NULL;
    };

    void rejestracjaUzytkownika();

    void logowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();

    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();

    void dodajAdresata();
    void wypiszWszystkichAdresatowZalogowanegoUzytkownika();

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
