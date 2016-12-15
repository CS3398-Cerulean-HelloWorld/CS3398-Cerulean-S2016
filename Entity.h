#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "health.h"
#include "AssetManager.h"
#include "animation_handler.h"
#include <iostream>

class Entity
{
public:
	AnimationHandler animHandler;
	sf::Sprite getSprite();
	sf::Sprite const getHealthBar();
	sf::RectangleShape getHealthBarI();
	int getCurrentHealth();
	void initHealthBar();
	void takeDamage(int x);
	void const drawEntity(sf::RenderWindow* window);
	Entity(int health, std::string tex) 
		: health(health)
	{
		initHealthBar();
		this->sprite.setTexture(AssetManager::GetTexture(tex));
	}
private:
	sf::Sprite sprite;
	Health health;
};