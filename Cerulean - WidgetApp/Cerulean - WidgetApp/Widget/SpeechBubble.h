#pragma once
#ifndef SPEECHBUBBLE_H_INCLUDED
#define SPEECHBUBBLE_H_INCLUDED

#include "Label.h"
#include <SFML/Graphics.hpp>

/*
Class for speech bubble widgets.
This class can be drawn directly.
Use window->draw(SpeechBubble) to do so.
*/
class SpeechBubble : public Label
{
public:
	///Public functions:

	//Constructor (a label requires text and a font, and optionally a parent)
	SpeechBubble(const sf::Sprite& sprite, const std::string& text, const sf::Font& font, Widget* parent = nullptr);

	//Destructor
	virtual ~SpeechBubble() {}

	//Get widget size. Overrides base Widget class and can be overridden.
	virtual sf::Vector2f getSize()const override;

private:
	///Private functions:

	//draw the label widget, can be overridden.
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	///Private variables:

	//Text the label widget contains
	sf::Sprite _sprite;
};


///Constructors and destructors

//Constructor. Sets sprite, label text and font, and parent if given.
SpeechBubble::SpeechBubble(const sf::Sprite& sprite, const std::string& text, const sf::Font& font, Widget* parent) : 
	Label(text, font, parent)
{
	_sprite = sprite;

	//.setScale(10);

	//if (Label::getSize)
}



//Get widget size from sprite. Overrides base Widget class and can be overridden.
sf::Vector2f SpeechBubble::getSize()const
{
	sf::FloatRect rect = _sprite.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}


///Drawing the widget

//draw the Speech Bubble widget, can be overridden.
void SpeechBubble::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.translate(_position);

	target.draw(_sprite, states);
	
	target.draw(_text, states);
}

#endif // SPEECHBUBBLE_H_INCLUDED