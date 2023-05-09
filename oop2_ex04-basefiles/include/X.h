#pragma once

#include <SFML/Graphics.hpp>

class X
{
public:
	X(sf::Vector2f);
	sf::RectangleShape getLine1();
	sf::RectangleShape getLine2();

private:
	sf::RectangleShape m_line1;
	sf::RectangleShape m_line2;

	sf::Texture m_texture;
	sf::Sprite m_sprite;
};