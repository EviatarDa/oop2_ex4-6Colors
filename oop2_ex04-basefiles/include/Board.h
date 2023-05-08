#pragma once

#include <SFML/Graphics.hpp>
#include "Hexagon.h"

class Board
{
public:
	Board(int, int);
	void drawGame(sf::RenderWindow&);

	

private:
	std::vector<Hexagon> m_hexagons;
	int m_row;
	int m_col;

	void createBoard();

};