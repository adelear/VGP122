#pragma once

#include <string>

#include "Global.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Vector2D.h"

class Character : public GameObject
{
public:
	Character(std::string, std::string, float x, float y, int w, int h, int r, int c);
	Character(const Character&);

	void update();
	void render();
	Character* clone();

	void play(std::string animationID, int fps, bool r, bool rev, bool flip);

	void leftPress();
	void rightPress();
	void upPress();
	void downPress();

	void leftRelease();
	void rightRelease();
	void upRelease();
	void downRelease();

	void leftHit();
	void rightHit();
	void groundHit();
	
	void idle();
	void move();
	void stop();

	bool isMoving();
	bool isJumping();

	bool checkCollision(Collider& b);

private:
	Sprite* graphic;

	bool left;
	bool right;
	bool up;
	bool down;
	bool jump;
	bool moving;

	bool isLeftHit;
	bool isRightHit;
	bool isGroundHit;
	bool isLeft;

	float iniJumpPosition;

	static const std::vector<int> idleAnimation;
	static const std::vector<int> walkAnimation;
	static const std::vector<int> jumpAnimation;

	static const float ACCELERATION;
	static const float MAXVELOCITY;
	static const float MAXJUMPVELOCITY;
	static const float GRAVITY;
};