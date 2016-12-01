#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "AssetManager.h"

class Button
{
public:
	Button(std::string texture, std::string words, sf::Vector2f location);
	bool checkClick(sf::Vector2f);
	void setText(std::string);
	sf::Sprite* getSprite();
	sf::Sprite getSprites();
	sf::Text* getText();
	sf::Text getTtext();

private:
	sf::Sprite texture;
	sf::Font font;
	sf::Text String;
};
