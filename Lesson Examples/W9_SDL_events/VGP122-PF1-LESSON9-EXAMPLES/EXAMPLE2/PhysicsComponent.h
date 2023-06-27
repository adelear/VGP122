#pragma once

#include "Object.h"
#include "Collider.h"

class PhysicsComponent : public Object
{
public:
    PhysicsComponent();
    ~PhysicsComponent();

    Collider collider;

private:
    
};