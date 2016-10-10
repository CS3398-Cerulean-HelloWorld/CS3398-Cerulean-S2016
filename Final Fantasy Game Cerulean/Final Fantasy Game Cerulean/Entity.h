#pragma once
#include "Application.h"
#include "AssetManager.h"
#include <SFML\Graphics.hpp>
#include <SFML\System\Vector2.hpp>
class Entity : public sf::Sprite
{
public:
	Entity();
	~Entity();
private:
	sf::Vector2f spawnpoint;
	int health;
};

