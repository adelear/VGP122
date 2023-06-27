#include "Collider.h"

Collider::Collider(Vector2D v, float w, float h) : position(v), w(w), h(h)
{ }

Collider::Collider(float x, float y, float w, float h) : position(x, y), w(w), h(h)
{ }

Vector2D Collider::getCollider()
{
	Vector2D rect = { position.x, position.y };
	return rect;
}

bool Collider::checkCollision(Collider& b)
{
	float leftA = position.x;
	float leftB = b.position.x;
	float rightA = position.x + w;
	float rightB = b.position.x + b.w;
	float topA = position.y;
	float topB = b.position.y;
	float bottomA = position.y + h;
	float bottomB = b.position.y + b.h;

	if (bottomA <= topB)
		return false;

	if (topA >= bottomB)
		return false;

	if (rightA <= leftB)
		return false;

	if (leftA >= rightB)
		return false;

	return true;
}