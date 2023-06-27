#pragma once

#include <string>

#include "GameObject.h"
#include "GameObjectProperties.h"
#include "PhysicsComponent.h"

class Wall : public GameObject
{
public:
	Wall(std::string);
	Wall(std::string, float, float, float, float);
	Wall(const Wall&);

	void update();
	void render();

	Wall* clone();

	Collider getCollider();
};