#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::pobierzAdresatowZalogowanegoUzytkownika() {
    return adresaciZalogowanegoUzytkownika;
}

void PlikZAdresatami::wyczyszczRejestrAdresatowZalogowanegoUzytkownika() {
    adresaciZalogowanegoUzytkownika.clear();
}

void PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(ID_ZALOGOWANEGO_UZYTKOWNIKA == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaciZalogowanegoUzytkownika.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneJednegoAddresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneJednegoAddresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoAddresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneJednegoAddresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata() {
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        plikTekstowy.close();
        return true;
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
        system("pause");
        return false;
    }
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefomu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

void PlikZAdresatami::usunAdresata(int idUsuwanegoAdresata) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int nrLinii = 1;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(),ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(),ios::out);

    if (odczytywanyPlikTekstowy.good() == true && tymczasowyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                // pomijamy linie podczas przepisywania
            } else {
                if (nrLinii > 1)
                    tymczasowyPlikTekstowy << endl;
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                nrLinii++;
            }
        }
    } else {
        cout << "Nie udalo sie otworzyc jednego z plikow: " << pobierzNazwePliku() << " lub "
             << NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI << "i zapisac w nim danych." << endl << " Awaryjne zamkniecie programu" << endl;
        exit(0);
    }

    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    remove (pobierzNazwePliku().c_str());
    zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, pobierzNazwePliku());
}

void PlikZAdresatami::zaktualizujDaneAdresata(Adresat adresat) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    int nrLinii = 1;

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(),ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(),ios::out);

    if (odczytywanyPlikTekstowy.good() == true && tymczasowyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if (nrLinii > 1) tymczasowyPlikTekstowy << endl;

            if (adresat.pobierzId() == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                tymczasowyPlikTekstowy << zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
            } else {
                tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
            }
            nrLinii++;
        }
    } else {
        cout << "Nie udalo sie otworzyc jednego z plikow: " << pobierzNazwePliku() << " lub "
             << NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI << "i zapisac w nim danych." << endl << " Awaryjne zamkniecie programu" << endl;
        exit(0);
    }

    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    remove (pobierzNazwePliku().c_str());
    zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, pobierzNazwePliku());
}
