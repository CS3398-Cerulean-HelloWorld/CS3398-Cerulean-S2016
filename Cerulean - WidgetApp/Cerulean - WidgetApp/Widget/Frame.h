#pragma once
#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include "Container.h"
#include "ActionTarget.h"

class Frame : public Container, protected ActionTarget<int>
{
  public:
  using ActionTarget<int>::FuncType;
  Frame(sf::RenderWindow& window);
  virtual ~Frame();

  void processEvents();
  bool processEvent(const sf::Event& event);

  void bind(int key,const FuncType& callback);
  void unbind(int key);

  void draw();
  virtual sf::Vector2f getSize()const override;

  private:
  sf::RenderWindow& _window;

  virtual bool processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)override;
  virtual void processEvents(const sf::Vector2f& parent_pos)override;
};


Frame::Frame(sf::RenderWindow& window) : Container(nullptr), ActionTarget(Configuration::gui_inputs), _window(window) {}
Frame::~Frame(){}

void Frame::draw() {_window.draw(*this);}

void Frame::bind(int key,const FuncType& callback) {ActionTarget::bind(key,callback);}

void Frame::unbind(int key) {ActionTarget::unbind(key);}

sf::Vector2f Frame::getSize()const
{
  sf::Vector2u size = _window.getSize();
  return sf::Vector2f(size.x,size.y);
}

void Frame::processEvents()
{
    sf::Vector2f parent_pos(0,0);
    processEvents(parent_pos);
}
bool Frame::processEvent(const sf::Event& event)
{
    sf::Vector2f parent_pos(0,0);
    return processEvent(event,parent_pos);
}

bool Frame::processEvent(const sf::Event& event,const sf::Vector2f& parent_pos)
{
  bool res = ActionTarget::processEvent(event);
  if(not res)
  res = Container::processEvent(event,parent_pos);
  return res;
}

void Frame::processEvents(const sf::Vector2f& parent_pos)
{
  ActionTarget::processEvents();
  Container::processEvents(parent_pos);
  sf::Event event;
  while(_window.pollEvent(event))
  Container::processEvent(event,parent_pos);
}

#endif // FRAME_H_INCLUDED
