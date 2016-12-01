#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "StateManager.h"
#include "Game.h"
#include "AssetManager.h"
#include "button.h"
#include <string>
#include <iostream>
#include "Entity.h"

class SplashScreenState : public GameState
{
public:
	virtual void draw(const float dt);
	SplashScreenState(Game* game);
	virtual void handleInput();
	virtual void update(const float dt);
private:
	sf::Sprite background;
	sf::SoundBuffer themesongBuffer;
	sf::Sound themesong;
	sf::Clock clock;
	sf::Mouse mouse;
	Entity lol;
};