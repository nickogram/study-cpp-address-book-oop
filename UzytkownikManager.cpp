#include "UzytkownikManager.h"

string wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

void UzytkownikManager::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikManager::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika(); - tak bylo
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika()); // tak stalo

    do
    {
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(wczytajLinie()); // = wczytajLinie();
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(wczytajLinie()); // = wczytajLinie();

    return uzytkownik;
}

int UzytkownikManager::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikManager::czyIstniejeLogin(string login)
{
    for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikManager::wypiszWszystkichUzytkownikow()
{
       for (size_t i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}