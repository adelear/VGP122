#pragma once

#include <string>

#include "Object.h"

class GameObject : public Object
{
public:
	virtual ~GameObject() = default;

	virtual void update() = 0;
	virtual void render() = 0;

	std::string getGameObjectID() { return gameObjectID; }
	std::string getResourceID() { return resourceID; }

protected:
	std::string resourceID;
	std::string gameObjectID;
};