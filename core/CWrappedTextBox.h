#pragma once

#include <SFML/Graphics.hpp>
#include "CStaticTextBox.h"

namespace CCore
{
	class CWrappedTextBox : public CStaticTextBox
	{
	private:
		sf::Text SFText;
		bool validText;

	public:
		//Constructors
		CWrappedTextBox();
		CWrappedTextBox(const char*);
		CWrappedTextBox(const char*, sf::Font);
		CWrappedTextBox(int, int, int, int);
		CWrappedTextBox(int, int, int, int, const char*, sf::Font);

		//functions to set respective text data
		void setFont(sf::Font);
		void setTextSize(int);
		void setTextColor(sf::Color);
		void setTextStyle(sf::Text);

		void setText(const char*);

		//function to draw text in text box
		void draw(sf::Window&);

	};

	//default constructor
	CWrappedTextBox::CWrappedTextBox() : CStaticTextBox()
	{
		SFText.setString("");
		validText = false;
	}

	//constructor with only text
	CWrappedTextBox::CWrappedTextBox(const char* Text) : CStaticTextBox(Text)
	{
		SFText.setString(Text);
		validText = false;
	}

	CWrappedTextBox::CWrappedTextBox(const char* Text, sf::Font) : CStaticTextBox(Text)
	{
		SFText.setString(Text);
		validText = true;
	}

	//constructor with only button bounds
	CWrappedTextBox::CWrappedTextBox(int X_pos, int Y_pos, int width, int height) :
		CStaticTextBox(X_pos, Y_pos, width, height)
	{
		SFText.setString("");
		validText = false;
	}

	//constructor with all data
	CWrappedTextBox::CWrappedTextBox(int X_pos, int Y_pos, int width, int height, const char* Text, sf::Font font) :
		CStaticTextBox(X_pos, Y_pos, width, height, Text)
	{
		SFText.setString(Text);
		SFText.setFont(font);
		SFText.setCharacterSize(12);
		SFText.setColor(sf::Color::Black);

		validText = true;
	}

	void CWrappedTextBox::setText(const char* Text)
	{
		StaticText = Text;
		SFText.setString(Text);
	}

	void CWrappedTextBox::setFont(sf::Font font)
	{
		SFText.setFont(font);

		validText = true;
	}

	void CWrappedTextBox::setTextSize(int pxSize)
	{
		SFText.setCharacterSize(pxSize);
	}

	void CWrappedTextBox::setTextStyle(sf::Text style)
	{
		SFText.setStyle(style);
	}

	void CWrappedTextBox::setTextColor(sf::Color color)
	{
		SFText.setColor(color);
	}

	void CWrappedTextBox::draw(sf::Window& window)
	{
		SFText.setPosition(X1, Y1);

		window.draw(SFText);
	}
}