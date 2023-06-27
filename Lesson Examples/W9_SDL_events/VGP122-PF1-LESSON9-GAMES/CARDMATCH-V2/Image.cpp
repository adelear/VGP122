#include "Image.h"

Image::Image(std::string goID, std::string f, int x, int y, double a, SDL_RendererFlip flip) : filename(f), position(x, y), angle(a), flip(flip)
{
	visible = true;

	gameObjectID = goID;
	resourceID = filename;

	renderer = Game::getRenderer();

	load();
}

Image::~Image()
{
	std::cout << "Removing image " << filename << "..." << std::endl;
	SDL_DestroyTexture(texture);
}

void Image::update()
{

}

void Image::render()
{
	if (visible)
	{
		SDL_Rect source{ 0, 0, w, h };
		SDL_Rect destination = getRect();

		SDL_RenderCopyEx(renderer, texture, &source, &destination, angle, nullptr, flip);
	}
}

SDL_Rect Image::getRect()
{
	return SDL_Rect { static_cast<int>(position.x), static_cast<int>(position.y), w, h };
}

void Image::setVisible(bool v)
{
	visible = v;
}

void Image::load()
{
	texture = ResourceManager::getInstance()->load(gameObjectID, filename);

	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
}