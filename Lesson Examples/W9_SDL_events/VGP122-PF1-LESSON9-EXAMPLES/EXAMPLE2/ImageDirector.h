#pragma once

#include <iostream>

#include "GameObjectDirector.h"
#include "GameObjectBuilder.h"

template <typename T>
class GameObjectDirector;

template <typename T>
class ImageDirector : public GameObjectDirector<T>
{
public:
    void construct(GameObjectBuilder<T>* builder)
    {
        std::cout << "Creating Image..." << std::endl;
        builder->construct();
    }
};