#pragma once

#include "SDL.h"

#include "Vector2D.h"

class Collider
{
public:
	Collider(int, int, int, int);
	~Collider() = default;

	SDL_Rect getCollider();

	bool checkCollision(Collider&);

	Vector2D position;
	int w;
	int h;
};