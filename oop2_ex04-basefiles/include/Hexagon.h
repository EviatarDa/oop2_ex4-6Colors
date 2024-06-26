#pragma once

#include <SFML/Graphics.hpp>
#include <Resources.h>
#include <random> 

class Hexagon
{
public:
	Hexagon(const int, const int);
	sf::CircleShape& get();
	const int getRow()const;
	const int getCol()const;
	const sf::Color getColor()const;
	const sf::Vector2f getPosition()const;
	const int getIndex()const;
	void setColor(const Colors);


private:
	sf::CircleShape m_hexagon;
	int m_col;
	int m_row;
};