#pragma once

#include <string>
#include <map>
#include <unordered_map>

#include "SDL.h"
#include "SDL_image.h"

#include "Game.h"
#include "AnimationManager.h"

class GameObject;

class ResourceManager
{
public:
	~ResourceManager();

	static ResourceManager* getInstance();
	static void removeInstance();

	SDL_Texture* load(std::string goID, std::string filename, int = 1, int = 1, int = 0, int = 0);

	SDL_Texture* findResource(std::string filename);

	void addGameObject(GameObject*, int);

	static std::unordered_map<std::string, SDL_Texture*> textureMap;
	static std::map<int, GameObject*> gameObjects;


private:
	ResourceManager();

	SDL_Renderer* renderer;
	AnimationManager* animationManager;

	std::unordered_map<std::string, std::string> resourceMap;

	static ResourceManager* instance;
};