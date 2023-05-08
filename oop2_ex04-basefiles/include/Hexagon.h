#pragma once

#include <SFML/Graphics.hpp>

class Hexagon
{
public:
	Hexagon(int, int);
	sf::CircleShape get();

private:
	sf::CircleShape m_hexagon;
};