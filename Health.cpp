#include "Health.h"


void Health::incHealth(int inc)
{
	currentHealth += inc;
	currentHBscale = (currentHealth / maxHealth);
	this->innerBarSP()->setScale(this->currentHBscale, 1.f);
}
void Health::decHealth(int dec)
{
	currentHealth -= dec;
	currentHBscale = (currentHealth / maxHealth);
	this->innerBarSP()->setScale(this->currentHBscale, 1.f);
}
sf::Sprite const Health::healthBarS()
{
	return this->healthBar;
}

sf::RectangleShape const Health::innerBarS()
{
	return this->innerBar;
}


sf::Sprite* const Health::healthBarSP()
{
	sf::Sprite* lol = &this->healthBar;
	return lol;
}

sf::RectangleShape* const Health::innerBarSP()
{
	sf::RectangleShape* lol = &this->innerBar;
	return lol;
}

int Health::currentHealtha()
{ 
	return this->currentHealth;
}

void Health::setHealth(int x)
{
	this->currentHealth = x;
}