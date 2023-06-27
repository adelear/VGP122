#pragma once

#include "Button.h"

class Pass : public Button
{
public:
	Pass(std::string, int, int, int, int, int, int);

	void update();
	void render();

	void onPress();
	void onRelease();

	bool isPressed();

private:


};