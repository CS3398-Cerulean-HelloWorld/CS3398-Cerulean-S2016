#include "Widget/ActionTarget.h"

#include <SFML/Graphics.hpp>

int main()
{
	//start sample window
	sf::RenderWindow window(sf::VideoMode(200, 200), "Widget Test");

	//load font "Arial"
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	//create widget
	//TextButton btn ("BUTTON", font);

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
		//window.draw(btn);
		
		window.display();
	}

	return 0;
}
