#include "GAMEZONE.H"


#include <cmath>

SDL_Texture * GAME_ZONE :: RenderObject ( SDL_Renderer * _render ) {

    ObiectHolder.push( { (SDL_Rect){ 0, 0, _board.GetWidth(), _board.GetHight() }, &_board } );

    for ( int i = 0; i < _piese.size(); ++i ) {
        ObiectHolder.push( { (SDL_Rect){ _piese[ i ].GetPositionX(), _piese[ i ].GetPositionY(),
                               _piese[ i ].GetWh(), _piese[ i ].GetWh() }, &_piese[ i ] } );
    }

    GAME_MANAGER :: RenderAll( _render );

    int i, j;
    for ( i =  0; i <  _board.GetDim(); ++i ) {
        for ( j = 0; j < _board.GetDim(); ++j ) {
            SDL_Rect aux;
            aux = (SDL_Rect) { i * TileSize(), j * TileSize(), TileSize(), TileSize() };
            SDL_SetRenderDrawColor( _render, 125, 125, 125, 0);
            SDL_RenderDrawRect( _render, &aux );
        }
    }

    return NULL;

}

bool GAME_ZONE :: AddPiesa( int x, int y, int wh, const char *str ) {

    x = ( x  ) / TileSize() * TileSize();
    y = ( y  ) / TileSize() * TileSize();

    if ( !(0 <= x && x <= _board.GetHight()) ) return 0;
    if ( !(0 <= y && y <= _board.GetWidth()) ) return 0;


    static int numar_piese = 1;
    int i, j, n, xx, yy, xxx, yyy;
    int a, b, aa, bb;
    int ok = 1;

    n = _piese.size();

    a = x;
    b = y;
    aa = a + wh;
    bb = b + wh;

    for ( i = 0; i < n; ++i ) {
        xx = _piese[ i ].GetPositionX();
        xxx = xx + _piese[ i ].GetWh();

        yy = _piese[ i ].GetPositionY();
        yyy = yy + _piese[ i ].GetWh();

        if ( a > xxx || bb < yy || aa < xx || yyy  < b ) continue ;

        return 0;
    }

    PIESA aux( a, b, wh, str );
    int dim = sqrt(_board.GetHight() * _board.GetWidth() / ( _board.GetDim() * _board.GetDim() ));
    _piese.push_back( aux );

    Board[ a / dim ][ b / dim ] = 1 + (numar_piese++) % 2;

    return 1;

}
bool GAME_ZONE :: Win() {

    int dim = sqrt(_board.GetHight() * _board.GetWidth() / ( _board.GetDim() * _board.GetDim() ));

    const int x_a[] = {0,0,  1,-1,  -1,1,  -1,1 };
    const int y_a[] = {-1,1,  0,0,   1,-1,  -1,1 };
    int t, i, j, k, x, y, xx, yy;

    for ( t = 0; t < _piese.size(); ++t ) {
        x = _piese[ t ].GetPositionX() / dim ;
        y = _piese[ t ].GetPositionY() / dim ;
        for ( i = 0; i < 8; i += 2 ) {
            xx = x ;
            yy = y ;
            for ( j = 1; j <= 5; ++j ) {
                xx = xx + x_a[ i ];
                yy = yy + y_a[ i ];
                if ( !( 0 <= xx && xx < _board.GetDim() ) || Board[ x ][ y ] != Board[ xx ][ yy ] ) break;
            }
            xx = x ;
            yy = y ;
            for ( k = 1; k <= 5; ++k ) {
                xx = xx + x_a[ i + 1 ];
                yy = yy + y_a[ i + 1 ];
                if ( !( 0 <= xx && xx <_board.GetDim() ) || Board[ x ][ y ] != Board[ xx ][ yy ] ) break;
            }
            if ( ( j + k ) <= 5 ) {
                continue ;
            } else {
                cout << "Castigator.\n" << x << " " << y << endl;
                return true;
            }

        }
    }

    return false;

}

