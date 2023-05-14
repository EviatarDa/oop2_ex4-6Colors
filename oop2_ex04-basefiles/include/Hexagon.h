#pragma once

#include <SFML/Graphics.hpp>
#include <Resources.h>
#include <random> 

class Hexagon
{
public:
	Hexagon(int, int);
	sf::CircleShape& get();
	void setOwner(Owner);
	int getRow(); 
	int getCol();
	void addNeighbor(Hexagon*);
	sf::Color getColor();
	std::vector<Hexagon*> getNeighbors();
	sf::Vector2f getPosition();
	int getIndex();
	void setColor(Colors);
	

private:
	sf::CircleShape m_hexagon;
	//sf::Color m_color;
	int m_row;
	int m_col;
	std::vector<Hexagon*> m_neighbors;
	Owner m_owner;
};