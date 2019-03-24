#pragma once

#include "WINDOW.h"
#include "PIESA.h"
#include "MENU.h"
#include "GAMEMANAGER.h"
#include "GAMEZONE.H"

#include <SDL.h>
#include <vector>
#include <iostream>

using namespace std;

class GAME : WINDOW, GAME_MANAGER{

public :
    GAME ( int wBoard, int hBoard, int hBuffer, const char *BoardPath, int BoardSize, const char *BlackPath, const char *WhitePath, const char *BufferPath );
    bool AddPiesa( int x, int y, int wh, const char *str );
    void RenderEverything();
    void RunGame();
    bool Win();

private :


    SDL_Texture *background;
    MENU _menu;
    GAME_ZONE _gameZone;

    char _WhitePath[ 100 ];
    char _BlackPath[ 100 ];

};
