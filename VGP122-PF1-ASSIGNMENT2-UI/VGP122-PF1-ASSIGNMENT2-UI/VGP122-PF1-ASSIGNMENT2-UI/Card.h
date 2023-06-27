#pragma once

#include "Global.h"

#include "Game.h"
#include "Sprite.h"
#include <cstdlib>
#include <ctime>

class Card : public Sprite
{
public:
    Card(std::string f, int x, int y, int w, int h, int rows, int cols, int offsetx, int offsety, int face, int suit);
    ~Card();

    int getCurrentFrame(int frame);
    int getFace() const;
    int getSuit() const;

private:
    int face;
    int suit;
    //int currentFrame;
};
