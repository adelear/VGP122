#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	renderer = Game::getInstance()->getRenderer(); 
	TTF_Init(); 
}

ResourceManager::~ResourceManager()
{ }

ResourceManager* ResourceManager::getInstance()
{
	if (instance == nullptr)
		instance = new ResourceManager();

	return instance;
}

void ResourceManager::removeInstance()
{
	if (instance != nullptr)
		delete instance;
}

SDL_Texture* ResourceManager::load(SDL_Renderer* renderer, std::string filename)
{
	std::unordered_map<std::string, SDL_Texture*>::iterator it = resources.find(filename);

	if (it != resources.end())
	{
		//std::cout << "Sprite " << filename << " already loaded..." << std::endl;
		return (*it).second;
	}

	SDL_Texture* texture = IMG_LoadTexture(renderer, filename.c_str());

	std::cout << "Loading sprite " << filename << "..." << std::endl;

	if (texture == nullptr)
	{
		std::cout << "Error: Unable to open sprite - " << IMG_GetError() << std::endl;
		return nullptr;
	}

	resources[filename] = texture;

	return texture;
}

SDL_Texture* ResourceManager::findResource(std::string filename)
{
	SDL_Texture* texture = resources[filename];
	
	if (texture == nullptr)
	{
		std::cout << "Error: Unable to find resource " << filename << std::endl;
		return nullptr;
	}

	return texture;
}

void ResourceManager::addGameObject(int depth, GameObject* o)
{
	gameObjects[depth] = o;
}

TTF_Font* ResourceManager::loadFont(std::string filename, int ptsize)
{
	TTF_Font* font = TTF_OpenFont(filename.c_str(), ptsize);

	if (!font)
	{
		std::cout << "Error: Unable to open font - " << TTF_GetError() << std::endl;  
		return nullptr; 
	}

	std::unordered_map<std::string, TTF_Font*>::iterator it = fonts.find(filename);

	if (it != fonts.end())
	{
		std::cout << "Font " << filename << " already loaded..." << std::endl;
		return (*it).second;
	}
	else
	{
		std::cout << "Loading font " << filename << "..." << std::endl;
		fonts[filename] = font;
	}

	return font; 
} 

TTF_Font* ResourceManager::findFont(std::string filename)
{
	TTF_Font* font = fonts[filename];

	if (font == nullptr)
	{
		std::cout << "Error: Unable to find font " << filename << std::endl;
		return nullptr;
	}

	return font;
} 

void ResourceManager::removeFont(std::string filename)
{
	TTF_Font* f = ResourceManager::getInstance()->findFont(filename);

	if (!f) TTF_CloseFont(f);
}



std::unordered_map<std::string, SDL_Texture*> ResourceManager::resources;
std::unordered_map<std::string, TTF_Font*>ResourceManager::fonts;  
std::map<int, GameObject*> ResourceManager::gameObjects;
ResourceManager* ResourceManager::instance = nullptr;