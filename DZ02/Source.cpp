#include "Game_of_life.h"

int main()
{
    Game_of_life game(60, 20);
    //game.postavi_dimenzije_polja(); //ne radi jos
    game.start();
    do
    {
        game.sljedeci_ciklus();
    } while (true);
    return 0;
}