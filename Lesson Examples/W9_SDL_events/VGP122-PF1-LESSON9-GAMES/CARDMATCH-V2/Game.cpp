#include "Game.h"

// Shutdown game
Game::~Game()
{	
	SceneManager::removeInstance();
	ResourceManager::removeInstance();
	InputManager::removeInstance();
	TimeManager::removeInstance();
	Window::removeInstance();

	SDL_Quit();
}

Game* Game::getInstance()
{
	if (instance == nullptr)
		instance = new Game();

	return instance;
}

// Initialize game
void Game::init(std::string title, int x, int y, int w, int h, bool flags)
{
	srand(static_cast<unsigned>(time(0)));

	paused = false;

	window = Window::getInstance(title, x, y, w, h, flags);
	inputManager = InputManager::getInstance();
	sceneManager = SceneManager::getInstance();
	timeManager = TimeManager::getInstance();

	running = timeManager->addTimer("game", true);
}

// Update events
void Game::handleEvents()
{
	inputManager->handleEvents();
}

// Update game logic
void Game::update()
{
	if(!isPaused())
		window->update();
}

// Render to screen
void Game::render()
{
	if (!isPaused())
		window->render();
}

// Start game and main game loop
void Game::start()
{
	paused = false;
	running = timeManager->start("game");

	gameLoop();
}

// Stop main game loop
void Game::stop()
{
	running = !timeManager->remove("game");
}

// Pause main game loop
void Game::pause()
{
	paused = timeManager->pause("game");
}

// Resume game loop from pause
void Game::resume()
{
	paused = !timeManager->resume("game");;
}

void Game::shutdown()
{
	if(isRunning())
		stop();

	if (instance != nullptr)
		delete instance;
}

void Game::gameLoop()
{
	while (isRunning())
	{
		startTime = getTimeManager()->get("game");

		handleEvents();
		update();
		render();

		delta = getTimeManager()->get("game") - startTime;

		if (delta < DELAY_TIME)
			SDL_Delay((DELAY_TIME - delta));
	}
}

bool Game::isRunning()
{
	return running;
}

bool Game::isPaused()
{
	return paused;
}

SDL_Window* Game::getWindow()
{
	return Window::getWindow();
}

SDL_Renderer* Game::getRenderer()
{
	return Window::renderer;
}

TimeManager* Game::getTimeManager()
{
	return TimeManager::getInstance();
}

Uint32 Game::getStartTime()
{
	return startTime;
}

Uint32 Game::getDeltaTime()
{
	return delta;
}

// Set frame rate
const float Game::FPS = 60.0f;
const float Game::DELAY_TIME = 1000.0f / FPS;

Game* Game::instance = nullptr;