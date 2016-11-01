#pragma once
#ifndef LAYOUT_H_INCLUDED
#define LAYOUT_H_INCLUDED

#include "Widget.h"

/*
Defining class for the layout widget.
This class cannot be drawn directly.
Another inherited class must be created with a draw() function.
*/

class Layout : protected Widget
{
public:
	///Public functions

	//Constructor with optional parent
	Layout(Widget* parent=nullptr);

	//Destructor
	virtual ~Layout();

	//Function to set the space between contained widgets
	void setSpace(float pixels);

protected:
	//Container widget will have access to this data
	friend class Container;

	///Private variables

	//Widget spacing
	float _space;
};


///Constructors and destructors

//Constructor. default spacing is 5 pixels
Layout::Layout(Widget* parent): Widget(parent), _space(5) {}

//Destructor.
Layout::~Layout() {}

///Setters

//Function to set the space between contained widgets
void Layout::setSpace(float pixels)
{
    if(pixels >= 0) {
        _space = pixels;
        updateShape();
    }
    else
        throw std::invalid_argument("pixel value must be >= 0");
}


#endif // LAYOUT_H_INCLUDED
