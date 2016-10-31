#pragma once
#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>

class Widget : public sf::Drawable
{
  public:
  Widget(Widget* parent=nullptr);
  virtual ~Widget();

  void setPosition(const sf::Vector2f& pos);
  void setPosition(float x,float y);
  const sf::Vector2f& getPosition()const;
  virtual sf::Vector2f getSize()const = 0;

  protected:
  virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos);
  virtual void processEvents(const sf::Vector2f& parent_pos);
  virtual void updateShape();

  Widget* _parent;
  sf::Vector2f _position;
};


Widget::Widget(Widget* parent) : _parent(parent){}
Widget::~Widget(){}
void Widget::setPosition(const sf::Vector2f& pos) {_position = pos;}
void Widget::setPosition(float x,float y)
{
  _position.x = x;
  _position.y = y;
}
const sf::Vector2f& Widget::getPosition()const {return _position;}
bool Widget::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos) {return false;}
void Widget::processEvents(const sf::Vector2f& parent_pos) {}


void Widget::updateShape()
{
  if(_parent)
  _parent->updateShape();
}

#endif // WIDGET_H_INCLUDED
