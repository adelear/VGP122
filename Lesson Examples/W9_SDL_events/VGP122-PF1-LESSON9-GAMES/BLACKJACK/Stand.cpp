#include "Stand.h"

Stand::Stand(std::string filename, int x, int y, int w, int h, int r, int c) : Button(filename, x, y, w, h, r, c)
{
	setCurrentFrame(STAND);
}

void Stand::update()
{
	Button::update();
}

void Stand::render()
{
	Button::render();
}

void Stand::onPress()
{
	
}

void Stand::onRelease()
{
	
}

bool Stand::isPressed()
{
	return Button::isPressed();
}