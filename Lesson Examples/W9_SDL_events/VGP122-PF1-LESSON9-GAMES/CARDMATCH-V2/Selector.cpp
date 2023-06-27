#include "Selector.h"

Selector::Selector(std::string goID, std::string filename, int x, int y, int r, int c) : Sprite(goID, filename, x, y, r, c)
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