#include "Menu.h"

void Menu::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	this->game->window.draw(text);
	//this->game->window.draw(button.getSprites());
	this->game->window.draw(button.getTtext());
	if (themesong.Stopped == themesong.getStatus())
	{
		themesong.play();
	}
	return;
}

Menu::Menu(Game* game) : button("button.png", "Press Enter", sf::Vector2f(450.f, 300.f))
{
	this->game = game;
	//themesongBuffer.loadFromFile("Sword_and_Shield_Theme.ogg");
	//themesong.setBuffer(themesongBuffer);
	background = sf::Sprite(AssetManager::GetTexture("MoonBck.png"));
	background.scale(7.f, 7.0f);
}

void Menu::update(const float dt)
{
}

void Menu::handleInput()
{
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		std::cout << "in loop" << std::endl;
		if (event.type == sf::Event::MouseButtonPressed)
		{
			std::cout << "right" << std::endl;
			if (button.checkClick((sf::Vector2f)mouse.getPosition(this->game->window)))
			{
				this->game->pushState(new SplashScreenState(this->game));
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			this->game->pushState(new SplashScreenState(this->game));
		}
	}
}


//
//
//font.loadFromFile("8bitlim.ttf");
//text.setFont(font);
//text.setString("hello");
//text.setColor(sf::Color::Cyan);
//text.setCharacterSize(30);