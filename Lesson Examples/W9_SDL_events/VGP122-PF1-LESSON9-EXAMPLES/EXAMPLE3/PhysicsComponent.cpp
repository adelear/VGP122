#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent() : collider(0.0f, 0.0f, 0.0f, 0.0f), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f), endTime(0)
{ }

PhysicsComponent::~PhysicsComponent()
{ }