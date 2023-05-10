#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class X
{
public:
	X(sf::Vector2f);
	sf::Sprite get();


private:
	sf::Sprite m_sprite;

};