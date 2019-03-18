#pragma once

#include "WINDOW.h"
#include "PIESA.h"
#include "UTIL.h"

#include <SDL.h>
#include <vector>
#include <iostream>

using namespace std;

class GAME : WINDOW {

public :
    GAME ( int wBoard, int hBoard, int hBuffer, const char *BoardPath, int BoardSize, const char *BlackPath, const char *WhitePath, const char *BufferPath );
    bool AddPiesa( int x, int y, int wh, const char *str );

    void PresentGame();
    void LoadPiese();
    void LoadBoard( const char *str );
    void RenderEverything();
    void RunGame();
    void LoadBuffer();
    bool Win();

private :

    SDL_Texture *background;
    vector < PIESA > _piese;
    vector < vector <int> >Board;
    int _wBoard, _hBoard;
    int _hBuffer;

    char _BoardPath[ 100 ];
    char _WhitePath[ 100 ];
    char _BlackPath[ 100 ];
    char _BufferPath[ 100 ];
    int _BoardSize;

};
