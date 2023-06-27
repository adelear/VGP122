#pragma once

#include <string>
#include <vector>

#include "Global.h"

#include "Game.h"
#include "Sprite.h"

class Card : public Sprite
{
public:
	Card(std::string, std::string, int, int, int, int, int);
	
	void setFace(int);
	int getFace();

	bool isTurned();
	void setTurned(bool);
	
	std::string getFaceName();

private:
	int face;
	bool turned;

	static const std::vector<int> chestAnimation;
	static const std::vector<int> coinAnimation;
	static const std::vector<int> flowerAnimation;
	static const std::vector<int> mushroomAnimation;
	static const std::vector<int> starAnimation;
};