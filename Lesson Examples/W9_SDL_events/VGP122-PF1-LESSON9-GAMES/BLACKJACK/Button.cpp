#include "Button.h"

Button::Button(std::string filename, int x, int y, int w, int h, int r, int c) : Sprite(Game::getRenderer(), filename, x, y, w, h, r, c)
{
	pressed = false;

	setCurrentFrame(PLAY);
}

void Button::update()
{
	Sprite::update();
}

void Button::render()
{
	Sprite::render();
}

void Button::onPress()
{
	pressed = true;
}

void Button::onRelease()
{
	pressed = false;
}

bool Button::isPressed()
{
	return pressed;
}