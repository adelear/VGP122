#include "Card.h"

Card::Card(std::string filename, int x, int y, int w, int h, int r, int c, int f) : Sprite(Game::getRenderer(), filename, x, y, w, h, r, c), face(f)
{ 
	setCurrentFrame(0);
}

void Card::setFace(int f)
{
	face = f;
}

int Card::getFace()
{
	return face;
}