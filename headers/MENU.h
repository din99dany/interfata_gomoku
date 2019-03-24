#pragma once

#include <cstring>
#include "RENDER.h"
#include "GAMEMANAGER.h"

class MENU : public RENDER {

    char _NewButtonPath[ 100 ];
    int _wMenu, _hMenu;

public :

    MENU () {};

    MENU ( int wMenu, int hMenu, const char* str ) {
        _wMenu = wMenu;
        _hMenu = hMenu;
        strcpy( _NewButtonPath, str );
    };

    int GetWidth() { return _wMenu; }
    int GetHight() { return _hMenu; }

    void SetPath( const char *str ) { strcpy( _NewButtonPath, str ); }

    SDL_Texture* RenderObject( SDL_Renderer * _render ) {
        SDL_Surface * aux = SDL_LoadBMP(_NewButtonPath );

        if ( aux == NULL ) {
            cout << "Failed to load menu surface.\n";
            return NULL;
        }

        return SDL_CreateTextureFromSurface( _render, aux );

    }

};
