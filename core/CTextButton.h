#pragma once

#include <string>
#include "CButton.h"

namespace CCore
{
	class CTextButton : public CButton
	{
	private:
		std::string BtnText;

	public:
		//Constructors
		CTextButton();
		CTextButton(const char*);
		CTextButton(int, int, int, int);
		CTextButton(int, int, int, int, const char*);

		//functions to set and get the button text
		void setText(const char*);
		const char* getText();
	};

	//default constructor
	CTextButton::CTextButton() : CButton()
	{
		BtnText = "";
	}

	//constructor with only text
	CTextButton::CTextButton(const char* Text) : CButton()
	{
		BtnText = Text;
	}

	//constructor with only button bounds
	CTextButton::CTextButton(int X_pos, int Y_pos, int width, int height) :
				 CButton(X_pos, Y_pos, width, height)
	{
		BtnText = "";
	}

	//constructor with all data
	CTextButton::CTextButton(int X_pos, int Y_pos, int width, int height, const char* Text) :
				 CButton(X_pos, Y_pos, width, height)
	{
		BtnText = Text;
	}

	//function to set button text. Takes CString pointer.
	void CTextButton::setText(const char* Text)
	{
		BtnText = Text;
	}

	//function to get button text. Returns pointer to CString.
	const char* CTextButton::getText()
	{
		return BtnText.c_str();
	}
}
