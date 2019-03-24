#pragma once

#include <cstring>
#include <SDL.h>

#include "PIESA.h"
#include "CLICK_ACTION.h"
#include "RENDER.h"

class BOARD : public RENDER, public CLICK_ACTION  {

    char _BoardPath[ 100 ];
    int _wBoard, _hBoard;
    int _dim;

public :

    BOARD () {};
    BOARD ( int wBoard, int hBoard, int dim, const char * str ) {
        _dim = dim;
        _wBoard = wBoard;
        _hBoard = hBoard;
        strcpy( _BoardPath, str );
    }

    void SetPath( const char *str) {
        strcpy( _BoardPath, str );
    }

    int GetWidth() { return _wBoard; };
    int GetHight() { return _hBoard; };
    int GetDim() { return _dim; }

    void ClickAction( SDL_Event event ) {
    }

    SDL_Texture* RenderObject( SDL_Renderer * _render ) {

        SDL_Surface * aux = SDL_LoadBMP( _BoardPath );

        if ( aux == NULL ) {
            cout << "Failed to load board surface.\n";
            return NULL;
        }

        return SDL_CreateTextureFromSurface( _render, aux );

    }


};
