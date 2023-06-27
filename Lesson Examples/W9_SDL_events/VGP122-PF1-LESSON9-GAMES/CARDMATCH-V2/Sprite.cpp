#include "Sprite.h"

Sprite::Sprite(std::string goID, std::string f, int x, int y, int r, int c, int offsetX, int offsetY, double a, SDL_RendererFlip flip) 
	: filename(f), position(x, y), angle(a), rows(r), cols(c), offsetX(offsetX), offsetY(offsetY), flipFlag(flip)
{
	renderer = Game::getRenderer();

	// Manager Initialization
	resourceManager = ResourceManager::getInstance();
	animationManager = AnimationManager::getInstance();
	timeManager = TimeManager::getInstance();

	// ID Initialization
	gameObjectID = goID;
	resourceID = filename;

	load();

	// Frame/Animation Initialization
	visible = true;
	animating = false;
	reverse = false;
	repeat = false;
	currentAnimation = "default";

	// Get default animation to determine length
	currentSequence = animationManager->animationMap[gameObjectID + currentAnimation];

	fps = 0;
	currentFrame = 0;
	startFrame = currentSequence[0];
	endFrame = currentSequence.size() - 1;

	// Time Initialization
	timeManager->addTimer(gameObjectID, true);
	timeManager->start(gameObjectID);
	startTime = timeManager->get(gameObjectID);
}

Sprite::~Sprite()
{
	std::cout << "Removing sprite " << filename << "..." << std::endl;
	timeManager->remove(gameObjectID);
	SDL_DestroyTexture(texture);
}

void Sprite::load()
{
	texture = resourceManager->load(gameObjectID, filename, rows, cols, offsetX, offsetY);

	SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);
}

void Sprite::update()
{
	if (animating)
	{
		Uint32 currentTime = timeManager->get(gameObjectID);
		Uint32 deltaTime = currentTime - startTime;

		currentFrame = ((((deltaTime * fps) / 1000) - startFrame) % ((endFrame + 1) - startFrame)) + startFrame;

		if (!repeat && currentFrame == endFrame)
			animating = false;
	}
}

void Sprite::render()
{
	if (this->visible)
	{
		std::vector<SDL_Rect> frameMap = animationManager->getFrameMap(gameObjectID, currentAnimation);

		SDL_Rect source = frameMap[currentSequence[currentFrame]];
		SDL_Rect destination = getRect();

		SDL_RenderCopyEx(renderer, texture, &source, &destination, angle, nullptr, flipFlag);
	}
}

void Sprite::addAnimation(std::string animationID, const std::vector<int> sequence)
{
	std::cout << "Adding animation " << gameObjectID + animationID << "..." << std::endl;
	animationManager->animationMap[gameObjectID + animationID] = sequence;
}

void Sprite::play(int startFrame, int endFrame, int fps, bool r, bool rev, bool flip)
{
	currentSequence = animationManager->animationMap[gameObjectID + currentAnimation];

	if (rev)
		std::reverse(currentSequence.begin(), currentSequence.end());

	if (startFrame < 0 || endFrame >= currentSequence.size())
	{
		std::cout << "Animation out of range" << std::endl;
		return;
	}
	else
	{
		std::cout << "Starting animation " << gameObjectID + currentAnimation << "..." << std::endl;

		animating = true;

		this->fps = fps;
		repeat = r;
		reverse = rev;

		this->startFrame = startFrame;
		this->endFrame = endFrame;

		if (flip)
			flipFlag = SDL_FLIP_HORIZONTAL;
		else
			flipFlag = SDL_FLIP_NONE;
	}
}

void Sprite::play(std::string animationID, int fps, bool r, bool rev, bool flip)
{
	currentSequence = animationManager->animationMap[gameObjectID + animationID];

	if (rev)
		std::reverse(currentSequence.begin(), currentSequence.end());

	if (!currentSequence.empty())
	{
		std::cout << "Starting animation " << gameObjectID + animationID << "..." << std::endl;

		this->fps = fps;

		currentAnimation = animationID;
		startFrame = 0;
		endFrame = currentSequence.size() - 1;

		animating = true;
		repeat = r;
		reverse = rev;

		if (flip)
			flipFlag = SDL_FLIP_HORIZONTAL;
		else
			flipFlag = SDL_FLIP_NONE;
	}
	else
		std::cout << "Animation " << animationID << "does not exist" << std::endl;
}

void Sprite::stop()
{
	animating = false;
}

void Sprite::gotoPos(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Sprite::move(int deltaX, int deltaY)
{
	position.x += deltaX;
	position.y += deltaY;
}

SDL_Rect Sprite::getRect()
{
	return SDL_Rect{ static_cast<int>(position.x), static_cast<int>(position.y), textureWidth / cols, textureHeight / rows };
}

void Sprite::setCurrentFrame(int frame)
{
	std::vector<int> sequence = animationManager->animationMap[gameObjectID + currentAnimation];

	if (frame < 0 || frame >= sequence.size())
		currentFrame = 0;
	else
		currentFrame = frame;
}

int Sprite::getCurrentFrame()
{
	return currentFrame;
}

SDL_Texture* Sprite::getFrame()
{
	return texture;
}

bool Sprite::isAnimating()
{
	return animating;
}

bool Sprite::isVisible()
{
	return visible;
}

void Sprite::setVisible(bool visible)
{
	this->visible = visible;
}

Uint32 Sprite::getDelta()
{
	Uint32 currentTime = timeManager->get(gameObjectID);
	Uint32 deltaTime = currentTime - startTime;

	return deltaTime;
}