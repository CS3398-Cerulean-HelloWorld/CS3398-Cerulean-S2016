#pragma once

#include "CBoundsBox.h"

namespace CCore
{
	class CButton : public CBoundsBox
	{
	public:
		//Constructors
		CButton();
		CButton(int, int, int, int);

		//function to return whether a point is within the button bounds
		//(use this when determining if the user pressed a button)
		bool pointIsInBounds(int, int);
	};

	//default constructor
	CButton::CButton() : CBoundsBox() {}

	//constructor with full data
	CButton::CButton(int X_pos, int Y_pos, int width, int height) :
			 CBoundsBox(X_pos, Y_pos, width, height) {}

	//function to return whether a point is within the button bounds
	//(use this when determining if the user pressed a button)
	bool CButton::pointIsInBounds(int X, int Y)
	{
		if ((X >= X1) && (X <= X2) &&
			(Y >= Y1) && (Y <= Y2))
			return true;
		else
			return false;
	}
}
