#pragma once

#include <SFML/Graphics.hpp>
#include <Resources.h>
#include <random> 

class Hexagon
{
public:
	Hexagon(int, int);
	sf::CircleShape get();

private:
	sf::CircleShape m_hexagon;
	sf::Color m_color;
};