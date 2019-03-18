#pragma once

#include <SDL.h>
#include <iostream>

class WINDOW {

public :
    WINDOW ( int width, int hight );

    int GetHight();
    int GetWidth();

    bool LoadTexture ( SDL_Texture *texture, int x, int y, int w, int h );

protected :
    SDL_Renderer *_render;
    SDL_Window *_window;

};
