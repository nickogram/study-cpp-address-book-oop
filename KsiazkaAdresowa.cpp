#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikJestZalogowany()) {
        adresatManager = new AdresatManager (NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    if (uzytkownikManager.czyUzytkownikJestZalogowany()) return false;
    else return true;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager;
    adresatManager = NULL;
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatManager->dodajAdresata();
}

void KsiazkaAdresowa::usunAdresata() {
    adresatManager->usunAdresata();
}

void KsiazkaAdresowa::edytujAdresata() {
    adresatManager->edytujAdresata();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatowZalogowanegoUzytkownika() {
    adresatManager->wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu() {
    adresatManager->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku() {
    adresatManager->wyszukajAdresatowPoNazwisku();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << " IdZalogowanegoUzytkownika: "<< uzytkownikManager.pobierzIdZalogowanegoUzytkownika() << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << " IdZalogowanegoUzytkownika: "<< uzytkownikManager.pobierzIdZalogowanegoUzytkownika() << endl;
    cout << " IdOstatniegoAdresata: " << adresatManager -> pobierzIdOstatniegoAdresataZAdresatManagera() <<endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
