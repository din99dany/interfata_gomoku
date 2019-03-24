#pragma once

#include <cmath>>
#include <vector>
#include <SDL.h>
#include <iostream>

#include "GAMEMANAGER.h"
#include "BOARD.h"
#include "PIESA.h"

class GAME_ZONE : GAME_MANAGER, public RENDER {

    BOARD _board;
    vector < PIESA > _piese;
    vector < vector <int> >Board;


public :

    void Reset() {
        _piese.clear();
        for ( int i = 0; i < Board.size(); ++i ) {
            for ( int j = 0; j < Board.size(); ++j ) {
                Board[ i ][ j ] = 0;
            }
        }
    }

    SDL_Texture * RenderObject ( SDL_Renderer * render );
    GAME_ZONE ( int wZone, int hZone, int dim, const char * boardPath ) :
        _board( wZone, hZone, dim, boardPath )
    {

        vector < int > aux;
        for ( int  i = 0; i < _board.GetDim(); ++i ) {
            aux.clear();
            for ( int j = 0; j < _board.GetDim(); ++j ) aux.push_back( 0 );
            Board.push_back( aux );
        }

    }

    int GetHight() { return _board.GetHight(); }
    int GetWidth() { return _board.GetWidth(); }
    int TileSize() { return sqrt(_board.GetHight() * _board.GetWidth() / ( _board.GetDim() * _board.GetDim() ) ); }

    bool Win();
    bool AddPiesa( int x, int y, int wh, const char *str );


};
