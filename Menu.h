#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "StateManager.h"
#include "Game.h"
#include "AssetManager.h"
#include "button.h"
#include <string>
#include "Splash.h"
#include <iostream>

class Menu : public GameState
{
public:
	Menu(Game* game);
	virtual void draw(const float dt);
	virtual void handleInput();
	virtual void update(const float dt);
private:
	sf::Sprite background;
	sf::SoundBuffer themesongBuffer;
	sf::Sound themesong;
	sf::Mouse mouse;
	sf::Font font;
	sf::Text text;
	Button button;
};