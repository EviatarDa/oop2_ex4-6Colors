#pragma once

#include <SFML/Graphics.hpp>
#include "Hexagon.h"
#include "X.h"

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
	std::unique_ptr<X> m_X;

	void createBoard();
	void createRectangles();
	sf::RectangleShape createRectangle(const int) const;
	sf::VertexArray createX(sf::RectangleShape);

};