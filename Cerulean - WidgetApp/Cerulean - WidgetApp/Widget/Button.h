#pragma once
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Widget.h"
#include <functional>

/*
Base class for button widgets.
This class cannot be drawn directly.
Another inherited class must be created with a draw() function.
*/
class Button : public Widget
{
public:
	///Public functions:

	//Constructor
	Button(Widget* parent = nullptr);

	//Destructor
	virtual ~Button();

	//Constructor (a label requires text and a font, and optionally a parent)
	using FuncType = std::function<void(const sf::Event& event, Button& self)>;
	static FuncType defaultFunc;

	//Function that decides what the button does when pressed
	FuncType onClick;

protected:
	///Protected functions

	//process events. Checks if mouse is pressed.
	virtual bool processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;

	//Default mouse behavior functions. Meant to be overridden.
	virtual void onMouseEntered();
	virtual void onMouseLeft();

private:
	///Private variables

	//Status enumeration
	enum Status { None = 0, Hover = 1 };

	//Current button status
	int _status;
};


///Constructors and destructors

//Constructor. Sets parent if given, as well as default onClick function and button status
Button::Button(Widget* parent) : Widget(parent), onClick(defaultFunc), _status(Status::None) {}

//Destructor.
Button::~Button() {}


///Button functionality

//Default mouse behavior functions
void Button::onMouseEntered() {}
void Button::onMouseLeft() {}

//Default empty callback function 
Button::FuncType Button::defaultFunc = [](const sf::Event&, Button&)->void {};

//Function to process events. Returns true if the button has been pressed.
bool Button::processEvent(const sf::Event& event, const
	sf::Vector2f& parent_pos)
{
	bool pressed = false;

	//if mouse button is released,
	if (event.type == sf::Event::MouseButtonReleased)
	{
		const sf::Vector2f pos = _position + parent_pos;
		const sf::Vector2f size = getSize();

		sf::FloatRect rect;
		rect.left = pos.x;
		rect.top = pos.y;
		rect.width = size.x;
		rect.height = size.y;

		//check if the mouse was within the button bounds
		if (rect.contains((float)event.mouseButton.x, (float)event.mouseButton.y))
		{
			//If so, the button was clicked.
			onClick(event, *this);
			pressed = true;
		}
	}
	//check if the mouse is in button bounds
	else if (event.type == sf::Event::MouseMoved)
	{
		const sf::Vector2f pos = _position + parent_pos;
		const sf::Vector2f size = getSize();

		sf::FloatRect rect;
		rect.left = pos.x;
		rect.top = pos.y;
		rect.width = size.x;
		rect.height = size.y;

		int old_status = _status;
		_status = Status::None;

		const sf::Vector2f mouse_pos((float)event.mouseMove.x, (float)event.mouseMove.y);

		//if the mouse is within the button bounds, it's hovering over the button
		if (rect.contains(mouse_pos))
			_status = Status::Hover;

		//if the mouse is no longer hovering over the button
		if ((old_status & Status::Hover) && !(_status & Status::Hover))
			onMouseLeft();
		//if the mouse just now moved over the button
		else if (!(old_status & Status::Hover) && (_status & Status::Hover))
			onMouseEntered();
	}

	//return whether the button was pressed
	return pressed;
}

#endif // BUTTON_H_INCLUDED
