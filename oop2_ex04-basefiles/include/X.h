#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class X
{
public:
	X(const sf::Vector2f);
	const sf::Sprite get()const;


private:
	sf::Sprite m_sprite;

};