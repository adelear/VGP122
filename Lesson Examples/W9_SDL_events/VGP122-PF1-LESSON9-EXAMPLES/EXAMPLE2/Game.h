#pragma once

#include <cstdlib>
#include <ctime>

#include "SDL.h"
#include "SDL_Image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "Window.h"
#include "Scene.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"

#include "GameObject.h"
#include "Image.h"
#include "Sprite.h"
#include "GameObjectBuilder.h"
#include "GameObjectDirector.h"
#include "ImageDirector.h"
#include "SpriteDirector.h"

// Forward declaration - create Window first
class Window;
class InputManager;
class SceneManager;
class ResourceManager;

template <typename T>
class GameObjectBuilder;
template <typename T>
class GameObjectDirector;

class Game
{
public:
	Game() = default;
	~Game();

	// Singleton
	static Game* getInstance();
	
	void init(std::string, int, int, int, int, bool = false);

	// Game states
	void start();
	void stop();
	void pause();
	void resume();
	void shutdown();

	bool isRunning();
	bool isPaused();

	Uint32 getStartTime();
	Uint32 getDeltaTime();

	Image* createImage(std::string goID, std::string filename, float x, float y, int w = 0, int h = 0, int rows = 1, int cols = 1);
	Sprite* createSprite(std::string goID, std::string filename, float x, float y, int w = 0, int h = 0, int rows = 1, int cols = 1);

	static SDL_Window* getWindow();
	static SDL_Renderer* getRenderer();
	static TimeManager* getTimeManager();

private:
	// Main game loop processing
	void handleEvents();
	void update();
	void render();
	void gameLoop();

	bool running;
	bool paused;

	// Initial game time and delta time
	Uint32 startTime = 0;
	Uint32 delta = 0;

	Window* window;
	InputManager* inputManager;
	SceneManager* sceneManager;
	TimeManager* timeManager;

	GameObjectBuilder<Image>* imageBuilder;
	GameObjectBuilder<Sprite>* spriteBuilder;

	static Game* instance;

	// Global frame rate
	static const float FPS;
	static const float DELAY_TIME;
};