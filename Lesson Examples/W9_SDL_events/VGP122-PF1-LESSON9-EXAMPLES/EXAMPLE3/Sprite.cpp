#include "Sprite.h"

Sprite::Sprite() : GameObject()
{
	resourceManager = ResourceManager::getInstance();
	animationManager = AnimationManager::getInstance();
	timeManager = TimeManager::getInstance();

	position = nullptr;
	velocity = nullptr;
	acceleration = nullptr;
}

Sprite::Sprite(std::string goID, std::string filename, float x, float y, int w, int h, int rows, int cols)
{
	Renderer* renderer = Renderer::getInstance();
	GraphicsComponent* gc = new GraphicsComponent();
	AnimationComponent* ac = new AnimationComponent();
	PhysicsComponent* pc = new PhysicsComponent();

	properties = new GameObjectProperties(renderer, gc, ac, pc);

	gameObjectID = goID;
	gc->filename = filename;
	gc->position = { x, y };
	gc->w = w;
	gc->h = h;
	gc->rows = rows;
	gc->cols = cols;

	loadAsset(goID);

	ac->initialize(goID);

	pc->collider.position = { x, y };
	pc->collider.w = w;
	pc->collider.h = h;

	position = &gc->position;
	velocity = &pc->velocity;
	acceleration = &pc->acceleration;

	resourceManager = ResourceManager::getInstance();
	animationManager = AnimationManager::getInstance();
	timeManager = TimeManager::getInstance();
}

Sprite::Sprite(GameObjectProperties* properties) 
    : GameObject(properties)
{
	GraphicsComponent* gc = new GraphicsComponent();
	PhysicsComponent* pc = new PhysicsComponent();

	resourceManager = ResourceManager::getInstance();
	animationManager = AnimationManager::getInstance();
	timeManager = TimeManager::getInstance();

	position = &gc->position;
	velocity = &pc->velocity;
	acceleration = &pc->acceleration;
}

Sprite::Sprite(const Sprite& other)
{
	Renderer* renderer = Renderer::getInstance();
	GraphicsComponent* gc = new GraphicsComponent();
	AnimationComponent* ac = new AnimationComponent();
	PhysicsComponent* pc = new PhysicsComponent();

	properties = new GameObjectProperties(renderer, gc, ac, pc);

	resourceManager = ResourceManager::getInstance();
	animationManager = AnimationManager::getInstance();
	timeManager = TimeManager::getInstance();

	position = &gc->position;
	velocity = &pc->velocity;
	acceleration = &pc->acceleration;
}

Sprite::~Sprite()
{ }

Sprite* Sprite::clone()
{
    return new Sprite(*this);
}

void Sprite::update()
{
	GraphicsComponent* gc = properties->graphicsComponent;
	AnimationComponent* ac = properties->animationComponent;
	PhysicsComponent* pc = properties->physicsComponent;

	pc->collider.position = gc->position;

	if (ac->animating)
	{
		Uint32 currentTime = timeManager->get(gameObjectID);
		Uint32 deltaTime = currentTime - ac->startTime;
		
		if (deltaTime >= 1000 / ac->fps)
			ac->currentFrame = ((((deltaTime * ac->fps) / 1000) - ac->startFrame) % ((ac->endFrame + 1) - ac->startFrame)) + ac->startFrame;

		/*Uint32 currentTime = timeManager->get(gameObjectID);
		Uint32 delta = currentTime - ac->prevTime;

		if (delta >= 1000 / ac->fps)
		{
			int numFrame = delta / (1000 / ac->fps);
			ac->currentFrame = (ac->currentFrame + numFrame) % (ac->endFrame + 1);
			ac->prevTime = currentTime;
		}*/

		if (!ac->repeat && ac->currentFrame == ac->endFrame)
			ac->animating = false;
	}
}

void Sprite::render()
{
	GraphicsComponent* gc = properties->graphicsComponent;
	AnimationComponent* ac = properties->animationComponent;

	if (gc->visible)
	{
		std::vector<SDL_Rect> frameMap = animationManager->getFrameMap(gameObjectID, ac->currentAnimation);

		SDL_Rect source = frameMap[ac->currentSequence[ac->currentFrame]];
		SDL_Rect destination = getRect();

		SDL_RenderCopyEx(Game::getRenderer(), gc->texture, &source, &destination, gc->angle, nullptr, gc->orientation);
	}
}

void Sprite::loadAsset(std::string goID)
{
	properties->graphicsComponent->loadAsset(goID);
}

void Sprite::addAnimation(std::string animationID, const std::vector<int> sequence)
{
	std::cout << "Adding animation " << gameObjectID + animationID << "..." << std::endl;
	animationManager->animationMap[gameObjectID + animationID] = sequence;
}

