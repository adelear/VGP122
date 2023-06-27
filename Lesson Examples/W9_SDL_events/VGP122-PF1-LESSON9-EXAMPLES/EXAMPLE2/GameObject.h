#pragma once

#include <string>

#include "Object.h"
#include "Vector2D.h"
#include "GraphicsComponent.h"
#include "AnimationComponent.h"
#include "PhysicsComponent.h"
#include "GameObjectProperties.h"

class GraphicsComponent;
class AnimationComponent;
class PhysicsComponent;
class GameObjectProperties;

class GameObject : public Object
{
public:
    GameObject();
    GameObject(Renderer* r, GraphicsComponent* g, AnimationComponent* a, PhysicsComponent* p);
    GameObject(GameObjectProperties* gop);

    virtual ~GameObject();

    virtual void update() = 0;
    virtual void render() = 0;

    virtual GameObject* clone() = 0;

    std::string getGameObjectID();
    void setGameObjectID(std::string goID);

    GameObjectProperties* properties{ nullptr };

protected:
    std::string gameObjectID;
};