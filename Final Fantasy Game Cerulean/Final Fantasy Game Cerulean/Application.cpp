#include "Application.h"
#include "Background.h"
#include<SFML\Graphics.hpp>

#include <iostream>


Application::Application()

	:appWindow(sf::VideoMode(800, 600), "Game Application Window")
{
}

Application::~Application()
{
}

void Application::run()
{
	while (appWindow.isOpen())
	{
		processInput();
		Background background;
		backdrop = background.getBackground();
		update();
		render();
	}
}

void Application::processInput()
{
	sf::Event event;
	while (appWindow.pollEvent(event))
	{
		if ((event.type == sf::Event::EventType::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
		{
			appWindow.close();
		}
	}
}

void Application::update()
{
}

void Application::render()
{
	appWindow.clear();
	appWindow.draw(backdrop);
	appWindow.display();
}
