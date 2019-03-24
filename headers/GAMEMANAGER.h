#pragma once

#include "RENDER.h"
#include "CLICK_ACTION.h"

#include <queue>
#include <SDL.h>

using namespace std;

class GAME_MANAGER {

protected :
    queue < pair < SDL_Rect, RENDER* > > ObiectHolder;
    queue < pair < SDL_Rect, CLICK_ACTION* > > ActionHolder;
public :

    void TriggerAll ( SDL_Event event ) {

        int n, i;
        CLICK_ACTION * aux;

        while ( !ActionHolder.empty() ) {
            aux = ActionHolder.front().second;
            aux -> ClickAction( event );
            ActionHolder.pop();
        }

    }

    void PushRender( SDL_Rect pos, RENDER * ObjPointer ) {
        ObiectHolder.push( {pos, ObjPointer} );
    }

    SDL_Texture  * RenderAll ( SDL_Renderer * _render ) {

        int n, i;
        RENDER *obj;
        SDL_Rect aux;

        while ( !ObiectHolder.empty() ) {
            obj = ObiectHolder.front().second;
            aux = ObiectHolder.front().first;
            ObiectHolder.pop();

            SDL_RenderCopy( _render, obj -> RenderObject( _render ), NULL, &aux );

        }

    }

};
