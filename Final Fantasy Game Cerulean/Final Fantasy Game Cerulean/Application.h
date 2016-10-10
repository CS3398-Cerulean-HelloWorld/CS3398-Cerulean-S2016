#pragma once
#include <SFML\Graphics.hpp>
class Application
{
public:
	Application();
	~Application();
	void run();
	sf::RenderWindow appWindow;
	sf::Sprite backdrop;
private:
	void processInput();
	void update();
	void render();

};

