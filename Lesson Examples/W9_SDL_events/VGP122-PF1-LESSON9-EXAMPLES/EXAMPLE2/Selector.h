#pragma once

#include <string>

#include "Global.h"
#include "Game.h"
#include "Sprite.h"

class Selector : public Sprite
{
public:
	Selector(std::string, std::string, int, int, int, int, int, int);

	void update();
	void render();

private:

};