#pragma once

#include "SDL.h"

class Renderer
{
public:
    ~Renderer();

    static Renderer* getInstance();
    static void removeInstance();

    static SDL_Renderer* getRenderer();

private:
    Renderer();
    
    static SDL_Renderer* renderer;
    static Renderer* instance;
};