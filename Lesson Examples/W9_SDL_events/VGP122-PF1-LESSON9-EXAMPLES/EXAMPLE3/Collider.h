#pragma once

#include "SDL.h"

#include "Vector2D.h"

class Collider
{
public:
	Collider(Vector2D, float, float);
	Collider(float, float, float, float);
	~Collider() = default;

	Vector2D getCollider();

	bool checkCollision(Collider&);

	Vector2D position;
	float w;
	float h;
};