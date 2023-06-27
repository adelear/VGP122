#include "DDown.h"

DDown::DDown(std::string filename, int x, int y, int w, int h, int r, int c) : Button(filename, x, y, w, h, r, c)
{
	setCurrentFrame(DDOWN);
}

void DDown::update()
{
	Button::update();
}

void DDown::render()
{
	Button::render();
}

void DDown::onPress()
{
	
}

void DDown::onRelease()
{
	
}

bool DDown::isPressed()
{
	return Button::isPressed();
}