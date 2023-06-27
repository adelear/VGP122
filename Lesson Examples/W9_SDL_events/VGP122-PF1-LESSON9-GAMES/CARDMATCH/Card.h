#pragma once

#include "Game.h"
#include "Sprite.h"

class Card : public Sprite
{
public:
	Card(std::string, int, int, int, int, int, int, int);
	
	void setFace(int);
	int getFace();

private:
	int face;
};