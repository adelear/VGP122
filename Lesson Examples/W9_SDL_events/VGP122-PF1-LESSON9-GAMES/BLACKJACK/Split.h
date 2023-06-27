#pragma once

#include "Button.h"

class Split : public Button
{
public:
	Split(std::string, int, int, int, int, int, int);

	void update();
	void render();

	void onPress();
	void onRelease();

	bool isPressed();

private:


};