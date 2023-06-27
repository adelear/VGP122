#pragma once

#include "Button.h"

class Hit : public Button
{
public:
	Hit(std::string, int, int, int, int, int, int);

	void update();
	void render();

	void onPress();
	void onRelease();

	bool isPressed();

private:


};