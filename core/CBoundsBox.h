#pragma once

#define getX(var) getX1(var)
#define getY(var) getY1(var)

namespace CCore
{
	class CBoundsBox
	{
	private:
		int X1;
		int Y1;

		int X2;
		int Y2;

	public:
		//Constructors
		CBoundsBox();
		CBoundsBox(int, int, int, int);

		//function to set BoundsBox position and size
		void setBox(int, int, int, int);

		//functions to directly set the box's bounds
		void setX1(int X_1) { X1 = X_1; }
		void setY1(int Y_1) { Y1 = Y_1; }

		void setX2(int X_2) { X2 = X_2; }
		void setY2(int Y_2) { Y2 = Y_2; }

		//functions to get the box's bounds
		int getX1() { return X1; }
		int getY1() { return Y1; }

		int getX2() { return X2; }
		int getY2() { return Y2; }

		//functions to set position, maintaining size.
		void setX(int);
		void setY(int);
		void setPosition(int X, int Y) { setX(X); setY(Y); }

		//functions to set size
		void setWidth(int Width) { X2 = X1 + Width; }
		void setHeight(int Height) { Y2 = Y1 + Height; }
		void setSize(int Width, int Height) { setWidth(Width); setHeight(Height); }

		//functions to get size
		int getWidth() { return (X2 - X1); }
		int getHeight() { return (Y2 - Y1); }

	};

	//default constructor
	CBoundsBox::CBoundsBox()
	{
		X1 = 0;
		Y1 = 0;

		X2 = 0;
		Y2 = 0;
	}

	//full-data constructor
	CBoundsBox::CBoundsBox(int X_pos, int Y_pos, int width, int height)
	{
		X1 = X_pos;
		Y1 = Y_pos;

		X2 = X_pos + width;
		Y2 = Y_pos + height;
	}

	//function to set position and size
	void CBoundsBox::setBox(int X_pos, int Y_pos, int width, int height)
	{
		X1 = X_pos;
		Y1 = Y_pos;

		X2 = X_pos + width;
		Y2 = Y_pos + height;
	}

	//function to set X position, maintaining width.
	void CBoundsBox::setX(int X_pos)
	{
		int Width = X2 - X1;

		X1 = X_pos;
		X2 = X_pos + Width;
	}

	//function to set Y position, maintaining height.
	void CBoundsBox::setY(int Y_pos)
	{
		int Height = Y2 - Y1;

		Y1 = Y_pos;
		Y2 = Y_pos + Height;
	}
}
