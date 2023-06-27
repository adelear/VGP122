#pragma once

#include "Object.h"
#include "Vector2D.h"
#include "Collider.h"

class PhysicsComponent : public Object
{
public:
    PhysicsComponent();
    ~PhysicsComponent();

    Collider collider;

    Vector2D velocity;
    Vector2D acceleration;

    Uint32 startTime;
    Uint32 endTime;

private:
    
};