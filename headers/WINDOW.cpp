#include  "WINDOW.H"

using namespace std;

bool  WINDOW :: LoadTexture ( SDL_Texture *texture, int x, int y, int w, int h ) {

    SDL_Rect aux;
    aux.h = h;
    aux.w = w;
    aux.x = x;
    aux.y = y;

    SDL_RenderCopy( _render, texture, NULL, &aux );

}


int WINDOW :: GetHight() {
        int x;
        SDL_GetWindowSize( _window, NULL, &x );
        return x;
}

int WINDOW :: GetWidth() {
        int x;
        SDL_GetWindowSize( _window, &x, NULL );
        return x;
}
WINDOW :: WINDOW ( int width, int hight ) {
        _window = SDL_CreateWindow( "GONOKU", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, hight, SDL_WINDOW_SHOWN );

        if ( _window == NULL ) {
            cout << "Failed to load window.\n";
        }

        _render = SDL_CreateRenderer( _window, 0, SDL_RENDERER_ACCELERATED );
        if ( _render == NULL ) {
            cout << "Failed to create render.\n";
        }

}

