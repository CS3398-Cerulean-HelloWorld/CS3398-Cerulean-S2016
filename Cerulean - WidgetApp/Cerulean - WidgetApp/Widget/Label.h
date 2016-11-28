#pragma once
#ifndef LABEL_H_INCLUDED
#define LABEL_H_INCLUDED

#include "Widget.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

/*
Defining class for Label widgets.
This class can be drawn directly.
Use window->draw(Label) to do so.
*/
class Label : public Widget
{
public:
	///Public functions:

	//Constructor (a label requires text and a font, and optionally a parent)
	Label(const std::string& text, const sf::Font& font, Widget* parent=nullptr);

	//Destructor
	virtual ~Label();

	//Set the label's text
	void setText(const std::string& text);

	//Set the text character size
	void setCharacterSize(unsigned int size);

	//Get the text character size
	unsigned int getCharacterSize()const;

	//Set the text color
	void setTextColor(const sf::Color& color);

	//Get widget size. Overrides base Widget class and can be overridden.
	virtual sf::Vector2f getSize()const override;

private:
	///Private functions:

	//draw the label widget, can be overridden.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

protected:
	///Protected variables:

	//Text the label widget contains
	sf::Text _text;
};


///Constructors and destructors

//Constructor. Sets label text and font, and parent if given.
Label::Label(const std::string& text, const sf::Font& font, Widget* parent) : Widget(parent)
{
  _text.setFont(font);
  setText(text);
  setTextColor(sf::Color(180,93,23));
}


//Destructor. 
Label::~Label() {}


///Setters

//Set the label's text
void Label::setText(const std::string& text)
{
    _text.setString(text);
  updateShape();
}

//Set the text character size
void Label::setCharacterSize(unsigned int size)
{
  _text.setCharacterSize(size);
  updateShape();
}

//Set the text color
void Label::setTextColor(const sf::Color& color) { _text.setFillColor(color); }


///Getters

//Get the text character size
unsigned int Label::getCharacterSize()const {return _text.getCharacterSize();}

//Get widget size from text. Overrides base Widget class and can be overridden.
sf::Vector2f Label::getSize()const
{
  sf::FloatRect rect = _text.getGlobalBounds();
  return sf::Vector2f(rect.width,rect.height);
}


///Drawing the widget

//draw the label widget, can be overridden.
void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform.translate(_position);
  target.draw(_text,states);
}

#endif // LABEL_H_INCLUDED
