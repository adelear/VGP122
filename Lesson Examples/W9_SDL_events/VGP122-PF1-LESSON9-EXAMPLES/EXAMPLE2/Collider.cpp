#include "Collider.h"

Collider::Collider(int x, int y, int w, int h) : position(x, y), w(w), h(h)
{ }

SDL_Rect Collider::getCollider()
{
	SDL_Rect rect{ position.x, position.y, w, h };
	return rect;
}

bool Collider::checkCollision(Collider& b)
{
	int leftA = position.x;
	int leftB = b.position.x;
	int rightA = position.x + w;
	int rightB = b.position.x + b.w;
	int topA = position.y;
	int topB = b.position.y;
	int bottomA = position.y + h;
	int bottomB = b.position.y + b.h;

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