#include "PlayScene.h"

PlayScene::PlayScene() : bg(nullptr), table(nullptr), hit(nullptr), stand(nullptr),
pass(nullptr), dubble(nullptr), split(nullptr), restart(nullptr),
deck(nullptr), dealer(nullptr), player(nullptr), splitHand(nullptr),
canHit(true), canSplit(false), hasSplit(false), canDoubleDown(false), gameEnded(false),
restartPressed(false) 
{

	//Initializing all my objects and variables
	bg = new Image(Game::getRenderer(), "images/bg.png", 0, 0);
	table = new Image(Game::getRenderer(), "images/table.png", 0, 0);

	hit = new Button("images/buttons.png", 0, 0, 247, 108, 1, 6);
	stand = new Button("images/buttons.png", 0, 0, 247, 108, 1, 6);
	pass = new Button("images/buttons.png", 0, 0, 247, 108, 1, 6);
	dubble = new Button("images/buttons.png", 0, 0, 247, 108, 1, 6);
	split = new Button("images/buttons.png", 0, 0, 247, 108, 1, 6);
	restart = new Button("images/restartbutton.png", 0, 0, 246, 97, 1, 1);
	deck = new Deck();
	dealer = new Hand();
	dealer->setPos(500, 5, 570, 5);
	player = new Hand();
	player->setPos(5, 5, 250, 250);
	splitHand = new Hand();
	splitHand->setPos(5, 250, 250, 250); 
	//playerScoreText = Text(renderer,"open-sans/OpenSans-Bold.tff", x_position, y_position, font_size, angle, flip);   

	splitCount = 0;

	table->position.x = (SCREEN_WIDTH / 2) - (table->w / 2);
	table->position.y = static_cast<float>(-200);

	hit->position = { 100, 490 };
	hit->setCurrentFrame(1);

	stand->position = { 247, 490 };
	stand->setCurrentFrame(2);

	pass->position = { 394, 490 };
	pass->setCurrentFrame(3);

	dubble->position = { 541, 490 };
	dubble->setCurrentFrame(4);

	split->position = { 688, 490 };
	split->setCurrentFrame(5);

	restart->position = { 450, 300 };
	restart->setCurrentFrame(1); 
}

void PlayScene::update()
{
	Scene::update();

	//std::cout << "Player Score: " << player->getTotalValue() << std::endl; 
	if (splitCount >= 1) {
		split->setVisible(false);
		split->setActive(false);
		dubble->setVisible(false);
		dubble->setActive(false);
	}

	if (hasSplit && splitCount == 0)
	{
		canSplit = false;
		split->setVisible(false);
		split->setActive(false);
		dubble->setVisible(false);
		dubble->setActive(false);
	}

	if (canSplit && splitCount == 0 && player->hasSameFaceCards()) {
		split->setVisible(true); 
		split->setActive(true);
	}
	else {
		split->setVisible(false);
		split->setActive(false); 
	}

	/*
	if (player->getTotalValue() > 21)
	{
		gameEnded = true; 
		return; 
	}
	*/ 

	// If player's hand only has 2 cards, set visibility of dubble to true
	if (player->getSizeOfHand() == 2 && splitCount==0 && ((player->getTotalValue()==9) || (player->getTotalValue()==10) || player->getTotalValue()==11))
	{
		dubble->setVisible(true);
		dubble->setActive(true);
	}

	// If player's hand has 2 cards and hasn't split yet
	if (player->getSizeOfHand() == 2 && player->hasSameFaceCards() && !hasSplit) 
	{
		// Player has two cards and hasn't split yet
		canSplit = true;
	}

	if (gameEnded)
	{
		hit->setVisible(false);
		stand->setVisible(false);
		split->setVisible(false);
		dubble->setVisible(false);
		pass->setVisible(false);
		hit->setActive(false);
		stand->setActive(false);
		split->setActive(false);
		dubble->setActive(false);
		pass->setActive(false);
		if (!restart->isVisible())
		{
			restart->setVisible(true);
			restart->setActive(true);
		}
	}
	else
	{
		hit->setVisible(true);
		hit->setActive(true);
		stand->setVisible(true);
		stand->setActive(true);
		pass->setVisible(true);
		pass->setActive(true);
		restart->setVisible(false);
		restart->setActive(false);
	}

	if (restartPressed)
		resetGame();

	if (hit->isPressed())
	{
		hit->onRelease();
		std::cout << "HIT" << std::endl;
		Hit();
	}

	if (stand->isPressed())
	{
		stand->onRelease();
		std::cout << "STAND" << std::endl;
		Stand();
	}

	if (pass->isPressed())
	{
		pass->onRelease();
		std::cout << "PASS" << std::endl;
		Pass();
	}

	if (dubble->isPressed())
	{
		dubble->onRelease();
		std::cout << "DOUBLE DOWN" << std::endl;
		DoubleDown();
	}

	if (split->isPressed())
	{
		split->onRelease();
		std::cout << "SPLIT" << std::endl;
		Split();
	}
}

