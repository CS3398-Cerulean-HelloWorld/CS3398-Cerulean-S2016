#include "Background.h"
#include "AssetManager.h"
#include <SFML\Graphics.hpp>
#include <iostream>

Background::Background()
{
	if (!font.loadFromFile("manaspc.ttf"))
	{
		std::cout << "The specified file was not loaded!" << std::endl;
	}

	//if (!backgroundTexture.loadFromFile("background1.png"))
	//{
		//std::cout << "The specified file was not loaded!" << std::endl;
	//}

	background = sf::Sprite(AssetManager::GetTexture("background1.png"));

	//background.setTexture(backgroundTexture);
	background.setPosition(0,0);
}

Background::~Background()
{
}

sf::Sprite Background::getBackground()
{
	return sf::Sprite(background);
}

