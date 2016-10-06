#pragma once

#include <string>
#include "CBoundsBox.h"

namespace CCore
{
	class CStaticTextBox : public CBoundsBox
	{
	private:
		std::string StaticText;

	public:
		//Constructors
		CStaticTextBox();
		CStaticTextBox(const char*);
		CStaticTextBox(int, int, int, int);
		CStaticTextBox(int, int, int, int, const char*);

		//functions to set and get the raw box text
		void setText(const char*);
		const char* getText();
	};

	//default constructor
	CStaticTextBox::CStaticTextBox() : CBoundsBox()
	{
		StaticText = "";
	}

	//constructor with only text
	CStaticTextBox::CStaticTextBox(const char* Text) : CBoundsBox()
	{
		StaticText = Text;
	}

	//constructor with only button bounds
	CStaticTextBox::CStaticTextBox(int X_pos, int Y_pos, int width, int height) :
					CBoundsBox(X_pos, Y_pos, width, height)
	{
		StaticText = "";
	}

	//constructor with all data
	CStaticTextBox::CStaticTextBox(int X_pos, int Y_pos, int width, int height, const char* Text) :
		CBoundsBox(X_pos, Y_pos, width, height)
	{
		StaticText = Text;
	}

	//function to set box text. Takes CString pointer.
	void CStaticTextBox::setText(const char* Text)
	{
		StaticText = Text;
	}

	//function to get box text. Returns pointer to CString.
	const char* CStaticTextBox::getText()
	{
		return StaticText.c_str();
	}
}
