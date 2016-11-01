#pragma once
#ifndef VLAYOUT_H_INCLUDED
#define VLAYOUT_H_INCLUDED

#include "Widget.h"

class VLayout : public Layout
{
  public:
  VLayout(const VLayout&) = delete;
  VLayout& operator=(const VLayout&) = delete;
  VLayout(Widget* parent = nullptr);
  ~Vlayout();

  void add(Widget* widget);
  Widget* at(unsigned int index)const;
  virtual sf::Vector2f getSize()const override;

  protected:
  virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos) override;
  virtual void processEvents(const sf::Vector2f& parent_pos) override;

  private:
  std::vector<Widget*> _widgets;
  virtual void updateShape() override;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


VLayout::VLayout(Widget* parent) : Layout(parent) {}
VLayout::~VLayout()
{
    for(Widget* widget : _widgets) {
        if(widget->_parent == this)
            delete widget;
    }
}


void VLayout::add(Widget* widget)
{
  widget->_parent = this;
  _widgets.emplace_back(widget);
  updateShape();
}
Widget* VLayout::at(unsigned int index)const {return _widgets.at(index);}


sf::Vector2f VLayout::getSize()const
{
  float max_x = 0;
  float y = 0;
  for(Widget* widget : _widgets)
  {
    sf::Vector2f size = widget->getSize();
    if(size.x > max_x)
    max_x = size.x;
    y+= _space + size.y;
  }
  return sf::Vector2f(max_x+_space*2,y+_space);
}


bool VLayout::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)
{
  for(Widget* widget : _widgets)
{
    if(widget->processEvent(event,parent_pos))
    return true;
  }
    return false ;
}

void VLayout::processEvents(const sf::Vector2f& parent_pos)
{
  for(Widget* widget : _widgets)
  widget->processEvents(parent_pos);
}

void VLayout::updateShape()
{
  float max_x = (_parentparent->getSize().x:0);
  for(Widget* widget : _widgets) {
  sf::Vector2f size = widget->getSize();
  float widget_x = size.x;
  if(widget_x > max_x)
  max_x = widget_x;
}
  float pos_y = _space;
  if(_parent)
  pos_y = (_parent->getSize().y - getSize().y)/2.f;
  for(Widget* widget : _widgets)
{
    sf::Vector2f size = widget->getSize();
    widget->setPosition((max_x-size.x)/2.0,pos_y);
    pos_y += size.y + _space;
  }
  Widget::updateShape();
}

void VLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  for(Widget* widget : _widgets)
  target.draw(*widget,states);
}

#endif // VLAYOUT_H_INCLUDED