void PlayScene::render()  // Render the game objects, such as player's hand, dealer's hand, etc. 
{
	Scene::render();
}

bool PlayScene::onEnter() // Set up the initial state of the game, initialize game objects, start the game, etc.
{
	gameEnded = false; 
	addGameObject(0, bg);
	addGameObject(1, table);
	addGameObject(2, hit);
	addGameObject(3, stand);
	addGameObject(4, pass);
	addGameObject(5, dubble);
	addGameObject(6, split);
 
	//TODO 
	//Add your objects
	addGameObject(7, deck); 

	Deal(); 

	addGameObject(8, restart); //Adding Restart Button   
	restart->setVisible(false); 
	restart->setActive(false); 
	dubble->setVisible(false); 
	dubble->setActive(false); 
	split->setActive(false);
	split->setVisible(false); 
	return true;

	// when all is over offer a button that if pressed reloads the scene
}

bool PlayScene::onExit()   // Clean up any resources used by the scene
{
	//CleanUp(); 
	return true;
}

void PlayScene::onKeyDown(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	if (inputManager->isKeyDown(SDL_SCANCODE_Q))
		Game::getInstance()->stop();
	else if (inputManager->isKeyDown(SDL_SCANCODE_P))
	{
		if (!Game::getInstance()->isPaused())
			Game::getInstance()->pause();
		else
			Game::getInstance()->resume();
	}
	else if (inputManager->isKeyDown(SDL_SCANCODE_R))
	{
		SceneManager::getInstance()->removeScene();
		SceneManager::getInstance()->addScene(new PlayScene());
		std::cout << "RESTART" << std::endl;
	}
} 

void PlayScene::onMouseButtonDown(SDL_Event& e) 
{  
	InputManager* inputManager = InputManager::getInstance();

	Vector2D mousePosition = inputManager->getMousePosition();

	if (mousePosition.x >= hit->position.x &&
		mousePosition.x <= hit->position.x + hit->w * SCALE_SIZE &&
		mousePosition.y >= hit->position.y &&
		mousePosition.y <= hit->position.y + hit->h * SCALE_SIZE)
		hit->onPress();
	else if (mousePosition.x >= stand->position.x &&
		mousePosition.x <= stand->position.x + stand->w * SCALE_SIZE &&
		mousePosition.y >= stand->position.y &&
		mousePosition.y <= stand->position.y + stand->h * SCALE_SIZE)
		stand->onPress();
	else if (mousePosition.x >= pass->position.x &&
		mousePosition.x <= pass->position.x + pass->w * SCALE_SIZE &&
		mousePosition.y >= pass->position.y &&
		mousePosition.y <= pass->position.y + pass->h * SCALE_SIZE)
		pass->onPress();
	else if (mousePosition.x >= dubble->position.x &&
		mousePosition.x <= dubble->position.x + dubble->w * SCALE_SIZE &&
		mousePosition.y >= dubble->position.y &&
		mousePosition.y <= dubble->position.y + dubble->h * SCALE_SIZE)
		dubble->onPress();
	else if (mousePosition.x >= split->position.x &&
		mousePosition.x <= split->position.x + split->w * SCALE_SIZE &&
		mousePosition.y >= split->position.y &&
		mousePosition.y <= split->position.y + split->h * SCALE_SIZE)
		split->onPress();
	if (!restartPressed && restart->isVisible() && mousePosition.x >= restart->position.x &&
		mousePosition.x <= restart->position.x + restart->w * SCALE_SIZE &&
		mousePosition.y >= restart->position.y &&
		mousePosition.y <= restart->position.y + restart->h * SCALE_SIZE)
	{
		restart->onPress();
	}
}  

