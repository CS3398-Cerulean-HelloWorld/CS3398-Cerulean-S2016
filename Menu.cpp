#include "Menu.h"
#include "AnimationHandler.h"

void Menu::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);
	this->game->window.draw(this->background);
	//this->game->window.draw(button.getSprites());
	this->game->window.draw(this->text);
	//if (themesong.Stopped == themesong.getStatus())
	//{
	//	themesong.play();
	//}
	return;
}

Menu::Menu(Game* game) : button("button.png", "agasdfasdasdfasdfasdfasd", sf::Vector2f(200.f, 200.f))
{
	this->game = game;
	themesongBuffer.loadFromFile("06_Codec.ogg");
	themesong.setBuffer(themesongBuffer);
	background = sf::Sprite(AssetManager::GetTexture("SplashIdeas.png"));
	Animator animator(background);
	auto& idleAnimation = animator.CreateAnimation("Idle", "SplashIdeas.png", sf::seconds(1), true);
	idleAnimation.AddFrames(sf::Vector2i(0, 0), sf::Vector2i(150, 150), 4);
	background.scale(7.f, 7.0f);
	background.setOrigin((background.getLocalBounds().width/2)-2,(background.getLocalBounds().height/2)-30);
	font.loadFromFile("8bitlim.ttf");
	text.setString("Soul Enshrined");
	text.setCharacterSize(48);
	text.setOrigin((text.getLocalBounds().width/2), (text.getLocalBounds().height/2));
	text.setPosition((this->game->window.getSize().x/2), (this->game->window.getSize().y/2));
}

void Menu::update(const float dt)
{
}

void Menu::handleInput()
{
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		std::cout << "in loop";
		if (event.type == sf::Event::MouseButtonPressed)
		{
			std::cout << "right" << std::endl;
			if (button.checkClick((sf::Vector2f)mouse.getPosition(this->game->window)))
			{
				this->game->pushState(new SplashScreenState(this->game));
			}
		}
	}
}
