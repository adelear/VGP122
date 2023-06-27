#pragma once

#include <string>

#include "GameObjectProperties.h"
#include "Renderer.h"
#include "GraphicsComponent.h"
#include "AnimationComponent.h"
#include "PhysicsComponent.h"
#include "GameObject.h"
#include "Image.h"
#include "Sprite.h"

class GraphicsComponent;
class AnimationComponent;
class PhysicsComponent;
class GameObjectProperties;
class Image;
class Sprite;

template <typename T>
class GameObjectBuilder
{
public:
    static GameObjectBuilder<T>* getObjectBuilder()
    {
        if (!instance)
            instance = new GameObjectBuilder();

        return instance;
    }

    static void removeGameObjectBuilder()
    {
        if (instance)
            delete instance;
    }

    void construct()
    {
        Renderer* renderer;
        GraphicsComponent* gc;
        AnimationComponent* ac;
        PhysicsComponent* pc;

        if constexpr (std::is_same_v<T, Image>)
        {
            renderer = Renderer::getInstance();
            gc = new GraphicsComponent();
            ac = nullptr;
            pc = nullptr;
        }
        else if constexpr (std::is_same_v<T, Sprite>)
        {
            renderer = Renderer::getInstance();
            gc = new GraphicsComponent();
            ac = new AnimationComponent();
            pc = new PhysicsComponent();
        }
        else
            properties = nullptr;

        constructed = true;

        properties = new GameObjectProperties(renderer, gc, ac, pc);
        prototype = new T(properties);
    }
    
    T* getGameObject(std::string goID, std::string filename, float x, float y, int w = 0, int h = 0, int rows = 1, int cols = 1)
    {
        T* newGameObject = nullptr;

        if (constructed)
        {
            newGameObject = prototype->clone();
            newGameObject->setGameObjectID(goID);

            if (newGameObject->properties->graphicsComponent)
            {
                GraphicsComponent* gc = newGameObject->properties->graphicsComponent;
                gc->filename = filename;
                gc->position = { x, y };
                gc->w = w;
                gc->h = h;
                gc->rows = rows;
                gc->cols = cols;
                newGameObject->loadAsset(goID);
            }

            if (newGameObject->properties->animationComponent)
                newGameObject->properties->animationComponent->initialize(goID);

            if (newGameObject->properties->physicsComponent)
            {
                newGameObject->properties->physicsComponent->collider.position = { x, y };
                newGameObject->properties->physicsComponent->collider.w = w;
                newGameObject->properties->physicsComponent->collider.h = h;
            }
        }

        return newGameObject;
    }
    
private:
    GameObjectBuilder()
        : properties{ nullptr }, constructed(false)
    { }

    GameObjectBuilder(GameObjectProperties* properties)
        : properties{ properties }
    { }

    ~GameObjectBuilder()
    {
        delete prototype;
    }

    bool constructed;

    GameObjectProperties* properties;

    static T* prototype;
    static GameObjectBuilder* instance;
};

template <typename T>
T* GameObjectBuilder<T>::prototype = new T();

template <typename T>
GameObjectBuilder<T>* GameObjectBuilder<T>::instance = nullptr;