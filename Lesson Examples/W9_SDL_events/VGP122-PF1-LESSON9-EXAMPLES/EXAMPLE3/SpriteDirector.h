#pragma once

#include <iostream>

#include "GameObjectDirector.h"
#include "GameObjectBuilder.h"

template <typename T>
class GameObjectDirector;

template <typename T>
class SpriteDirector : public GameObjectDirector<T>
{
public:
    void construct(GameObjectBuilder<T>* builder)
    {
        std::cout << "Creating Sprite..." << std::endl;
        builder->construct();
    }
};