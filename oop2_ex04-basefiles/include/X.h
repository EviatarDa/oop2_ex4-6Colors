#pragma once

#include <SFML/Graphics.hpp>
#include "Resources.h"

class X
{
public:
	X(sf::Vector2f);
	sf::RectangleShape getLine1();
	sf::RectangleShape getLine2();
	sf::Sprite get();


private:
	sf::RectangleShape m_line1;
	sf::RectangleShape m_line2;

	sf::Sprite m_sprite;
};