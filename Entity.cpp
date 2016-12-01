#include "Entity.h"



sf::Sprite Entity::getSprite()
{
	return this->sprite;
}

sf::Sprite const Entity::getHealthBar()
{
	return this->health.healthBarS();
}


sf::RectangleShape Entity::getHealthBarI()
{
	return this->health.innerBarS();
}

void Entity::takeDamage(int x)
{
	this->health.decHealth(x);
	std::cout << health.currentHealtha();
}

void const Entity::drawEntity(sf::RenderWindow* window)
{
	window->draw(this->getHealthBarI());
	window->draw(this->getHealthBar());
	window->draw(this->getSprite());
	//window->draw(this->getButton());
}

int Entity::getCurrentHealth()
{
	return health.currentHealtha();
}


void Entity::initHealthBar()
{
	this->health.healthBarSP()->setPosition(sprite.getGlobalBounds().width / 2, (sprite.getGlobalBounds().height + sprite.getLocalBounds().height));
	this->health.innerBarSP()->setPosition(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height + sprite.getLocalBounds().height);
	this->health.healthBarSP()->setTexture(AssetManager::GetTexture("healthBar.png"));
	this->health.innerBarSP()->setSize(sf::Vector2f(this->health.healthBarSP()->getTextureRect().width, this->health.healthBarSP()->getTextureRect().height));
	this->health.innerBarSP()->setFillColor(sf::Color::Red);
	this->health.healthBarSP()->setOrigin(this->health.healthBarSP()->getLocalBounds().width / 2, this->health.healthBarSP()->getLocalBounds().height);
	this->health.innerBarSP()->setOrigin(this->health.innerBarSP()->getLocalBounds().width / 2, this->health.innerBarSP()->getLocalBounds().height);
	this->health.healthBarSP()->setPosition(300,300);
}