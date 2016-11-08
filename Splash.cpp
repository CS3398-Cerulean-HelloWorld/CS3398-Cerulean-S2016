#include "Splash.h"

void SplashScreenState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	this->game->window.draw(button.getSprites());
	this->game->window.draw(button.getTtext());
	if(themesong.Stopped == themesong.getStatus())
	{
			themesong.play();
	}
	return;
}

SplashScreenState::SplashScreenState(Game* game) : button("button.png", "Hello", sf::Vector2f(200.f, 200.f))
{	
	this->game = game;
	themesongBuffer.loadFromFile("06_Codec.ogg");
	themesong.setBuffer(themesongBuffer);
	background = sf::Sprite(AssetManager::GetTexture("Splash.png"));
	background.scale(4.8f, 4.0f);
}

void SplashScreenState::update(const float dt)
{

}

void SplashScreenState::handleInput()
{
	sf::Event event;
	while(this->game->window.pollEvent(event))
	{
		std::cout << "in loop 2";
		if (event.type == sf::Event::MouseButtonPressed)
		{
			std::cout << "right" <<std::endl;
			if (button.checkClick((sf::Vector2f)mouse.getPosition(this->game->window)))
			{
				std::cout << "eyyyyy" << std::endl;
			}
		}
	}
}