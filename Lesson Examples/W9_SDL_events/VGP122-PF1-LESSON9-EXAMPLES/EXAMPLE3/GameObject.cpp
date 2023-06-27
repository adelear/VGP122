#include "GameObject.h"

GameObject::GameObject()
    : properties{ nullptr }
{ }

GameObject::GameObject(Renderer* r, GraphicsComponent* g, AnimationComponent* a, PhysicsComponent* p)
    : properties{ new GameObjectProperties(r, g, a, p) }
{ }

GameObject::GameObject(GameObjectProperties* gop)
    : properties(gop)
{ }

GameObject::~GameObject()
{
    if (properties != nullptr)
        delete properties;

    properties = nullptr;
}

std::string GameObject::getGameObjectID()
{
    return gameObjectID;
}

void GameObject::setGameObjectID(std::string goID)
{
    gameObjectID = goID;
}