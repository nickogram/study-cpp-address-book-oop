#include "AdresatManager.h"

void AdresatManager::ustawIdZalogowanegoUzytkownika (int noweIdZalogowanegoUzytkownika) {
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

int AdresatManager::pobierzIdOstatniegoAdresataZPliku () {
    idOstatniegoAdresata = plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata();
    return idOstatniegoAdresata;
}

int AdresatManager::pobierzIdOstatniegoAdresataZAdresatManagera() {
    pobierzIdOstatniegoAdresataZPliku();
    return idOstatniegoAdresata;
}

void AdresatManager::pobierzAdresatowZalogowanegoUzytkownika() {
    plikZAdresatami.ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    adresaci = plikZAdresatami.pobierzAdresatowZalogowanegoUzytkownika();
    plikZAdresatami.wyczyszczRejestrAdresatowZalogowanegoUzytkownika();
}


void AdresatManager::wypiszWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatManager::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefomu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatManager::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
    adresaci.clear();

    cout << "Skutecznie wylogowano uzytkownika" << endl;
}

Adresat AdresatManager::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata) {
    Adresat adresat;

    adresat.ustawId(idOstatniegoAdresata+1);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatManager::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;

    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    idOstatniegoAdresata = idOstatniegoAdresata + 1;
}
