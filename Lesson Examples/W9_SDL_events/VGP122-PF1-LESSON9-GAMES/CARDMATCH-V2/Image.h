#pragma once

#include <iostream>
#include <string>

#include "SDL.h"
#include "SDL_image.h"

#include "GameObject.h"
#include "Vector2D.h"
#include "ResourceManager.h"

class Image : public GameObject
{
public:
	Image(std::string, std::string, int, int, double = 0.0, SDL_RendererFlip = SDL_FLIP_NONE);
	~Image();

	virtual void update();
	virtual void render();

	SDL_Rect getRect();

	void setVisible(bool);

	Vector2D position;
	int w;
	int h;

private:
	void load();

	std::string filename;

	double angle;
	SDL_RendererFlip flip;

	bool visible;

	SDL_Renderer* renderer;
	SDL_Texture* texture;
};