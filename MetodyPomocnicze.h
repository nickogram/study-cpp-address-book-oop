#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>

#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString (int liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    static char wczytajZnak();
};

#endif
