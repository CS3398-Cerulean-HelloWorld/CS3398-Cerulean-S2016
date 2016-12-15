#pragma once
#include <SFML\Graphics.hpp>
#include "AssetManager.h"
#include "button.h"

class Health
{
public:
	Health(int startHealth)
		: maxHealth(startHealth)
	{
		//this->innerBar.setSize(sf::Vector2f(this->healthBar.getTextureRect().width, this->healthBar.getTextureRect().height));
		//this->innerBar.setFillColor(sf::Color::Red);
		//this->healthBar.setTexture(AssetManager::GetTexture("healthBar.png"));
		//this->healthBar.setOrigin(healthBar.getLocalBounds().width/2, healthBar.getLocalBounds().height);
		//this->innerBar.setOrigin(innerBar.getLocalBounds().width / 2, innerBar.getLocalBounds().height);
	}
	void incHealth(int inc);
	void decHealth(int dec);
	void setHealth(int x);
	int currentHealtha();
	sf::Sprite const healthBarS();
	sf::RectangleShape const innerBarS();
	sf::Sprite* const healthBarSP();
	sf::RectangleShape* const innerBarSP();
private:
	int currentHealth;
	int maxHealth;
	float currentHBscale;
	sf::Sprite healthBar;
	sf::RectangleShape innerBar;
};