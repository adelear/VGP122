#include "Selector.h"

Selector::Selector(std::string filename, int x, int y, int w, int h, int r, int c) : Sprite(Game::getRenderer(), filename, x, y, w, h, r, c)
{ 
	setCurrentFrame(11);
}

void Selector::update()
{
	Sprite::update();
}

void Selector::render()
{
	Sprite::render();
}