#include <iostream>
#include <SDL.h>

#include "../headers/GAME.h"

using namespace std;

int main(int argv, char** args)
{


    GAME test( 800, 800, 200, "../TABLA.BMP", 21, "../PIESA-NEAGRA.bmp", "../PIESA-ALBA.bmp", "../BUFFER.bmp" );
    test.RunGame();

    return 0;
}
