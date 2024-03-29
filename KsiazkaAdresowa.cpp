#include "KsiazkaAdresowa.h"

char wczytajZnak() {
    string wejscie = "";
    char znak  = {0};

    while (true) {
        getline(cin, wejscie);

        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}


void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikManager.logowanieUzytkownika();
    uzytkownikManager.pobierzIdZalogowanegoUzytkownika();

    adresatManager.ustawIdZalogowanegoUzytkownika(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    adresatManager.pobierzAdresatowZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return uzytkownikManager.pobierzIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::pobierzIdOstatniegoAdresata() {
    return adresatManager.pobierzIdOstatniegoAdresataZAdresatManagera();
}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikManager.wylogowanieUzytkownika();
    adresatManager.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {
    adresatManager.dodajAdresata();
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    adresatManager.wypiszWszystkichAdresatow();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << " Id Zalogowanego Uzytkownika: "<< pobierzIdZalogowanegoUzytkownika() << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << " Id Zalogowanego Uzytkownika: "<< pobierzIdZalogowanegoUzytkownika() << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "NIEWPROWADZONO 2. Wyszukaj po imieniu" << endl;
    cout << "NIEWPROWADZONO 3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "NIEWPROWADZONO 5. Usun adresata" << endl;
    cout << "NIEWPROWADZONO 6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}
