
#include "Splash.h"

void SplashScreenState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	return;
}

SplashScreenState::SplashScreenState(Game* game)
{
	this->game = game;
	background = sf::Sprite(AssetManager::GetTexture("background1.png"));
}

void SplashScreenState::update(const float dt)
{
}

void SplashScreenState::handleInput()
{

}