#pragma once

#include <stack>
#include <SFML/Graphics.hpp>
#include "texture_manager.h"
class GameState;

class Game
{
public:

	std::stack<GameState*> states;

	sf::RenderWindow window;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();
	TextureManager texmgr;
	void gameLoop();

	Game();
	~Game();

private:
	void loadTextures();
};