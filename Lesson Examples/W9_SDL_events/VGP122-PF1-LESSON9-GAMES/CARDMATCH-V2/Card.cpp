#include "Card.h"

Card::Card(std::string cardID, std::string filename, int x, int y, int r, int c, int f) : Sprite(cardID, filename, x, y, r, c), face(f)
{ 
	setCurrentFrame(0);

	turned = false;

	addAnimation("chest", chestAnimation);
	addAnimation("coin", coinAnimation);
	addAnimation("flower", flowerAnimation);
	addAnimation("mushroom", mushroomAnimation);
	addAnimation("star", starAnimation);
}

void Card::setFace(int f)
{
	face = f;
}

int Card::getFace()
{
	return face;
}

void Card::setTurned(bool t)
{
	turned = t;
}

bool Card::isTurned()
{
	return turned;
}

std::string Card::getFaceName()
{
	std::string faceName; 

	switch (face)
	{
		case CHEST:
			faceName = "chest";
			break;
		case COIN:
			faceName = "coin";
			break;
		case FLOWER:
			faceName = "flower";
			break;
		case MUSHROOM:
			faceName = "mushroom";
			break;
		case STAR:
			faceName = "star";
			break;
	}

	return faceName;
}

const std::vector<int> Card::chestAnimation = { 0, 1, 2, 3, 4, 5, 6 };
const std::vector<int> Card::coinAnimation = { 0, 1, 2, 3, 4, 5, 7 };
const std::vector<int> Card::flowerAnimation = { 0, 1, 2, 3, 4, 5, 8 };
const std::vector<int> Card::mushroomAnimation = { 0, 1, 2, 3, 4, 5, 9 };
const std::vector<int> Card::starAnimation = { 0, 1, 2, 3, 4, 5, 10 };