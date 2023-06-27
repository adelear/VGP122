#pragma once

#include "Global.h"

#include "Game.h"
#include "Sprite.h"

class Button : public Sprite
{
public:
	Button(std::string, int, int, int, int, int, int);

	void update();
	void render();

	void onPress();
	void onRelease();

	bool isPressed();

protected:
	bool pressed;
};