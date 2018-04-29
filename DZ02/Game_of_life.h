#pragma once

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


class Game_of_life
{
private:
    int visina;
    int sirina;
    std::vector<bool> zivoti;
    std::vector<bool> zivoti_pomocna;
    void pocetno_namjestanje_polja();
    bool pocetno_generiranje_zivota();
    int brojac_okolnih_true_polja(std::vector<bool>& zivoti, int inkrement);

public:
    Game_of_life(int visina, int sirina);
    //void postavi_dimenzije_polja();
    void start();
    void sljedeci_ciklus();
};