void Sprite::play(int startFrame, int endFrame, int fps, bool r, bool rev, bool flip)
{
	GraphicsComponent* gc = properties->graphicsComponent;
	AnimationComponent* ac = properties->animationComponent;

	ac->currentSequence = animationManager->animationMap[gameObjectID + ac->currentAnimation];

	if (rev)
		std::reverse(ac->currentSequence.begin(), ac->currentSequence.end());

	if (startFrame < 0 || endFrame >= ac->currentSequence.size())
	{
		std::cout << "Animation out of range" << std::endl;
		return;
	}
	else
	{
		std::cout << "Starting animation " << gameObjectID + ac->currentAnimation << "..." << std::endl;

		ac->animating = true;

		ac->fps = fps;
		ac->repeat = r;
		ac->reverse = rev;

		ac->startFrame = startFrame;
		ac->endFrame = endFrame;

		if (flip)
			gc->orientation = SDL_FLIP_HORIZONTAL;
		else
			gc->orientation = SDL_FLIP_NONE;
	}
}

void Sprite::play(std::string animationID, int fps, bool r, bool rev, bool flip)
{
	GraphicsComponent* gc = properties->graphicsComponent;
	AnimationComponent* ac = properties->animationComponent;

	ac->currentSequence = animationManager->animationMap[gameObjectID + animationID];

	if (rev)
		std::reverse(ac->currentSequence.begin(), ac->currentSequence.end());

	if (!ac->currentSequence.empty())
	{
		std::cout << "Starting animation " << gameObjectID + animationID << "..." << std::endl;

		ac->fps = fps;

		ac->currentAnimation = animationID;
		ac->startFrame = 0;
		ac->endFrame = ac->currentSequence.size() - 1;

		ac->animating = true;
		ac->repeat = r;
		ac->reverse = rev;

		if (flip)
			gc->orientation = SDL_FLIP_HORIZONTAL;
		else
			gc->orientation = SDL_FLIP_NONE;
	}
	else
		std::cout << "Animation " << animationID << "does not exist" << std::endl;
}

void Sprite::stop()
{
	AnimationComponent* ac = properties->animationComponent;

	ac->animating = false;
}

void Sprite::setCurrentFrame(int frame)
{
	AnimationComponent* ac = properties->animationComponent;

	std::vector<int> sequence = animationManager->animationMap[gameObjectID + ac->currentAnimation];

	if (frame < 0 || frame >= sequence.size())
		ac->currentFrame = 0;
	else
		ac->currentFrame = frame;
}

Collider Sprite::getCollider()
{
	return properties->physicsComponent->collider;
}

bool Sprite::checkCollision(Collider& b)
{
	return properties->physicsComponent->collider.checkCollision(b);
}

int Sprite::getCurrentFrame()
{
	AnimationComponent* ac = properties->animationComponent;

	return ac->currentFrame;
}

SDL_Texture* Sprite::getFrame()
{
	GraphicsComponent* gc = properties->graphicsComponent;

	return gc->texture;
}

bool Sprite::isAnimating()
{
	AnimationComponent* ac = properties->animationComponent;

	return ac->animating;
}

std::string Sprite::getCurrentAnimation()
{
	AnimationComponent* ac = properties->animationComponent;

	return ac->currentAnimation;
}

Uint32 Sprite::getStartTime()
{
	AnimationComponent* ac = properties->animationComponent;
	return ac->startTime;
}

Uint32 Sprite::getCurrentTime()
{
	return timeManager->get(gameObjectID);
}

Uint32 Sprite::getEndTime()
{
	PhysicsComponent* pc = properties->physicsComponent;

	return pc->endTime;
}

void Sprite::setEndTime(Uint32 time)
{
	PhysicsComponent* pc = properties->physicsComponent;

	pc->endTime = time;
}

Uint32 Sprite::getDelta()
{
	AnimationComponent* ac = properties->animationComponent;
	PhysicsComponent* pc = properties->physicsComponent;

	Uint32 currentTime = timeManager->get(gameObjectID);
	Uint32 deltaTime = currentTime - pc->endTime;

	return deltaTime;
}

std::string Sprite::getFilename()
{
    return properties->graphicsComponent->filename;
}

Vector2D Sprite::getPosition()
{
	return properties->graphicsComponent->position;
}

int Sprite::getWidth()
{
	return properties->graphicsComponent->w / properties->graphicsComponent->cols;
}

int Sprite::getHeight()
{
	return properties->graphicsComponent->h / properties->graphicsComponent->rows;
}

void Sprite::setPosition(Vector2D v)
{
	properties->graphicsComponent->position = v;
}

double Sprite::getAngle()
{
	return properties->graphicsComponent->angle;
}

void Sprite::setAngle(double angle)
{
	properties->graphicsComponent->angle = angle;
}

SDL_Rect Sprite::getRect()
{
	GraphicsComponent* gc = properties->graphicsComponent;

	return SDL_Rect{ static_cast<int>(gc->position.x), static_cast<int>(gc->position.y), gc->w / gc->cols, gc->h / gc->rows };
}

bool Sprite::isVisible()
{
	return properties->graphicsComponent->visible;
}

void Sprite::setVisible(bool visible)
{
	properties->graphicsComponent->visible = visible;
}