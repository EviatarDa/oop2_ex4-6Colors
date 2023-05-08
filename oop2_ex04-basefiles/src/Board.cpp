#pragma once

#include "Board.h"

Board::Board(int row, int col)
	:m_row(row), m_col(col)
{
	createBoard();
}

void Board::createBoard()
{
	for (int row = 0; row < m_row; ++row)
	{
		for (int col = 0 ; col < m_col; ++col)
		{
			m_hexagons.push_back(Hexagon(row, col));
		}
	}
}

void Board::drawGame(sf::RenderWindow& window)
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			window.draw(m_hexagons[row * col].get());
		}
	}
}
