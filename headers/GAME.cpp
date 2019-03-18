#include "GAME.h"
#include <cmath>

GAME :: GAME ( int wBoard, int hBoard, int hBuffer, const char *BoardPath, int BoardSize,
               const char *BlackPath, const char *WhitePath, const char * BufferPath
             ) : WINDOW( wBoard, hBoard + hBuffer ) {

    background = SDL_CreateTexture( _render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, wBoard, hBoard + hBuffer );
    SDL_SetRenderTarget(_render, background);

    _wBoard = wBoard;
    _hBoard =  hBoard;
    _BoardSize = BoardSize;
    _hBuffer = hBuffer;

    strcpy( _BufferPath, BufferPath );
    strcpy( _BoardPath, BoardPath );
    strcpy( _BlackPath, BlackPath );
    strcpy( _WhitePath, WhitePath );

}

void GAME :: LoadBuffer( ) {

    SDL_Surface *buffer = SDL_LoadBMP( _BufferPath );
    SDL_Texture *background = SDL_CreateTextureFromSurface( _render, buffer);

    SDL_Rect aux;
    aux.x = 0;
    aux.y = _wBoard;

    aux.h = _hBuffer;
    aux.w = _wBoard;

    SDL_RenderCopy( _render, background, NULL, &aux );

}

void GAME :: RenderEverything () {

        SDL_SetRenderTarget( _render, background );
        SDL_RenderClear( _render );

        LoadBuffer();
        LoadBoard( _BoardPath );
        LoadPiese();


        SDL_SetRenderTarget(_render, NULL);
        SDL_RenderPresent(_render);


        SDL_RenderClear(_render);
        SDL_RenderCopy(_render, background, NULL, NULL);
        SDL_RenderPresent( _render);

}

void GAME :: RunGame() {

    int ok = 1;
    int seter;
    int TurnCounter = 0;
    int x, y, xx, yy;
    SDL_Event event;

    while ( ok ) {

        if ( SDL_PollEvent( &event ) ) {

            if ( event.type == SDL_MOUSEBUTTONDOWN ) {
                seter = 0;

                if ( event.button.clicks >= 2  ) {
                    SDL_GetMouseState( &x, &y );

                    int dim = sqrt(_wBoard * _hBoard / ( _BoardSize * _BoardSize ));

                    x = ( x + dim / 2) / dim * dim;
                    y = ( y + dim / 2 ) / dim * dim;

                    if ( TurnCounter % 2 == 1 ) seter = AddPiesa( x, y, dim - 5 , _BlackPath );
                    else seter = AddPiesa( x, y, dim - 5, _WhitePath );

                    TurnCounter += seter;
                    RenderEverything();
                }

            } else if ( event.type == SDL_QUIT ) {
                ok = 0;
            }

        }
    }



}

void GAME :: PresentGame() {
    SDL_RenderPresent( _render );
}

bool GAME :: AddPiesa( int x, int y, int wh, const char *str ) {

    int i, j, n, xx, yy, xxx, yyy;
    int a, b, aa, bb;
    int ok = 1;

    n = _piese.size();

    a = x - wh / 2;
    b = y - wh / 2;
    aa = a + wh;
    bb = b + wh;

    for ( i = 0; i < n; ++i ) {
        xx = _piese[ i ].GetPositionX();
        xxx = xx + _piese[ i ].GetWh();

        yy = _piese[ i ].GetPositionY();
        yyy = yy + _piese[ i ].GetWh();

        cout << a << " " << aa << " " << b << " " << bb << endl;
        cout << xx << " " << yy << " " << xxx << " " << yyy << endl << endl;

        if ( a > xxx || bb < yy || aa < xx || yyy  < b ) continue ;

        return 0;
    }

    PIESA aux( a, b, wh, str );
    _piese.push_back( aux );

    return 1;

}

void GAME :: LoadBoard( const char *str ) {

    SDL_Surface *aux = SDL_LoadBMP( str );

    if( aux == NULL ) {
        cout << "Failed to load board surface.\n";
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface( _render, aux );

    if ( texture == NULL  ) {
        cout << "Failed to load board.\n";
    } else {
        WINDOW::LoadTexture( texture, 0, 0, 800, 800 );
    }

    SDL_FreeSurface( aux );
    SDL_DestroyTexture( texture );

}

void  GAME :: LoadPiese( ) {

    SDL_Surface *piesaNeagra = NULL;
    SDL_Surface *piesaALBA = NULL ;
    SDL_Surface *pieseIntermediara;

    int i, n;
    n =_piese.size();

    if ( n >= 1 ) piesaALBA = _piese[ 0 ].GetSurface();
    if ( n >= 2 ) piesaNeagra = _piese[ 1 ].GetSurface();

    for ( i = 0; i < n; ++i ) {
        SDL_Rect aux;
        aux.x = _piese[ i ].GetPositionX();
        aux.y = _piese[ i ].GetPositionY();
        aux.w = aux.h = _piese[ i ].GetWh();

        if ( i % 2 == 0 ) pieseIntermediara = piesaALBA;
        else pieseIntermediara = piesaNeagra;

        SDL_RenderCopy( _render, SDL_CreateTextureFromSurface( _render, pieseIntermediara ) , NULL, &aux );
    }

    SDL_FreeSurface( piesaNeagra );
    SDL_FreeSurface( piesaALBA );

}
