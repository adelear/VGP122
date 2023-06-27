#include "Scene.h"

Scene::~Scene()
{
	std::unordered_map<std::string, GameObject*>::iterator it = gameObjectMap.begin();

	while (it != gameObjectMap.end())
	{
		std::string goID = (*it).first;

		std::cout << "Removing GameObject " << goID << "..." << std::endl;
		delete gameObjectMap[goID];

		++it;
	}
}

void Scene::update()
{
	std::unordered_map<std::string, int>::iterator it = depthMap.begin();

	while (it != depthMap.end())
	{
		std::string goID = (*it).first;

		gameObjectMap[goID]->update();

		++it;
	}
}

void Scene::render()
{
	std::vector<std::pair<int, std::string>> sortedMap;

	for (auto i : depthMap)
		sortedMap.push_back({ i.second, i.first });

	std::sort(sortedMap.begin(), sortedMap.end());

	std::vector<std::pair<int, std::string>>::iterator it = sortedMap.begin();

	while (it != sortedMap.end())
	{
		std::string goID = (*it).second;

		gameObjectMap[goID]->render();

		++it;
	}
}

void Scene::addGameObject(GameObject* object, int depth)
{
	std::string goID = object->getGameObjectID();
	
	std::cout << "Adding GameObject " << goID << "..." << std::endl;
	gameObjectMap[goID] = object;
	depthMap[goID] = depth;
}

bool Scene::onEnter()
{
	return true;
}

bool Scene::onExit()
{
	std::unordered_map<std::string, int>::iterator depthIT = depthMap.begin();
	std::unordered_map<std::string, GameObject*>::iterator goIT = gameObjectMap.begin();

	while (depthIT != depthMap.end())
	{
		std::string goID = (*depthIT).first;

		depthMap.erase(depthIT);
		gameObjectMap.erase(goIT);

		++depthIT;
		++goIT;
	}
	
	std::cout << "Exiting Scene..." << std::endl;
	
	return true;
}

GameObject* Scene::getObjectByID(std::string id)
{
	return gameObjectMap[id];
}