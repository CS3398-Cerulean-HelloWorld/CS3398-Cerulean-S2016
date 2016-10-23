#pragma once

#include <SFML\Graphics.hpp>

#include "StateManager.h"
#include "background.h"
#include "Game.h"
#include "AssetManager.h"


class SplashScreenState : public GameState
{
public:
	virtual void draw(const float dt);
	SplashScreenState(Game* game);
	virtual void handleInput();
	virtual void update(const float dt);
private:
	sf::Texture backgroundTex;
	sf::Sprite background;
};