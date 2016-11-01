#pragma once
#ifndef TEXTBUTTON_H_INCLUDED
#define TEXTBUTTON_H_INCLUDED

#include "Button.h"
#include "Label.h"
#include <SFML/Graphics/RectangleShape.hpp>

/*
Defining class for text button widgets.
This class can be drawn directly.
Use window->draw(TextButton) to do so.

This also assumes buttons don't have sprites,
and draws a rectangle around the button.
*/
class TextButton : public Button
{
public:
	///Public functions

	//Constructor (a text button requires text and a font, and optionally a parent)
	TextButton(const std::string& text, const sf::Font& font, 
			   const sf::Vector2f& size = sf::Vector2f(0,0), Widget* parent=nullptr);

	//Destructor
	virtual ~TextButton();

	//Set the button's text
	void setText(const std::string& text);

	//Set the text character size
	void setCharacterSize(unsigned int size);

	//Set the color of the text
	void setTextColor(const sf::Color& color);

	//Set the button fill color
	void setFillColor(const sf::Color& color);

	//Set the button outline color
	void setOutlineColor(const sf::Color& color);

	//Set the thickness of the button outline
	void setOutlineThickness(float thickness);

	//Get the size of the button as an sf::Vector2f object
	virtual sf::Vector2f getSize()const override;

	//Set the button size (no less than text size)
	void setMinSize(const sf::Vector2f& size);

protected:
	///Protected variables

	//Button minimum size
	sf::Vector2f _buttonSize;

private:
	///Private functions

	//update the shape.
	void updateShape()override;

	//draw the text button widget. can be overridden.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	//Mouse behavior functions.
	virtual void onMouseEntered()override;
	virtual void onMouseLeft()override;

	///Private variables

	//Button rectangle
	sf::RectangleShape _shape;

	//Button text
	Label _label;
	
	//Button rectangle fill color
	sf::Color _fillColor;

	//Button rectangle outline color
	sf::Color _outlineColor;
};


///Constructors and destructors

//Constructor. Sets button text and font, and parent if given.
TextButton::TextButton(const std::string& text, const sf::Font& font, const sf::Vector2f& size, Widget* parent) :
	Button(parent), _label(text, font, this), _buttonSize(size)
{
	setFillColor(sf::Color(86,20,19));
	setOutlineThickness(5);
	setOutlineColor(sf::Color(146,20,19));
}

//Destructor
TextButton::~TextButton() {}


///Setters

//Set the button text
void TextButton::setText(const std::string& text) {_label.setText(text);}

//Set the button text's point size 
void TextButton::setCharacterSize(unsigned int size) {_label.setCharacterSize(size);}

//Set the color of the button's text
void TextButton::setTextColor(const sf::Color& color) {_label.setTextColor(color);}

//Set the button fill color
void TextButton::setFillColor(const sf::Color& color)
{
  _fillColor = color;
  _shape.setFillColor(_fillColor);
}

//Set the button outline color
void TextButton::setOutlineColor(const sf::Color& color)
{
  _outlineColor = color;
  _shape.setOutlineColor(_outlineColor);
}

//Set the button outline thickness
void TextButton::setOutlineThickness(float thickness) {_shape.setOutlineThickness(thickness);}

void TextButton::setMinSize(const sf::Vector2f& size) 
{
	_buttonSize.x = size.x;
	_buttonSize.y = size.y;
}

///Getters

//Get the size of the button as an sf::Vector2f object
sf::Vector2f TextButton::getSize()const
{
  sf::FloatRect rect = _shape.getGlobalBounds();
  return sf::Vector2f(rect.width,rect.height);
}


///Drawing the widget

//Update the widget shape, and all parent widgets.
void TextButton::updateShape()
{
  sf::Vector2f label_size = _label.getSize();
  unsigned int char_size = _label.getCharacterSize();

  //scale the button according to the size of the text
  float x = char_size * 2 + label_size.x;
  float y = char_size * 2 + label_size.y;

  //but not smaller than our minimum size.
  if (y < _buttonSize.y)
	  y = _buttonSize.y;
  if (x < _buttonSize.x)
	  x = _buttonSize.x;

  _shape.setSize(sf::Vector2f(x, y));

  //put the text in the center of the button
  _label.setPosition((float)char_size, (float)char_size);

  Widget::updateShape();
}

//Draw the text button widget
void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform.translate(_position);
  target.draw(_shape,states);
  target.draw(_label,states);
}


///Button behavior

//when the mouse is hovering over the button, highlight it.
void TextButton::onMouseEntered()
{
  const float light = 1.4f;
  _shape.setOutlineColor(sf::Color((sf::Uint8)(_outlineColor.r*light),
								   (sf::Uint8)(_outlineColor.g*light),
								   (sf::Uint8)(_outlineColor.b*light)));
  _shape.setFillColor(sf::Color((sf::Uint8)(_fillColor.r*light),
								(sf::Uint8)(_fillColor.b*light),
								(sf::Uint8)(_fillColor.b*light)));
}

//when the mouse is not over the button, de-highlight it.
void TextButton::onMouseLeft()
{
  _shape.setOutlineColor(_outlineColor);
  _shape.setFillColor(_fillColor);
}


#endif // TEXTBUTTON_H_INCLUDED
