#include "PIESA.h"
#include <cstring>
using namespace std;

SDL_Texture* PIESA :: RenderObject( SDL_Renderer *_render )  {
        SDL_Surface *aux = SDL_LoadBMP( SurfacePath );

        if ( aux == NULL  ) {
            cout << "Fail to load surface for piesa.\n";
            return NULL;
        }
        return SDL_CreateTextureFromSurface( _render, aux );
    }

PIESA :: PIESA ( int x, int y, int wh, const char * str ) {

    _x = x;
    _y = y;
    _wh = wh;

    strcpy( SurfacePath, str );

}

SDL_Surface * PIESA :: GetSurface() {

    SDL_Surface *aux = SDL_LoadBMP( SurfacePath );

    if ( aux == NULL ) {
        cout << "Failed to load texture piesa\n";
        return 0;
    }

    return  aux;

}

void PIESA :: ChangePosition( int x, int y ) {
    _x = x;
    _y = y;
}

int PIESA :: GetPositionX() { return _x; };
int PIESA :: GetPositionY() { return _y; };
int PIESA :: GetWh() { return _wh; }
