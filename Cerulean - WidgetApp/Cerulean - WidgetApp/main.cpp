#include "Widget/VLayout.h"
#include "Widget/Container.h"
#include "Widget/TextButton.h"

#include <SFML/Graphics.hpp>

#include <iostream>

int main()
{
	//start sample window
	sf::RenderWindow window(sf::VideoMode(640, 480), "Widget Test");

	//load font "Arial"
	sf::Font font;
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

	//create widgets
	Container* container = new Container;
	VLayout* layout = new VLayout(container);

	TextButton* btn = new TextButton("Do nothing.", font, sf::Vector2f(400, 100));
	//btn->setFillColor(sf::Color::Red);
	layout->add(btn);

	btn = new TextButton("Also do nothing.", font, sf::Vector2f(400, 100));
	//btn->setFillColor(sf::Color::Green);
	layout->add(btn);

	btn = new TextButton("Close the program.", font, sf::Vector2f(400, 100));
	//btn->setFillColor(sf::Color::Blue);
	layout->add(btn);

	

	container->setLayout(layout);

	///main window loop
	while (window.isOpen())
	{
		//check for events (exit if window is closed)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//get which button was pressed
			int evt = container->processEvent(event, sf::Vector2f(0.f, 0.f));
			
		
			if (evt)
			{
				std::cout << evt << std::endl;

				if (evt & 4)
					window.close();
			}
			
		}

		window.clear();

		//draw the widget
		window.draw(*container);
		
		window.display();
	}

	return 0;
}
