#include "Split.h"

Split::Split(std::string filename, int x, int y, int w, int h, int r, int c) : Button(filename, x, y, w, h, r, c)
{
	setCurrentFrame(SPLIT);
}

void Split::update()
{
	Button::update();
}

void Split::render()
{
	Button::render();
}

void Split::onPress()
{
	
}

void Split::onRelease()
{
	
}

bool Split::isPressed()
{
	return Button::isPressed();
}