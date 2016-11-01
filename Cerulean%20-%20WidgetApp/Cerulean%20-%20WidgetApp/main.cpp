#include "Widget/Label.h"

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Widget Test");

	sf::Font font;

	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	Label label("LABEL1", font);
	label.setCharacterSize(12);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(label);
		window.display();

		label.setPosition(label.getPosition().x + 0.05, label.getPosition().y + 0.05);
	}

	return 0;
}
