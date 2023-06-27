#include "Text.h"

Text::Text(SDL_Renderer* r, std::string f, int x, int y, int size, double a, SDL_RendererFlip flip) : renderer(r), filename(f), position(x, y), fontSize(size), angle(a), flip(flip)
{ 
    visible = true;
    w = 0;
    h = 0;
    surface = nullptr;
    texture = nullptr;
    color = { 255, 255, 255, 200 };
}  

Text::~Text()
{
    std::cout << "Removing Text " << filename << "..." << std::endl;
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Text::update()
{

}

void Text::render()
{
    if (visible)
    {
        SDL_Rect dest = getRect();

        SDL_RenderCopyEx(renderer, texture, nullptr, &dest, angle, nullptr, flip);

    }
}

SDL_Rect Text::getRect()
{
    return SDL_Rect{ static_cast<int>(position.x * SCALE_SIZE), static_cast<int>(position.y * SCALE_SIZE), (int)ceil(w * SCALE_SIZE), (int)ceil(h * SCALE_SIZE) };
}

bool Text::isVisible()
{
    return visible;
}

void Text::setVisible(bool v)
{
    visible = v;
}


void Text::load()
{
    TTF_Font* font = ResourceManager::getInstance()->loadFont(filename, fontSize);
    if (!font) {
        std::cout << "Font not loaded" << std::endl;
        return;
    }

    surface = TTF_RenderText_Solid(font, output.c_str(), color);
    if (surface == nullptr) {
        std::cout << "Error rendering text surface: " << TTF_GetError() << std::endl;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    w = surface->w;
    h = surface->h; 
} 



void Text::setText(std::string t)
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    output = t;
    load();
}

void Text::setFont(std::string f)
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    filename = f;
    load();
}

void Text::setFontSize(float v)
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    fontSize = v;
    load();
}

void Text::setColor(SDL_Color c)
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    color = c;
    load();
}

 