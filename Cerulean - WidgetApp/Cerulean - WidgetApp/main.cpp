#include "Widget/SpeechBubble.h"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	//start sample window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Widget Test");

	//load font "Arial"
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	//load speech bubble texture
	sf::Texture texture;
	texture.loadFromFile("Speech Bubble Large.png");

	//get sprite for speech bubble
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(3, 30, 35, 52));//use smallest speech bubble
	sprite.setColor(sf::Color(255, 255, 255, 200));
	sprite.setScale(sf::Vector2f(4, 1.5));

	sprite.setPosition(-25, -8); //set sprite offset


	//create widget
	SpeechBubble bubble(sprite, "Speech-bubble", font);
	bubble.setCharacterSize(10);
	bubble.setPosition(200, 50);
	bubble.setTextColor(sf::Color(0, 0, 0, 255));

	///main window loop
	while (window.isOpen())
	{
		//check for events (exit if window is closed)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		window.clear();

		//draw the widget
		window.draw(bubble);
		
		window.display();


		//slide bubble across the screen
		float bubx = bubble.getPosition().x + 0.02;
		float buby = bubble.getPosition().y + 0.02;

		if (bubx >= window.getSize().x)
			bubx = 0.f;

		if (buby >= window.getSize().y)
			buby = 0.f;

		bubble.setPosition(sf::Vector2f(bubx, buby));
	}

	return 0;
}
