#pragma once

#include <string>
#include <map>
#include <unordered_map>

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"  

#include "GameObject.h"
#include "Sprite.h"
#include "Game.h" 

class ResourceManager
{
public:
	~ResourceManager();

	static ResourceManager* getInstance();
	static void removeInstance();

	TTF_Font* loadFont(std::string, int);  
	SDL_Texture* load(SDL_Renderer*, std::string);
	SDL_Texture* findResource(std::string filename);

	TTF_Font* findFont(std::string); 

	void addGameObject(int, GameObject*); 

	void removeFont(std::string); 

	static std::unordered_map<std::string, SDL_Texture*> resources;
	static std::unordered_map<std::string, TTF_Font*> fonts; 
	static std::map<int, GameObject*> gameObjects;


private:
	ResourceManager();

	SDL_Renderer* renderer;

	static ResourceManager* instance;
};