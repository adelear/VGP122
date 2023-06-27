#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include "SDL.h"

#include "GameObject.h"

class GameObject;

class Scene
{
public:
	virtual ~Scene();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual void onKeyDown(SDL_Event&) { };
	virtual void onKeyUp(SDL_Event&) { };

	virtual void onMouseButtonDown(SDL_Event&) { };
	virtual void onMouseButtonUp(SDL_Event&) { };
	virtual void onMouseMove(SDL_Event&) { };

	virtual void onControllerButtonDown(SDL_Event&) { };
	virtual void onControllerButtonUp(SDL_Event&) { };
	virtual void onControllerAxisMotion(SDL_Event&) { };

	//virtual std::string getSceneID() const { };

	void addGameObject(GameObject*, int);
	GameObject* getObjectByID(std::string);

protected:
	Scene() = default;
	
private:
	std::unordered_map<std::string, int> depthMap;
	std::unordered_map<std::string, GameObject*> gameObjectMap;
};