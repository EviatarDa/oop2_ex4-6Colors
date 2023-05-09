#pragma once

#include <SFML/Graphics.hpp>
#include "Hexagon.h"

class Board
{
public:
	Board(int, int);
	void drawBoard(sf::RenderWindow&);

	

private:
	std::vector<Hexagon> m_hexagons;
	std::vector<sf::RectangleShape> m_rectangles;
	int m_row;
	int m_col;

	void createBoard();
	void createRectangles();
	sf::RectangleShape createRectangle(const int) const;

};