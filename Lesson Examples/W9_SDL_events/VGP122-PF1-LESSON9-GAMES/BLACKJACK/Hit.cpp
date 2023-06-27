#include "Hit.h"

Hit::Hit(std::string filename, int x, int y, int w, int h, int r, int c) : Button(filename, x, y, w, h, r, c)
{
	setCurrentFrame(HIT);
}

void Hit::update()
{
	Button::update();
}

void Hit::render()
{
	Button::render();
}

void Hit::onPress()
{
	
}

void Hit::onRelease()
{
	
}

bool Hit::isPressed()
{
	return Button::isPressed();
}