void PlayScene::onMouseButtonUp(SDL_Event& e)
{
	InputManager* inputManager = InputManager::getInstance();

	Vector2D mousePosition = inputManager->getMousePosition();

	if (!restartPressed && restart->isVisible() && mousePosition.x >= restart->position.x &&
		mousePosition.x <= restart->position.x + restart->w * SCALE_SIZE &&
		mousePosition.y >= restart->position.y &&
		mousePosition.y <= restart->position.y + restart->h * SCALE_SIZE)
	{
		restart->onRelease();
		restartPressed = true; // Set the restartPressed flag to true
		std::cout << "Restart button pressed" << std::endl;
	} 
}


void PlayScene::onMouseMove(SDL_Event& e)
{

}

void PlayScene::Deal() {
	player->getCardFromDeck(deck); 
	dealer->getCardFromDeck(deck); 
}

void PlayScene::Hit()
{
	if (!hasSplit || splitHand->getSizeOfHand() == 0) {
		// Player's turn for the player hand
		player->getCardFromDeck(deck);
		std::cout << "Player Score: " << player->getTotalValue() << std::endl;
		if (player->getTotalValue() > 21) {
			std::cout << "Player busts on the player hand!" << std::endl;
			if (hasSplit && splitHand->getSizeOfHand() > 0) {
				std::cout << "Switching to player hand..." << std::endl;
				hasSplit = false; // Move back to player hand
				return;
			}
			else {
				gameEnded = true;
				return;
			}
		}
	}
	else {
		// Player's turn for the split hand
		splitHand->getCardFromDeck(deck);
		std::cout << "Split Hand Score: " << splitHand->getTotalValue() << std::endl;
		if (splitHand->getTotalValue() > 21) {
			std::cout << "Split hand busts!" << std::endl;
			std::cout << "Switching to player hand..." << std::endl;
			hasSplit = false; // Move back to player hand
			return;
		}
	}
}


void PlayScene::Split()
{
	if (player->hasSameFaceCards() && canSplit)
	{
		// Move the first card from the player's hand to the split hand
		player->moveCard(splitHand, 0); 
		
		// Get new cards for both hands from the deck
		std::cout << "Player has split!" << std::endl; 
		player->getCardFromDeck(deck); 
		splitHand->getCardFromDeck(deck); 

		// Disable further splitting
		splitCount++; 
		canSplit = false;
		hasSplit = true; 
	}
} 

void PlayScene::DoubleDown() {
	//Bet is supposed to be doubled? 
	player->getCardFromDeck(deck); 
	Stand(); 
}

void PlayScene::Pass() {
	//ends game taking half the player's bet
	resetGame(); 
}

