#include "Pass.h"

Pass::Pass(std::string filename, int x, int y, int w, int h, int r, int c) : Button(filename, x, y, w, h, r, c)
{
	setCurrentFrame(PASS);
}

void Pass::update()
{
	Button::update();
}

void Pass::render()
{
	Button::render();
}

void Pass::onPress()
{
	
}

void Pass::onRelease()
{
	
}

bool Pass::isPressed()
{
	return Button::isPressed();
}