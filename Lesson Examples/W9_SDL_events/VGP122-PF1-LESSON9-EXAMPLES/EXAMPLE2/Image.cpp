#include "Image.h"

Image::Image() : GameObject(nullptr)
{ }

Image::Image(std::string goID, std::string filename, float x, float y, int w, int h, int rows, int cols)
    : GameObject()
{
    Renderer* renderer = Renderer::getInstance();
    GraphicsComponent* gc = new GraphicsComponent();
    AnimationComponent* ac = nullptr;
    PhysicsComponent* pc = nullptr;

    properties = new GameObjectProperties(renderer, gc, ac, pc);
    
    gameObjectID = goID;
    gc->filename = filename;
    gc->position = { x, y };
    gc->w = w;
    gc->h = h;
    gc->rows = rows;
    gc->cols = cols;

    loadAsset(goID);
}

Image::Image(GameObjectProperties* properties) 
    : GameObject(properties)
{ }

Image::Image(const Image& other)
{
    Renderer* renderer = Renderer::getInstance();
    GraphicsComponent* gc = new GraphicsComponent();
    AnimationComponent* ac = nullptr;
    PhysicsComponent* pc = nullptr;

    properties = new GameObjectProperties(renderer, gc, ac, pc);
}

Image::~Image()
{ }

Image* Image::clone()
{
    return new Image(*this);
}

void Image::update()
{ }

void Image::render()
{
    GraphicsComponent* gc = properties->graphicsComponent;

    if (gc->visible)
    {
        SDL_Rect source{ 0, 0, gc->w, gc->h };
        SDL_Rect destination = getRect();

        SDL_RenderCopyEx(Game::getRenderer(), gc->texture, &source, &destination, gc->angle, nullptr, gc->flipFlag);
    }
}

void Image::loadAsset(std::string goID)
{
    properties->graphicsComponent->loadAsset(goID);
}

std::string Image::getFilename()
{
    return properties->graphicsComponent->filename;
}

Vector2D Image::getPosition()
{
    return properties->graphicsComponent->position;
}

int Image::getWidth()
{
    return properties->graphicsComponent->w;
}

int Image::getHeight()
{
    return properties->graphicsComponent->h;
}

void Image::setPosition(Vector2D v)
{
    properties->graphicsComponent->position = v;
}

double Image::getAngle()
{
    return properties->graphicsComponent->angle;
}

void Image::setAngle(double angle)
{
    properties->graphicsComponent->angle = angle;
}

SDL_Rect Image::getRect()
{
    GraphicsComponent* gc = properties->graphicsComponent;

    return SDL_Rect{ static_cast<int>(gc->position.x), static_cast<int>(gc->position.y), gc->w, gc->h };
}

bool Image::isVisible()
{
    return properties->graphicsComponent->visible;
}

void Image::setVisible(bool visible)
{
    properties->graphicsComponent->visible = visible;
}