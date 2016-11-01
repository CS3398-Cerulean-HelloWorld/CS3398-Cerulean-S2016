#pragma once
#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

#include "Layout.h"
#include <SFML/Graphics/RenderTarget.hpp>

/*
Defining class for the conatiner widget, which stores other widgets using a layout.
This class can be drawn directly.
Use window->draw(Container) to do so.
*/
class Container : public Widget
{
public:
	///Public functions

	//Constructor with optional parent
	Container(Widget* parent=nullptr);

	//Destructor
	virtual ~Container();

	//Set the layout of this container
	void setLayout(Layout* layout);

	//Get this container's layout
	Layout* getLayout()const;

	//Get the size of this container
	virtual sf::Vector2f getSize()const override;

	//process events
	virtual int processEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;
	virtual void processEvents(const sf::Vector2f& parent_pos)override;

protected:
	///Protected functions

	//draw the container widget. can be overridden.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	///Private variables

	//The layout of the container
	Layout* _layout;
};


///Constructors and destructors

//Constructor with optional parent
Container::Container(Widget* parent) : Widget(parent), _layout(nullptr) {}

//Destructor. Deletes contained layout.
Container::~Container()
{
	if((_layout != nullptr) && (_layout->_parent == this))
	{
		_layout->_parent = nullptr;
		delete _layout;
	}
}


///Setters

//Set the layout of this container
void Container::setLayout(Layout* layout)
{
	//clear previous layout
	if((_layout != nullptr) && (_layout->_parent == this)) 
	{
		_layout->_parent = nullptr;
	}

	//set current layout
	if((_layout = layout) != nullptr)
	{
		_layout->_parent = this;
		_layout->updateShape();
	}
}


///Getters

//Get the layout of this container
Layout* Container::getLayout()const {return _layout;}

//Get the size of this container
sf::Vector2f Container::getSize()const
{
  sf::Vector2f res(0,0);
  if(_layout)
  res = _layout->getSize();
  return res;
}


///Drawing the widget

//draw the container widget's layout
void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  if(_layout)
  target.draw(*_layout,states);
}


///Event handling

//Process internal events, returning the children pressed
int Container::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)
{
    int result = 0;

	int child = 1;

	if (_layout)
	{
		result = _layout->processEvent(event, parent_pos);
	}
    return result;
}

//process all events
void Container::processEvents(const sf::Vector2f& parent_pos)
{
    if(_layout)
        _layout->processEvents(parent_pos);
}

#endif // CONTAINER_H_INCLUDED
