#ifndef LAYOUT_H_INCLUDED
#define LAYOUT_H_INCLUDED

#include "Widget.h"

class Layout : protected Widget
{
  public:
  Layout(Widget* parent=nullptr);
  virtual ~Layout();

  void setSpace(float pixels);

  protected:
  friend class Container;
  float _space;
};


Layout::Layout(Widget* parent): Widget(parent), _space(5) {}

Layout::~Layout() {}
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
