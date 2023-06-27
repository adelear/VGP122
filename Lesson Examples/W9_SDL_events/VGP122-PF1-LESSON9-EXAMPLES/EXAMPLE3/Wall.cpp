#include "Wall.h"

Wall::Wall(std::string goID)
{ 
	gameObjectID = goID;

	PhysicsComponent* pc = new PhysicsComponent();

	properties = new GameObjectProperties(nullptr, nullptr, nullptr, pc);

	properties->physicsComponent = pc;
	pc->collider = Collider(0.0f, 0.0f, 0.0f, 0.0f);
}

Wall::Wall(std::string goID, float x, float y, float w, float h)
{
	gameObjectID = goID;

	PhysicsComponent* pc = new PhysicsComponent();

	properties = new GameObjectProperties(nullptr, nullptr, nullptr, pc);

	properties->physicsComponent = pc;
	pc->collider = Collider(x, y, w, h);
}

Wall::Wall(const Wall& other)
{
	gameObjectID = other.gameObjectID;

	PhysicsComponent* pc = new PhysicsComponent();

	properties = new GameObjectProperties(nullptr, nullptr, nullptr, pc);
	properties->physicsComponent = pc;

	Vector2D v = { other.properties->physicsComponent->collider.position.x, other.properties->physicsComponent->collider.position.y };
	int w = other.properties->physicsComponent->collider.w;
	int h = other.properties->physicsComponent->collider.h;
	
	pc->collider = Collider(v, w, h);
}

void Wall::update()
{

}

void Wall::render()
{

}

Collider Wall::getCollider()
{
	return properties->physicsComponent->collider;
}

Wall* Wall::clone()
{
	return new Wall(*this);
}