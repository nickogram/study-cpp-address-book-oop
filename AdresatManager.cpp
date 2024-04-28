#include "AdresatManager.h"

int AdresatManager::pobierzIdOstatniegoAdresataZPliku() {
    idOstatniegoAdresata = plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata();
    return idOstatniegoAdresata;
}

int AdresatManager::pobierzIdOstatniegoAdresataZAdresatManagera() {
    pobierzIdOstatniegoAdresataZPliku();
    return idOstatniegoAdresata;
}

void AdresatManager::pobierzAdresatowZalogowanegoUzytkownika() {
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

void AdresatManager::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    bool statusZnalezienia = false;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                statusZnalezienia = true;
                wyswietlDaneAdresata(*itr);
            }
        }
        if (statusZnalezienia != true) cout << endl << "Nie znaleziono danego adresata" << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatManager::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata = "";
    bool statusZnalezienia = false;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
            }
        }
        if (statusZnalezienia != true) cout << endl << "Nie znaleziono danego adresata" << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
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

Adresat AdresatManager::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzZPlikuIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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

    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);

    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << endl << "Nowy adresat zostal dodany" << endl << endl;
    else
        cout << endl << "Blad! Nie udaslo sie dodac nowego adresata do pliku." << endl << endl;

    system ("pause");
    idOstatniegoAdresata++;
}

int AdresatManager::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatManager::usunAdresata() {
    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                plikZAdresatami.usunAdresata(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                break;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    AdresatManager::pobierzAdresatowZalogowanegoUzytkownika();
}

void AdresatManager::edytujAdresata() {
    Adresat zmodyfikowanyAdresat;
    int idDoEdycji = 0, pozycjaDoEdycji = 0;
    bool czyIstniejeAdresat = false;
    bool czyZmodyfikowanoAdresata = false;

    system("cls");
    cout << ">>> Edycja Adresata <<<" << endl << endl;
    cout << "-----------------------" << endl;

    cout << "Prosze wprowadzic Id do edycji: " << endl;
    idDoEdycji = podajIdWybranegoAdresata();

    for (size_t i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idDoEdycji) {
            czyIstniejeAdresat = true;
            pozycjaDoEdycji = i;
            czyZmodyfikowanoAdresata = menuEdycjiAdresata(czyZmodyfikowanoAdresata, pozycjaDoEdycji);
            if (czyZmodyfikowanoAdresata == true) {
                zmodyfikowanyAdresat = adresaci[i];
                plikZAdresatami.zaktualizujDaneAdresata(zmodyfikowanyAdresat);
            }
            break;
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

bool AdresatManager::menuEdycjiAdresata (bool czyWprowadzonoZmiany, int pozycjaDoEdycji) {
    while (true) {
        system("cls");
        cout << ">>> Menu edycji <<<" << endl << endl;
        cout << "1. Zmien imie " << endl;
        cout << "2. Zmien nazwisko " << endl;
        cout << "3. Zmien numer telefonu " << endl;
        cout << "4. Zmien e-mail " << endl;
        cout << "5. Zmien adress " << endl;
        cout << "6. Wroc do glownego menu " << endl << endl;

        cout << "Twoj wybor: ";
        char wyborMenu = MetodyPomocnicze::wczytajZnak();

        switch(wyborMenu) {
        case '1':
            cout << endl << "Nowe imie: ";
            adresaci[pozycjaDoEdycji].ustawImie(MetodyPomocnicze::wczytajLinie());
            czyWprowadzonoZmiany = true;
            break;
        case '2':
            cout << endl << "Nowe nazwisko: ";
            adresaci[pozycjaDoEdycji].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
            czyWprowadzonoZmiany = true;
            break;
        case '3':
            cout << endl << "Nowy numer telefonu: ";
            adresaci[pozycjaDoEdycji].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
            czyWprowadzonoZmiany = true;
            break;
        case '4':
            cout << endl << "Nowe e-mail: ";
            adresaci[pozycjaDoEdycji].ustawEmail(MetodyPomocnicze::wczytajLinie());
            czyWprowadzonoZmiany = true;
            break;
        case '5':
            cout << endl << "Nowe adres: ";
            adresaci[pozycjaDoEdycji].ustawAdres(MetodyPomocnicze::wczytajLinie());
            czyWprowadzonoZmiany = true;
            break;
        case '6':
            cout << endl << "Nie wprowadzono zadnych zmian." << endl ;
            system("pause");
            break;
        }
        break;
    }
    return czyWprowadzonoZmiany;
}
