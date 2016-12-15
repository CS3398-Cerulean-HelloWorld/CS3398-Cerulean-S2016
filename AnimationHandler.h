#pragma once
#include "SFML/Window.hpp"
#include "SFML\Window.hpp"
#include "AssetManager.h"
#include <string>
#include <vector>
#include <list>
class  Animator
{
public:
	struct Animation
	{
		std::string m_Name;
		std::string m_TextureName;
		std::vector<sf::IntRect> m_Frames;
		sf::Time m_Duration;
		bool m_Looping;

		Animation(std::string const& name, std::string const& textureName,
			sf::Time const& duration, bool looping) : m_Name(name), m_TextureName(textureName), m_Duration(duration), m_Looping(looping)
		{}

		void AddFrames(sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int frames)
		{
			sf::Vector2i current = startFrom;
			for (unsigned int i = 0; i < frames; i++)
			{
				m_Frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
				current.x += frameSize.x;
			}
		}
	};

	Animator(sf::Sprite& sprite);

	Animator::Animation& CreateAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool loop = false);

	void Update(sf::Time const& dt);

	bool SwitchAnimation(std::string const& name);

	std::string GetCurrentAnimationName() const;
private:
	Animator::Animation* FindAnimation(std::string const& name);

	void SwitchAnimation(Animator::Animation* animation);

	sf::Sprite& m_Sprite;
	sf::Time m_CurrentTime;
	std::list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;

};

Animator::Animator(sf::Sprite& sprite) : m_Sprite(sprite), m_CurrentTime(), m_CurrentAnimation(nullptr)
{
}

Animator::Animation& Animator::CreateAnimation(std::string const& name, std::string const& textureName, sf::Time const& duration, bool loop)
{
	m_Animations.push_back(
		Animator::Animation(name, textureName, duration, loop));

	if (m_CurrentAnimation == nullptr)
		SwitchAnimation(&m_Animations.back());

	return m_Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation* animation)
{
	if (animation != nullptr)
	{
		m_Sprite.setTexture(AssetManager::GetTexture(animation->m_TextureName));
	}

	m_CurrentAnimation = animation;
	m_CurrentTime = sf::Time::Zero;
}

bool Animator::SwitchAnimation(std::string const& name)
{
	auto animation = FindAnimation(name);
	if (animation != nullptr)
	{
		SwitchAnimation(animation);
		return true;
	}
	return false;
}

Animator::Animation* Animator::FindAnimation(std::string const& name)
{
	for (auto it = m_Animations.begin(); it != m_Animations.end(); ++it)
	{
		if (it->m_Name == name)
			return &*it;
	}
	return nullptr;
}

std::string Animator::GetCurrentAnimationName() const
{
	if (m_CurrentAnimation != nullptr)
		return m_CurrentAnimation->m_Name;

	return "";
}

void Animator::Update(sf::Time const& dt)
{
	if (m_CurrentAnimation == nullptr)
		return;
	m_CurrentTime += dt;

	float scaledTime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
	int numFrames = m_CurrentAnimation->m_Frames.size();
	int currentFrame = static_cast<int>(scaledTime * numFrames);
	if (m_CurrentAnimation->m_Looping)
		currentFrame %= numFrames;
	else if (currentFrame >= numFrames)
		currentFrame = numFrames - 1;
	m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}