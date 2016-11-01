#pragma once
#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>


/*
Base class for all widgets. 
This class cannot be drawn directly.
Another inherited class must be created with a draw() function.
*/
class Widget : public sf::Drawable
{
public:
	///Public functions:

	//constructor
	Widget(Widget* parent=nullptr);
  
	//destructor which will be overridden
	virtual ~Widget();

	//setting positions
	void setPosition(const sf::Vector2f& pos);
	void setPosition(float x,float y);

	//get position
	const sf::Vector2f& getPosition()const;

	//get size, which will  be overridden
	virtual sf::Vector2f getSize()const = 0;

protected:
	///Protected functions:

	//event processing, will be overridden
	virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos);
	virtual void processEvents(const sf::Vector2f& parent_pos);

	//update the shape, will be overridden
	virtual void updateShape();

	///Protected variables:

	//parent widget
	Widget* _parent;

	//position of this widget
	sf::Vector2f _position;
};

///Constructors and destructors

//constructor. Sets parent if given, otherwise no parent.
Widget::Widget(Widget* parent) : _parent(parent){}

//default empty destructor
Widget::~Widget(){}


///Setters

//Set the widget position, given a position of type sf::Vector2f
void Widget::setPosition(const sf::Vector2f& pos) {_position = pos;}

//Set the widget position, given a position x and y value.
void Widget::setPosition(float x,float y)
{
  _position.x = x;
  _position.y = y;
}


///Getters

//Return the widget's position as type sf::Vector2f
const sf::Vector2f& Widget::getPosition()const {return _position;}


///Event processing

//process a single event. Default function return false, will be overridden.
bool Widget::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos) {return false;}

//process all events for this widget.
void Widget::processEvents(const sf::Vector2f& parent_pos) {}


//Update the widget shape, and all parent widgets.
void Widget::updateShape()
{
  if(_parent)
  _parent->updateShape();
}

#endif // WIDGET_H_INCLUDED
