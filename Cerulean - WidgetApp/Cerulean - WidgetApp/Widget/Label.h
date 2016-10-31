#ifndef LABEL_H_INCLUDED
#define LABEL_H_INCLUDED

#include "Widget.h"

class Label : public Widget
{
  public:
  Label(const std::string& text, Widget* parent=nullptr);
  virtual ~Label();

  void setText(const std::string& text);
  void setCharacterSize(unsigned int size);
  unsigned int getCharacterSize()const;
  void setTextColor(const sf::Color& color);
  virtual sf::Vector2f getSize()const override;

  private:
  sf::Text _text;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


Label::Label(const std::string& text, Widget* parent) : Widget(parent)
{
  _text.setFont(Configuration::fonts.get(Configuration::Fonts::Gui));
  setText(text);
  setTextColor(sf::Color(180,93,23));
}

Label::~Label() {}
void Label::setText(const std::string& text)
{
    _text.setString(text);
  updateShape();
}

void Label::setCharacterSize(unsigned int size)
{
  _text.setCharacterSize(size);
  updateShape();
}

unsigned int Label::getCharacterSize()const {return _text.getCharacterSize();}

void Label::setTextColor(const sf::Color& color) {_text.setColor(color);}

sf::Vector2f Label::getSize()const
{
  sf::FloatRect rect = _text.getGlobalBounds();
  return sf::Vector2f(rect.width,rect.height);
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform.translate(_position);
  target.draw(_text,states);
}

#endif // LABEL_H_INCLUDED
