#pragma once
#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include <SFML/Window/Event.hpp>

class Action
{
public:

	enum Type
	{
		RealTime = 1,
		Pressed = 1 << 1,
		Released = 1 << 2
	};

	Action(const Action& other);
	const Action& operator=(const Action& other);

	Action(const sf::Keyboard::Key& key, int type = Type::RealTime | Type::Pressed);
	Action(const sf::Mouse::Button& button, int type = Type::RealTime | Type::Pressed);

	bool test()const;

	bool operator==(const sf::Event& event)const;
	bool operator==(const Action& other)const;

private:
	friend class ActionTarget;
	sf::Event _event;
	int _type;
};


Action::Action(const Action& other) : _type(other._type)
{
	std::memcpy(&_event, &other._event, sizeof(sf::Event));
}

const Action& Action::operator=(const Action& other)
{
	std::memcpy(&_event, &other._event, sizeof(sf::Event));
	_type = other._type;
	return *this;
}

Action::Action(const sf::Keyboard::Key& key, int type) : _type(type)
{
	_event.type = sf::Event::EventType::KeyPressed;
	_event.key.code = key;
}

Action::Action(const sf::Mouse::Button& button, int type) : _type(type)
{
	_event.type = sf::Event::EventType::MouseButtonPressed;
	_event.mouseButton.button = button;
}

bool Action::operator==(const sf::Event& event)const
{
	bool res = false;
	switch (event.type)
	{
	case sf::Event::EventType::KeyPressed:
	{
		if ((_type & Type::Pressed) && (_event.type == sf::Event::EventType::KeyPressed))
			res = event.key.code == _event.key.code;
	}break;
	case sf::Event::EventType::KeyReleased:
	{
		if ((_type & Type::Released) && (_event.type == sf::Event::EventType::KeyPressed))
			res = event.key.code == _event.key.code;
	}break;
	case sf::Event::EventType::MouseButtonPressed:
	{
		if ((_type & Type::Pressed) && (_event.type == sf::Event::EventType::MouseButtonPressed))
			res = event.mouseButton.button == _event.mouseButton.button;
	}break;
	case sf::Event::EventType::MouseButtonReleased:
	{
		if ((_type & Type::Released) && (_event.type == sf::Event::EventType::MouseButtonPressed))
			res = event.mouseButton.button == _event.mouseButton.button;
	}break;
	default: break;
	}
	return res;
}

bool Action::operator==(const Action& other)const
{
	return (_type == other._type) && (other == _event);
}

bool Action::test()const
{
	bool res = false;
	if (_event.type == sf::Event::EventType::KeyPressed)
	{
		if (_type & Type::Pressed)
			res = sf::Keyboard::isKeyPressed(_event.key.code);
	}
	else if (_event.type == sf::Event::EventType::MouseButtonPressed)
	{
		if (_type & Type::Pressed)
			res = sf::Mouse::isButtonPressed(_event.mouseButton.button);
	}
	return res;
}


#endif // !ACTION_H_INCLUDED