void PlayScene::Stand()
{
	if (hasSplit && splitHand->getSizeOfHand() > 0) {
		// Player stands on the split hand
		std::cout << "Player stands on the split hand" << std::endl;
		hasSplit = false; // Set hasSplit to false
		return;
	}

	// Player stands on the player hand
	std::cout << "Player stands on the player hand" << std::endl;
	std::cout << "Player Score: " << player->getTotalValue() << std::endl; 
	
	// Check if the player has a split hand
	if (hasSplit && splitHand->getSizeOfHand() > 0) {
		// Switch to the split hand
		std::cout << "Switching to split hand..." << std::endl;
		hasSplit = false; // Set hasSplit to false
		return;
	}

	// Perform the dealer's turn
	DealerTurn();

	// Check for a win condition
	int result = WinCondition();
	if (result == 1) {
		// Player wins
		std::cout << "Player wins!" << std::endl;
	}
	else if (result == -1) {
		// Player loses
		std::cout << "Player loses!" << std::endl;
	}
	else {
		// Tie
		std::cout << "It's a tie!" << std::endl;
	}

	gameEnded = true;
} 


int PlayScene::WinCondition() {
	int playerHandResult = 0;
	int splitHandResult = 0;

	// Check win condition for player's hand
	if (player->getTotalValue() < 22) {
		if ((player->getTotalValue() > dealer->getTotalValue()) || (dealer->getTotalValue() > 21)) {
			playerHandResult = 1; // PLAYER WIN
		}
		else if (player->getTotalValue() < dealer->getTotalValue()) {
			playerHandResult = -1; // PLAYER LOSS
		}
		else {
			playerHandResult = 0; // TIE
		}
	}
	else {
		playerHandResult = -1; // Player Loses
	}

	// Check win condition for split hand (if applicable)
	if (hasSplit) {
		if (splitHand->getTotalValue() < 22) {
			if ((splitHand->getTotalValue() > dealer->getTotalValue()) && (dealer->getTotalValue() <= 21)) {
				splitHandResult = 1; // PLAYER'S SPLIT HAND WINS
			}
			else if (splitHand->getTotalValue() < dealer->getTotalValue()) {
				splitHandResult = -1; // PLAYER'S SPLIT LOSS
			}
			else {
				splitHandResult = 0; // TIE
			}
		}
		else {
			splitHandResult = -1; // Player Loses
		}
	}
	
	if (hasSplit) {
		if (playerHandResult == 1 && splitHandResult == 1) {
			return 1; // Player Wins (Both hands win)
		}
		else if (playerHandResult == 1 && splitHandResult != -1) {
			return 1; // Player Wins (Only player's hand wins, split hand not applicable)
		}
		else if (playerHandResult != -1 && splitHandResult == 1) {
			return 1; // Player Wins (Only split hand wins, player's hand not applicable)
		}
		else if (playerHandResult == -1 && splitHandResult == -1) {
			return -1; // Player Loses (Both hands lose)
		}
		else {
			return 0; // TIE (No winning hands)
		}
	}
	else {
		if (playerHandResult == 1) return 1;
		if (playerHandResult == 0) return 0;
		if (playerHandResult == -1) return -1; 
	}
	// Determine the overall win condition
	
}


 

void PlayScene::DealerTurn()
{
	std::cout << "Dealer's turn" << std::endl;

	while (dealer->getTotalValue() < 17)
	{
		std::cout << "Dealer Hit!" << std::endl; 
		dealer->getCardFromDeck(deck);
	}

	std::cout << "Dealer's total value: " << dealer->getTotalValue() << std::endl;
}


void PlayScene::resetGame()
{
	SceneManager::getInstance()->removeScene();
	SceneManager::getInstance()->addScene(new PlayScene());
	std::cout << "RESTART" << std::endl; 
} 

PlayScene::~PlayScene()
{
	//CleanUp(); // Clean up resources used by the current scene
	delete bg;
	delete table;
	delete hit;
	delete stand;
	delete pass;
	delete dubble;
	delete split;
	delete restart;
	delete deck;
	delete dealer;
	delete player;
	delete splitHand; 
	std::cout << "Deleting..." << std::endl; 
}
 