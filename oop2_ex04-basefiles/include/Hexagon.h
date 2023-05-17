#pragma once

#include <SFML/Graphics.hpp>
#include <Resources.h>
#include <random> 

class Hexagon
{
public:
	Hexagon(int, int);
	sf::CircleShape& get();
	int getRow();
	int getCol();
	sf::Color getColor();
	sf::Vector2f getPosition();
	int getIndex();
	void setColor(Colors);


private:
	sf::CircleShape m_hexagon;
	int m_col;
	int m_row;
};