#pragma once

#include <SDL.h>
#include <string>
#include <iostream>
#include <cstring>>
using namespace std;

class PIESA {
public:

    PIESA ( const PIESA &ob ) {
        _x = ob._x;
        _y = ob._y;
        _wh = ob._wh;
        strcpy( SurfacePath, ob.SurfacePath );
    }

    ~PIESA(){

    }

    PIESA( int x, int y, int wh, const char * str );

    SDL_Surface * GetSurface();

    int GetPositionX();
    int GetPositionY();
    int GetWh();

    void ChangePosition( int x, int y );


private:

    int _x;
    int _y;
    int _wh;
    char SurfacePath[ 100 ];

};
