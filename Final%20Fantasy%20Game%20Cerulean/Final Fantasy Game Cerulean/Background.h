#pragma once
#include <SFML\Graphics.hpp>

class Background
{
public:
	Background();
	~Background();
	sf::Sprite getBackground();
private:
	sf::Font font;
	sf::Texture backgroundTexture;
	sf::Sprite background;

};

