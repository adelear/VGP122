#pragma once

#include <iostream>
#include <string>

#include "GameObjectBuilder.h"
#include "ImageDirector.h"
#include "SpriteDirector.h"
#include "Image.h"
#include "Sprite.h"

class Image;
class Sprite;

template <typename T>
class ImageDirector;

template <typename T>
class SpriteDirector;

template <typename T>
class GameObjectDirector
{
public:
    void construct(GameObjectBuilder<T>* builder)
    {
        std::cout << "Creating Game Object..." << std::endl;
        builder->construct();
    }

    static GameObjectDirector<T>* getDirector()
    {
        if constexpr (std::is_same_v<T, Image>)
        {
            return new ImageDirector<T>();
        }
        else if constexpr (std::is_same_v<T, Sprite>)
        {
            return new SpriteDirector<T>();
        }
        else
        {
            std::cout << "GameObject does not exist" << std::endl;
        }
    }
};