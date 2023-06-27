#include "Character.h"

Character::Character(std::string goID, std::string filename, float x, float y, int w, int h, int r, int c)
{
	graphic = Game::getInstance()->createSprite(goID, filename, x, y, w, h, r, c);

	gameObjectID = goID;

	graphic->addAnimation("idle", idleAnimation);
	graphic->addAnimation("walk", walkAnimation);
	graphic->addAnimation("jump", jumpAnimation);

	left = false;
	right = false;
	up = false;
	down = false;
	jump = false;
	moving = false;

	isLeft = false;
	isLeftHit = false;
	isRightHit = false;
	isGroundHit = false;

	iniJumpPosition = 0;

	*(graphic->velocity) = { 0, 0 };
	*(graphic->acceleration) = { 0, 0 };
	graphic->setEndTime(graphic->getCurrentTime());
}

Character::Character(const Character& other)
{
	Vector2D p = other.properties->graphicsComponent->position;
	int w = other.properties->graphicsComponent->w;
	int h = other.properties->graphicsComponent->h;
	int r = other.properties->graphicsComponent->rows;
	int c = other.properties->graphicsComponent->cols;
	std::string filename = other.properties->graphicsComponent->filename;
	
	graphic = Game::getInstance()->createSprite("", filename, p.x, p.y, w, h, r, c);

	left = false;
	right = false;
	up = false;
	down = false;
	jump = false;
	moving = false;
	
	isLeft = false;
	isLeftHit = false;
	isRightHit = false;
	isGroundHit = false;

	iniJumpPosition = 0;

	*(graphic->velocity) = { 0, 0 };
	*(graphic->acceleration) = { 0, 0 };
	graphic->setEndTime(graphic->getCurrentTime());
}

void Character::update()
{
	std::string currentAnimation = graphic->getCurrentAnimation();
	float delta = static_cast<float>(graphic->getDelta() / 1000.0f);
	graphic->setEndTime(graphic->getCurrentTime());

	//std::cout << gameObjectID << " X POSITION: " << graphic->position->x << " Y POSITION " << graphic->position->y << " FPS " << 1000 / (Game::FPS - delta) << std::endl;

	if (isLeftHit)
	{
		play("idle", 8, true, false, isLeft);
		*(graphic->acceleration) = { 0, 0 };
		*(graphic->velocity) = { 0, 0 };
		*(graphic->position) = { 0, graphic->position->y };
		idle();

		isLeftHit = false;
	}
	else if (isRightHit)
	{
		play("idle", 8, true, false, isLeft);
		*(graphic->acceleration) = { 0, 0 };
		*(graphic->velocity) = { 0, 0 };
		*(graphic->position) = { static_cast<float>(SCREEN_WIDTH) - graphic->getWidth(), graphic->position->y};
		idle();

		isRightHit = false;
	}
	else if (isGroundHit)
	{
		play("idle", 8, true, false, isLeft);
		*(graphic->acceleration) = { 0, 0 };
		*(graphic->velocity) = { 0, 0 };
		*(graphic->position) = { graphic->position->x, iniJumpPosition };
		idle();

		isGroundHit = false;
	}
	else if (left)
	{
		if (currentAnimation != "walk")
			graphic->play("walk", 10, true, false, isLeft);
		
		*(graphic->acceleration) = { ACCELERATION, 0 };
		*(graphic->velocity) -= *(graphic->acceleration) * delta;
		graphic->velocity->limit(MAXVELOCITY);
		*(graphic->position) += (*(graphic->velocity) * delta) + (*(graphic->acceleration) * delta * delta * 0.5f);
	}
	else if (right)
	{
		if (currentAnimation != "walk")
			graphic->play("walk", 10, true, false, isLeft);
		
		*(graphic->acceleration) = { ACCELERATION, 0 };
		*(graphic->velocity) += *(graphic->acceleration) * delta;
		graphic->velocity->limit(MAXVELOCITY);
		*(graphic->position) += (*(graphic->velocity) * delta) + (*(graphic->acceleration) * delta * delta * 0.5f);
	}
	else if (up)
	{
		jump = true;

		if (currentAnimation != "jump")
			graphic->play("jump", 7, true, false, isLeft);

		*(graphic->velocity) = { 0, MAXJUMPVELOCITY };

		iniJumpPosition = graphic->position->y;
	}
	else if (down)
	{

	}
	else if (jump)
	{
		*(graphic->position) += (*(graphic->velocity) * delta) + (*(graphic->acceleration) * delta * delta * 0.5f);
		*(graphic->acceleration) = { 0, GRAVITY };
		*(graphic->velocity) += *(graphic->acceleration) * delta;
	}
	else
	{
		idle();
		
		*(graphic->acceleration) = { 0, 0 };
		*(graphic->velocity) = { 0, 0 };
		
		if (currentAnimation != "idle")
		{
			play("idle", 8, true, false, isLeft);
		}
	}

	graphic->update();
}

void Character::render()
{
	graphic->render();
}

Character* Character::clone()
{
	return new Character(*this);
}

void Character::play(std::string animationID, int fps, bool r, bool rev, bool flip)
{
	graphic->play(animationID, fps, r, rev, flip);
}

void Character::leftHit()
{
	isLeftHit = true;
}

void Character::rightHit()
{
	isRightHit = true;
}

void Character::groundHit()
{
	isGroundHit = true;
}

void Character::idle()
{
	left = false;
	right = false;
	up = false;
	down = false;
	moving = false;
	jump = false;
}

void Character::leftPress()
{
	left = true;

	isLeft = true;
}

void Character::rightPress()
{
	right = true;

	isLeft = false;
}

void Character::upPress()
{
	up = true;
}

void Character::downPress()
{
	down = true;
}

void Character::leftRelease()
{
	left = false;
}

void Character::rightRelease()
{
	right = false;
}

void Character::upRelease()
{
	up = false;
}

void Character::downRelease()
{
	down = false;
}

bool Character::isJumping()
{
	return jump;
}

bool Character::isMoving()
{
	return moving;
}

void Character::move()
{
	moving = true;
}

void Character::stop()
{
	moving = false;
	jump = false;
}

bool Character::checkCollision(Collider& b)
{
	return graphic->checkCollision(b);
}

const std::vector<int> Character::idleAnimation = { 0, 1, 2, 3 };
const std::vector<int> Character::walkAnimation = { 4, 5, 6, 7, 8 };
const std::vector<int> Character::jumpAnimation = { 9, 10, 11, 12, 13, 14, 15 };

const float Character::GRAVITY = 250.0f;
const float Character::ACCELERATION = 200.0f;
const float Character::MAXVELOCITY = 100.0f;
const float Character::MAXJUMPVELOCITY = -110.0f;