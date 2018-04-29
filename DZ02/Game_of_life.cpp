#include "Game_of_life.h"


    //Visina igrace ploce
    int visina;

    //Sirina igrace ploce
    int sirina;

    //Glavni vektor za spremanje zivota
    vector<bool> zivoti;

    //Pomocni vektor za pospremanje zivota
    vector<bool> zivoti_pomocna;

    //Izradjuje pocetno polje na temelju generiranih vrijednosti iz metode pocetno_generiranje_zivota()
    void Game_of_life::pocetno_namjestanje_polja()
    {
        //Inicijalizacija pomocne varijable koja sluzi kao hodalica po poljima, tj. jedan pomak je jedno polje
        int pomak = 0;

        //Generira zivote i gura ih u vektor
        for (int i = 0; i < sirina*visina; i++)
        {
            zivoti.push_back(pocetno_generiranje_zivota());
        }

        //Iscrtava polje na temelju glavnog vektora zivoti
        for (int i = 0; i < visina; i++)
        {
            for (int i = 0; i < sirina; i++)
            {
                if (zivoti.at(pomak))
                {
                    cout << "X";
                }
                else
                {
                    cout << "_";
                }
                pomak++;
            }
            cout << endl;
        }
    }

    //Generira random zivote i sprema T ili F u vektor
    bool Game_of_life::pocetno_generiranje_zivota()
    {
        //Generiranje random broja
        int rng = rand() % (4 - 1 + 1) + 1;

        //Generira zivot ako je dobio broj 2, u suprotnom vraca false
        if (rng == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //Broji true statemente u okolnih 8 polja od dezigniranog polja
    int Game_of_life::brojac_okolnih_true_polja(vector<bool>& zivoti, int pomak)
    {

        int brojac = 0;
        int stupac = pomak % this->sirina;
        int velicina = zivoti.size();
        if (stupac != 0) // lijeve
        {
            // NW
            if (pomak > this->sirina)
            {
                if (zivoti[pomak - this->sirina - 1])
                {
                    brojac++;
                }
            }
            // W
            if (pomak != 0) // this is always true, you dint need this if
            {
                if (zivoti[pomak - 1])
                {
                    brojac++;
                }
            }
            // SW
            if (pomak <= velicina - this->sirina - 1)
            {
                if (zivoti[pomak + this->sirina - 1])
                {
                    brojac++;
                }
            }
        }
        if (stupac != (this->sirina - 1)) // desne
        {
            // NE
            if (pomak > sirina + 1)
            {
                if (zivoti[pomak - this->sirina + 1])
                {
                    brojac++;
                }
            }
            // SE
            if (pomak < velicina - this->sirina - 1) // - 1 ?
            {
                if (zivoti[pomak + this->sirina + 1])
                {
                    brojac++;
                }
            }
            // E ?
            if (pomak < velicina - 1) // ionako nije zadnja tocka jer ne smije biti zadnji stupac
            {
                if (zivoti[pomak + 1])
                {
                    brojac++;
                }
            }
        }
       // N
        if (pomak >= sirina)
        {
            if (zivoti[pomak - this->sirina])
            {
                brojac++;
            }
        }  
        // S
        if (pomak < zivoti.size() - this->sirina)
        {
            if (zivoti[pomak + this->sirina])
            {
                brojac++;
            }
        }
        return brojac;
    }


    /*//Nudi mogucnost promjene velicine igraceg polja- NE RADI
    void Game_of_life::postavi_dimenzije_polja()
    {
        char c;
        cout << "Default sirina je " << this->sirina << " a visina " << this->visina << endl << "Zelite li postaviti velicinu polja (d/n)? ";
        cin >> c;
        if (c == 'd')
        {
            cout << "Sirina polja: ";
            cin >> this->sirina;
            cout << "Visina polja: ";
            cin >> this->sirina;
        }
        system("cls");
    }*/

    Game_of_life::Game_of_life(int sirina, int visina)
    {
        this->sirina = sirina;
        this->visina = visina;
    }

    //Pocetak igre
    void Game_of_life::start()
    {
        srand(time(nullptr));
        system("cls");
        pocetno_namjestanje_polja();
        system("pause");
    }

    //Metoda za zapocinjanje novog ciklusa zivota
    void Game_of_life::sljedeci_ciklus()
    {
        system("cls");

        //Petlje za provjeravanje pojedinacnih polja i gura T ili F u pomocni vektor
        for (int pomak = 0; pomak < sirina*visina; pomak++)
        {
            if (zivoti[pomak])
            {
                if (brojac_okolnih_true_polja(zivoti, pomak) == 2 || brojac_okolnih_true_polja(zivoti, pomak) == 3)
                {
                    zivoti_pomocna.push_back(true);
                }
                else
                {
                    zivoti_pomocna.push_back(false);
                }

            }
            else
            {
                if (brojac_okolnih_true_polja(zivoti, pomak) == 3)
                {
                    zivoti_pomocna.push_back(true);
                }
                else
                {
                    zivoti_pomocna.push_back(false);
                }
            }
        }

        //Kopiram iz pomocnog u glavni vektor i cistim pomocni vektor kako bi bio spreman za sljedeci ciklus
        zivoti = zivoti_pomocna;
        zivoti_pomocna.clear();

        //Ispis ploce
        int pomak = 0;
        for (int i = 0; i < visina; i++)
        {
            for (int i = 0; i < sirina; i++)
            {
                if (zivoti.at(pomak))
                {
                    cout << "X";
                }
                else
                {
                    cout << "_";
                }
                pomak++;
            }
            cout << endl;
        }
        system("pause");
    }
