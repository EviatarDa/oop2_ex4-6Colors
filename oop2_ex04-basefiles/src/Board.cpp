#pragma once

#include "Board.h"

Board::Board(int row, int col)
	:m_row(row), m_col(col), m_graph(row* col)
{
	createBoard();
	connectNeighbors();
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
	//m_hexagons[m_col].get().setFillColor(sf::Color::Black);
	//m_hexagons[m_row*m_col-m_col].get().setFillColor(sf::Color::Black);

	//if(m_hexagons[m_row].getColor() ==  )
}

void Board::createRectangles()
{
	for (int rectangle = 0; rectangle < 6; ++rectangle)
	{
		m_rectangles.push_back(createRectangle(rectangle));
	}
}

void Board::connectNeighbors()
{
	int even_directions[6][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1} };
	int odd_directions[6][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1} };

	for (int index = 0; index < m_hexagons.size(); ++index) 
	{
		Hexagon& hexagon = m_hexagons[index];
		int row = hexagon.getRow();
		int col = hexagon.getCol();

		if (row % 2 == 0)
		{
			connectHexagonNeighbors(even_directions, row, col, hexagon);
		}
		else
		{
			connectHexagonNeighbors(odd_directions, row, col, hexagon);
		}
	}
}

void Board::connectHexagonNeighbors(int dir[6][2], int row, int col, Hexagon& hexagon)
{
	for (int index = 0 ; index < 6 ; index++)
	{
		int newRow = row + dir[index][0];
		int newCol = col + dir[index][1];

		if (newRow >= 0 && newRow < m_row && newCol >= 0 && newCol < m_col) 
		{
			int neighborIndex = newRow * m_col + newCol;
			if(hexagon.getColor() == m_hexagons[neighborIndex].getColor())
			{
				hexagon.addNeighbor(&m_hexagons[neighborIndex]);
			}
		}
	}
}

sf::RectangleShape Board::createRectangle(const int index) const
{
	sf::RectangleShape rec;

	//Position
	rec.setSize(sf::Vector2f(50.f, 50.f));
	rec.setPosition(WINDOW_WIDTH * 0.5 - 300 + index * 100, WINDOW_HEIGHT * 0.9);

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

void Board::Check()
{
	static int index =0;

	//m_hexagons[index].get().setFillColor(sf::Color::Black);
	Hexagon& hex = m_hexagons[index];
	for(int i = 0; i< hex.getNeighbors().size(); i++)
		if (hex.getNeighbors()[i] != nullptr)
		{
			hex.getNeighbors()[i]->get().setFillColor(sf::Color::Black);
		}
	index++;
}

