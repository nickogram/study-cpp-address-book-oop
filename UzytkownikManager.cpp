#include "UzytkownikManager.h"

string wczytajLinie() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void UzytkownikManager::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do {
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(wczytajLinie());
    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login) {
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow() {
    cout << " zalogowane ID: "<< pobierzIdZalogowanegoUzytkownika() << endl; //potem usunac
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikManager::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikManager::logowanieUzytkownika() {
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    bool loginStatus = false;
    bool findStatus = false;

    cout << endl << "Podaj login: ";
    login = wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            findStatus = true;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = wczytajLinie();
                if (itr -> pobierzHaslo() == haslo) {
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    loginStatus = true;
                    system("pause");
                    break;
                }
            }
            if (loginStatus != true) {
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                break;
            }
        }
        itr++;
    }
    if (findStatus != true) {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
    }
}

int UzytkownikManager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikManager::wylogowanieUzytkownika() {
    idZalogowanegoUzytkownika = 0;
    cout << "Skutecznie wylogowano uzytkownika" << endl;
}

void UzytkownikManager::zmianaHaslaZalogowanegoUzytkownika() {
    cout << "ID dla ktorego zmienane jest haslo: "<< pobierzIdZalogowanegoUzytkownika() << endl;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = wczytajLinie();

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika) {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
