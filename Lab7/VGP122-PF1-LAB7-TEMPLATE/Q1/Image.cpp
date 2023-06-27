#include "Image.h"

Image::Image(SDL_Renderer* r, std::string f, int x, int y, double a, SDL_RendererFlip flip) : renderer(r), filename(f), position(x, y), angle(a), flip(flip)
{
	visible = true;

	load();
}

Image::~Image()
{
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
	return SDL_Rect{ static_cast<int>(position.x), static_cast<int>(position.y), w, h };
}

void Image::setVisible(bool v)
{
	visible = v;
}

void Image::load()
{
	std::cout << "Loading image " << filename << "..." << std::endl;
	texture = IMG_LoadTexture(renderer, filename.c_str());

	if (texture == nullptr)
		std::cout << "Error: Unable to open image - " << IMG_GetError() << std::endl;

	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
}

void Image::resize(int width, int height)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	SDL_Surface* resizedSurface = SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
	SDL_BlitScaled(surface, nullptr, resizedSurface, nullptr);
	SDL_DestroyTexture(texture);
	texture = SDL_CreateTextureFromSurface(renderer, resizedSurface);
	SDL_FreeSurface(surface);
	SDL_FreeSurface(resizedSurface);

	// Update width and height variables
	w = width;
	h = height;
}

 
