#pragma once

#include <SFML/Graphics.hpp>
#include "Hexagon.h"
#include "X.h"

class Board
{
public:
	Board(int, int);
	void drawBoard(sf::RenderWindow&);
	void setPlayerX(Colors);
	sf::RectangleShape getRectangle(Colors);
	

private:
	std::vector<Hexagon> m_hexagons;
	std::vector<sf::RectangleShape> m_rectangles;
	int m_row;
	int m_col;
	std::unique_ptr<X> m_PlayerX;
	std::unique_ptr<X> m_ComputerX;

	void createBoard();
	void createRectangles();
	sf::RectangleShape createRectangle(const int) const;

};