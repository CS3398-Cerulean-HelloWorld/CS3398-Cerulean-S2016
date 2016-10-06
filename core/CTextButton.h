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
		CTextButton();
		CTextButton(const char*);
		CTextButton(int, int, int, int, const char*);

		void setText(const char*);
		const char* getText();
	};

	CTextButton::CTextButton() : CButton()
	{
		BtnText = "";
	}

	CTextButton::CTextButton(const char* Text) : CButton()
	{
		BtnText = Text;
	}

	CTextButton::CTextButton(int X_pos, int Y_pos, int width, int height, const char* Text) :
				 CButton(X_pos, Y_pos, width, height)
	{
		BtnText = Text;
	}

	void CTextButton::setText(const char* Text)
	{
		BtnText = Text;
	}

	const char* CTextButton::getText()
	{
		return BtnText.c_str();
	}
}
