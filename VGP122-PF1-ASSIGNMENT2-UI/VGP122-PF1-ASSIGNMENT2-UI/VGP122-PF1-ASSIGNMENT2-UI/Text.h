#pragma once

#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "Global.h"


#include "GameObject.h"
#include "Vector2D.h"
#include "ResourceManager.h"


/*
class Text : public GameObject
{
public:
    Text(SDL_Renderer*, std::string, int, int, int, double = 0.0, SDL_RendererFlip = SDL_FLIP_NONE);

    ~Text();

    virtual void update();
    virtual void render();

    SDL_Rect getRect();

    void setVisible(bool);
    void setText(std::string);
    void setFontSize(float);
    void setColor(SDL_Color);
    void setFont(std::string);
    bool isVisible();

    Vector2D position;
    int w;
    int h;

private:
    void load();

    std::string output;
    std::string filename;
    float fontSize;

    double angle;
    SDL_RendererFlip flip;
    SDL_Color color;

    bool visible;

    SDL_Renderer* renderer;
    SDL_Surface* surface;
    SDL_Texture* texture;
};

*/