#include "GAME.h"
#include <cmath>

GAME :: GAME ( int wBoard, int hBoard, int hBuffer, const char *BoardPath, int BoardSize,
               const char *BlackPath, const char *WhitePath, const char * BufferPath ) :
WINDOW( wBoard, hBoard + hBuffer ),
_gameZone( wBoard, hBoard, BoardSize, BoardPath ),
_menu( wBoard, hBuffer, BufferPath )
{

    background = SDL_CreateTexture( _render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, wBoard, hBoard + hBuffer );
    SDL_SetRenderTarget(_render, background);

    strcpy( _BlackPath, BlackPath );
    strcpy( _WhitePath, WhitePath );

}

void GAME :: RenderEverything () {

        SDL_SetRenderTarget( _render, background );
        SDL_RenderClear( _render );

        ObiectHolder.push( { (SDL_Rect){ 0, 0, _gameZone.GetWidth(), _gameZone.GetHight() }, &_gameZone } );
        ObiectHolder.push( { (SDL_Rect){ 0, _gameZone.GetHight(), _menu.GetWidth() / 2, _menu.GetHight() }, &_menu } );



        RenderAll( _render );


        SDL_SetRenderTarget(_render, NULL);
        SDL_RenderPresent(_render);


        SDL_RenderClear(_render);
        SDL_RenderCopy(_render, background, NULL, NULL);
        SDL_RenderPresent( _render);

}

void GAME :: RunGame() {

    int ok = 1, okk = 1;;
    int seter;
    int TurnCounter = 0;
    int x, y, xx, yy;
    SDL_Event event;

    RenderEverything();

    while ( ok ) {
        if ( SDL_PollEvent( &event ) ) {

            switch ( event.type ) {

                case SDL_QUIT :
                    ok = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN :
                    SDL_GetMouseState( &x, &y );
                    cout << x << " " << y << endl;
                    if ( okk != 0 && ( 0 <= y && y <= _gameZone.GetHight() ) && ( 0 <= x && x <= _gameZone.GetWidth() ) ) {
                        TurnCounter += ( TurnCounter % 2 ) ? (_gameZone.AddPiesa( x, y, _gameZone.TileSize() - 3, _BlackPath )) : ( _gameZone.AddPiesa( x, y,  _gameZone.TileSize() - 3, _WhitePath ) );
                        okk = !_gameZone.Win();
                    } else if ( ( _gameZone.GetHight() <= y && y <= _menu.GetHight() + _gameZone.GetHight() ) && ( 0 <= x && x <= _menu.GetWidth() ) ) {
                        _gameZone.Reset();
                        TurnCounter = 0;
                        okk = 1;
                        cout << "Reset.\n";
                    }
                    RenderEverything( );
                    break;
                default :
                    break;

            }

        }
    }



}

