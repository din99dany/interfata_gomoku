#pragma once

#include <SDL.h>

class RENDER {

public :
    virtual SDL_Texture* RenderObject( SDL_Renderer * _render )  = 0;

};
