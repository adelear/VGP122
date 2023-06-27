#include "Renderer.h"

Renderer::Renderer()
{
	//UPDATE - get Game Renderer
	renderer = nullptr;
}

Renderer::~Renderer()
{
	// REPLACE with SDL_DestroyTexture
	if(renderer != nullptr)
		delete renderer;
}

Renderer* Renderer::getInstance()
{
	if (!instance)
		instance = new Renderer();

	return instance;
}

void Renderer::removeInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

SDL_Renderer* Renderer::getRenderer()
{
	return renderer;
}

Renderer* Renderer::instance = nullptr;
SDL_Renderer* Renderer::renderer = nullptr;