#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	renderer = Game::getInstance()->getRenderer();

	animationManager = AnimationManager::getInstance();
}

ResourceManager::~ResourceManager()
{ 
	AnimationManager::removeInstance();
	IMG_Quit();
}

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

SDL_Texture* ResourceManager::load(std::string goID, std::string filename, int totalRows, int totalCols, int offsetX, int offsetY)
{
	SDL_Texture* texture;
	std::unordered_map<std::string, SDL_Texture*>::iterator it = textureMap.find(filename);

	if (it != textureMap.end())
	{
		std::cout << "Sprite " << filename << " already loaded..." << std::endl;
		texture = (*it).second;
	}
	else
	{
		renderer = Game::getInstance()->getRenderer();
		texture = IMG_LoadTexture(renderer, filename.c_str());

		std::cout << "Loading sprite " << filename << "..." << std::endl;

		if (texture == nullptr)
		{
			std::cout << "Error: Unable to open sprite - " << IMG_GetError() << std::endl;
			return nullptr;
		}
	}

	int w;
	int h;

	SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);

	w /= totalCols;
	h /= totalRows;

	std::vector<SDL_Rect> frameInfo;
	std::vector<int> animationSequence;
	std::string animationName = "default";

	frameInfo.reserve(totalRows * totalCols);

	for (int i = 0; i < totalRows; ++i)
	{
		for (int j = 0; j < totalCols; ++j)
		{
			SDL_Rect temp;

			temp.x = (j * w) + offsetX;
			temp.y = (i * h) + offsetY;
			temp.w = w;
			temp.h = h;

			frameInfo.push_back(temp);
			animationSequence.push_back(i * totalCols + j);
		}
	}

	if (totalRows == 1 && totalCols > 1 || totalRows > 1 && totalCols == 1 || totalRows > 1 && totalCols > 1)
	{
		animationManager->frameMap.insert({ goID + animationName, frameInfo });
		animationManager->animationMap[goID + animationName] = animationSequence;
		animationManager->gameObjects.insert({ goID, goID + animationName });
	}

	resourceMap[goID] = filename;
	textureMap[filename] = texture;

	return texture;
}

SDL_Texture* ResourceManager::findResource(std::string filename)
{
	SDL_Texture* texture = textureMap[filename];
	
	if (texture == nullptr)
	{
		std::cout << "Error: Unable to find resource " << filename << std::endl;
		return nullptr;
	}

	return texture;
}

void ResourceManager::addGameObject(GameObject* o, int depth)
{
	gameObjects[depth] = o;
}

std::unordered_map<std::string, SDL_Texture*> ResourceManager::textureMap;
std::map<int, GameObject*> ResourceManager::gameObjects;
ResourceManager* ResourceManager::instance = nullptr;