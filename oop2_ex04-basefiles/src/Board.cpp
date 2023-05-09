#pragma once

#include "Board.h"

Board::Board(int row, int col)
	:m_row(row), m_col(col)
{
	createBoard();
	createRectangles();

	m_PlayerX = std::make_unique<X>(m_rectangles[2].getPosition());
	m_ComputerX = std::make_unique<X>(m_rectangles[0].getPosition());
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

void Board::createRectangles()
{
	for (int rectangle = 0; rectangle < 6; ++rectangle)
	{
		m_rectangles.push_back(createRectangle(rectangle));
	}
}

sf::RectangleShape Board::createRectangle(const int index) const
{
	sf::RectangleShape rec;

	//Position
	rec.setSize(sf::Vector2f(50.f, 50.f));
	rec.setPosition(WINDOW_WIDTH * 0.5-300 + index*100, WINDOW_HEIGHT * 0.9);

	//Style
	rec.setOutlineThickness(2.f);
	rec.setFillColor(Resources::instance().getColorArray()[index]);

	return rec;
}


void Board::drawBoard(sf::RenderWindow& window)
{
	for (int hexagon = 0; hexagon < m_hexagons.size(); hexagon++)
	{
		window.draw(m_hexagons[hexagon].get());
	}
	for (int rectangle = 0; rectangle < m_rectangles.size(); rectangle++)
	{
		window.draw(m_rectangles[rectangle]);
	}
	window.draw(m_PlayerX->get());
	window.draw(m_ComputerX->get());
}

void Board::setPlayerX(Colors color)
{
	m_PlayerX = std::make_unique<X>(m_rectangles[color].getPosition());
}

sf::RectangleShape Board::getRectangle(Colors color)
{
	return m_rectangles[color];
}
