#include <iostream>
#include <SDL.h>

#include "../headers/GAME.h"

using namespace std;

int main(int argv, char** args)
{


    GAME test( 750, 750, 200, "../TABLA.bmp", 20, "../PIESA-NEAGRA.bmp", "../PIESA-ALBA.bmp", "../BUFFER.bmp" );
    test.RunGame();

    return 0;
}
