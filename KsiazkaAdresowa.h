#include <iostream>
#include <vector>

#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    vector <Uzytkownik> uzytkownicy;

private: //nie musi tego byc bo wszystko od class w dol jest private az do innego punktora
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin (string login);
public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
};
