#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Widget.h"

class Button : public Widget
{
  public:
  Button(Widget* parent=nullptr);

  virtual ~Button();

  protected:
  virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)override;
  virtual void onMouseEntered();
  virtual void onMouseLeft();

  private:
  enum Status {None =0,Hover = 1};
  int _status;
};


Button::Button(Widget* parent) : Widget(parent), onClick(defaultFunc), _status(Status::None) {}

Button::~Button() {}
bool Button::processEvent(const sf::Event& event,const
sf::Vector2f& parent_pos)
{
  bool res = false;
  if(event.type == sf::Event::MouseButtonReleased)
  {
    const sf::Vector2f pos = _position + parent_pos;
    const sf::Vector2f size = getSize();
    sf::FloatRect rect;
    rect.left = pos.x;
    rect.top = pos.y;
    rect.width = size.x;
    rect.height = size.y;
    if(rect.contains(event.mouseButton.x,event.mouseButton.y))
{
      onClick(event,*this);
        res = true;
    }
  } else if (event.type == sf::Event::MouseMoved) {
    const sf::Vector2f pos = _position + parent_pos;
    const sf::Vector2f size = getSize();
    sf::FloatRect rect;
    rect.left = pos.x;
    rect.top = pos.y;
    rect.width = size.x;
    rect.height = size.y;
    int old_status = _status;
    _status = Status::None;
    const sf::Vector2f
    mouse_pos(event.mouseMove.x,event.mouseMove.y);
    if(rect.contains(mouse_pos))
      _status=Status::Hover;
    if((old_status & Status::Hover) and not (_status &
      Status::Hover))
        onMouseLeft();
    else if(not (old_status & Status::Hover) and (_status &
      Status::Hover))
        onMouseEntered();
  }
  return res;
}

void Button::onMouseEntered() {}
void Button::onMouseLeft() {}

#endif // BUTTON_H_INCLUDED
