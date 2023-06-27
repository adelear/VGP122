#pragma once

#include "Sprite.h"

class Cursor : public Sprite
{
public:
	Cursor(std::string, std::string, int, int, int, int, int, int);
	~Cursor() = default;

	void update();
	void render();

	void moveLeft();
	void moveRight();

	void movePlayer1();
	void movePlayer2();

private:
	bool left;
	bool right;

	bool player1;
	bool player2;

	std::string id;
};