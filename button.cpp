#include "button.h"
#include <iostream>

Button::Button(std::string texture, std::string words, sf::Vector2f location) : texture(AssetManager::GetTexture(texture)){
	this->texture.setPosition(location);
	String.setString(words);
	String.setPosition(location.x + (this->texture.getLocalBounds().width/8), location.y + (this->texture.getLocalBounds().height/4));
	String.setCharacterSize(30);
	font.loadFromFile("8bitlim.ttf");
	String.setFont(font);
}

bool Button::checkClick(sf::Vector2f mousePos) 
{
	return this->getSprite()->getGlobalBounds().contains(mousePos);
}

sf::Sprite* Button::getSprite() {
	return &this->texture;
}

sf::Sprite Button::getSprites()
{
	return this->texture;
}

sf::Text * Button::getText() {
	return &String;
}

sf::Text Button::getTtext()
{
	return String;
}