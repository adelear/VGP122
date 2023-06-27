#include "Cursor.h"

Cursor::Cursor(std::string id, SDL_Renderer* r, std::string filename, int x, int y, int w, int h, int rows, int cols) : Sprite(r, filename, x, y, w, h, rows, cols), id(id)
{
	left = false;
	right = false;

	if (id == "player1")
	{
		player1 = true;
		player2 = false;
	}
	else if (id == "player2")
	{
		player1 = false;
		player2 = true;
	}
	else
		std::cout << "Enter id player1 or player2" << std::endl;
}

void Cursor::update()
{
	Sprite::update();

	if(player1)
		movePlayer1();
	else if(player2)
		movePlayer2();
}

void Cursor::render()
{
	Sprite::render();
}

void Cursor::moveLeft()
{
	left = true;
	right = false;
}

void Cursor::moveRight()
{
	left = false;
	right = true;
}

void Cursor::movePlayer1()
{
	if (player1 && left)
	{
		if (position.x <= 191 && position.y == 216)
			gotoPos(359, 344);
		else if (position.x <= 149 && position.y == 280)
			gotoPos(317, 216);
		else if (position.x <= 149 && position.y == 344)
			gotoPos(359, 280);
		else
			gotoPos(position.x - 42, position.y);

		left = false;
	}
	else if (player1 && right)
	{
		if (position.x >= 317 && position.y == 216)
			gotoPos(149, 280);
		else if (position.x >= 359 && position.y == 280)
			gotoPos(149, 344);
		else if (position.x >= 359 && position.y == 344)
			gotoPos(191, 216);
		else
			gotoPos(position.x + 42, position.y);

		right = false;
	}
}

void Cursor::movePlayer2()
{
	if (player2 && left)
	{
		if (position.x <= 191 && position.y == 223)
			gotoPos(359, 351);
		else if (position.x <= 149 && position.y == 287)
			gotoPos(317, 223);
		else if (position.x <= 149 && position.y == 351)
			gotoPos(359, 287);
		else
			gotoPos(position.x - 42, position.y);

		left = false;
	}
	else if (player2 && right)
	{
		if (position.x >= 317 && position.y == 223)
			gotoPos(149, 287);
		else if (position.x >= 359 && position.y == 287)
			gotoPos(149, 351);
		else if (position.x >= 359 && position.y == 351)
			gotoPos(191, 223);
		else
			gotoPos(position.x + 42, position.y);

		right = false;
	}
}