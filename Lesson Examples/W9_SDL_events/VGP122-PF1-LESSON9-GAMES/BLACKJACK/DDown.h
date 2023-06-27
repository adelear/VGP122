#pragma once

#include "Button.h"

class DDown : public Button
{
public:
	DDown(std::string, int, int, int, int, int, int);

	void update();
	void render();

	void onPress();
	void onRelease();

	bool isPressed();

private:


};