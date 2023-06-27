#include "Card.h"

Card::Card(std::string cardID, std::string filename, int x, int y, int w, int h, int r, int c, int f) : GameObject()
{ 
	graphic = Game::getInstance()->createSprite(cardID, filename, x, y, w, h, r, c);

	face = f;

	initialize();
}

Card::Card(const Card& other)
{
	std::string goID = other.gameObjectID;
	std::string filename = other.graphic->getFilename();
	float x = other.graphic->getPosition().x;
	float y = other.graphic->getPosition().y;
	int w = other.graphic->getWidth();
	int h = other.graphic->getHeight();
	int rows = other.graphic->properties->graphicsComponent->rows;
	int cols = other.graphic->properties->graphicsComponent->cols;

	graphic = Game::getInstance()->createSprite(goID, filename, x, y, w, h, rows, cols);

	face = other.face;

	initialize();
}

Card::~Card()
{
	delete graphic;
}

void Card::initialize()
{
	graphic->setCurrentFrame(BLANK);

	turned = false;

	graphic->addAnimation("chest", chestAnimation);
	graphic->addAnimation("coin", coinAnimation);
	graphic->addAnimation("flower", flowerAnimation);
	graphic->addAnimation("mushroom", mushroomAnimation);
	graphic->addAnimation("star", starAnimation);
}

void Card::update()
{
	graphic->update();
}

void Card::render()
{
	graphic->render();
}

Card* Card::clone()
{
	return new Card(*this);
}

void Card::play(std::string animation, int fps, bool repeat, bool reverse)
{
	graphic->play(animation, fps, repeat, reverse);
}

void Card::setCurrentFrame(int frame)
{
	graphic->setCurrentFrame(frame);
}

void Card::setPosition(Vector2D v)
{
	graphic->setPosition(v);
}

Vector2D Card::getPosition()
{
	return graphic->getPosition();
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