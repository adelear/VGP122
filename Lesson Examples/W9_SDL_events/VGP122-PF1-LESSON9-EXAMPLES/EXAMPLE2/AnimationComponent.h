#pragma once

#include <vector>
#include <string>

#include "SDL.h"

#include "Object.h"
#include "AnimationManager.h"
#include "TimeManager.h"

class ResourceManager;

class AnimationComponent : public Object
{
public:
    AnimationComponent();

	void initialize(std::string gameObjectID);

	std::vector<int> currentSequence;
	std::string currentAnimation;
	int currentFrame;
	int startFrame;
	int endFrame;

	int fps;
	Uint32 startTime;

	bool animating;
	bool repeat;
	bool reverse;

private:
	ResourceManager* resourceManager;
	AnimationManager* animationManager;
	TimeManager* timeManager;
};