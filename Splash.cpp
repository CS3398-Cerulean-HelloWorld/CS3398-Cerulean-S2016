#include "Splash.h"
#include "AnimationHandler.h"

void SplashScreenState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	lol.drawEntity(&this->game->window);
	if(themesong.Stopped == themesong.getStatus())
	{
			themesong.play();
	}
	return;
}

SplashScreenState::SplashScreenState(Game* game) : lol(100, "bloodTemplarLord.png") 
{
	this->game = game;
	themesongBuffer.loadFromFile("No.ogg");
	themesong.setBuffer(themesongBuffer);
	background = sf::Sprite(AssetManager::GetTexture("background.png"));
	background.scale(2.0f, 2.0f);
}

void SplashScreenState::update(const float dt)
{
	
}

void SplashScreenState::handleInput()
{
	sf::Event event;
	while(this->game->window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			
		}
	}
}