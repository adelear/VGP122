#pragma once

#include "Object.h"
#include "Renderer.h"
#include "GraphicsComponent.h"
#include "AnimationComponent.h"
#include "PhysicsComponent.h"

class GraphicsComponent;
class AnimationComponent;
class PhysicsComponent;

class GameObjectProperties : public Object
{
public:
    GameObjectProperties();
    GameObjectProperties(Renderer* r, GraphicsComponent* g = nullptr, AnimationComponent* a = nullptr, PhysicsComponent* p = nullptr);
    GameObjectProperties(const GameObjectProperties& properties);

    ~GameObjectProperties();

    Renderer* renderer;
    GraphicsComponent* graphicsComponent;
    AnimationComponent* animationComponent;
    PhysicsComponent* physicsComponent;
    
private:

};