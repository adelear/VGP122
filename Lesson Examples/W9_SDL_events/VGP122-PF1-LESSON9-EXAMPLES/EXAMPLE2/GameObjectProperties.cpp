#include "GameObjectProperties.h"

GameObjectProperties::GameObjectProperties() 
    : renderer(nullptr), graphicsComponent(nullptr), animationComponent(nullptr), physicsComponent(nullptr)
{ }

GameObjectProperties::GameObjectProperties(Renderer* r, GraphicsComponent* g, AnimationComponent* a, PhysicsComponent* p)
    : renderer(r), graphicsComponent(g), animationComponent(a), physicsComponent(p)
{ }

GameObjectProperties::GameObjectProperties(const GameObjectProperties& properties) 
    : renderer(properties.renderer), graphicsComponent(properties.graphicsComponent), animationComponent(properties.animationComponent), physicsComponent(properties.physicsComponent)
{ }

GameObjectProperties::~GameObjectProperties()
{
    if (renderer != nullptr)
        Renderer::removeInstance();
    if (graphicsComponent != nullptr)
        delete graphicsComponent;
    if (animationComponent != nullptr)
        delete animationComponent;
    if (physicsComponent != nullptr)
        delete  physicsComponent;

    graphicsComponent = nullptr;
    animationComponent = nullptr;
    physicsComponent = nullptr;
}