#pragma once

#include "Board.h"

Board::Board(const int row, const int col)
	:m_row(row), m_col(col), m_graph(row* col)
{
	m_backgroung.setTexture(Resources::instance().getTexture(GameBackground));
	m_backgroung.scale(2.6f, 2.6f);
	createRectangles();
	createGridFrame();
	locateObjects();
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
	if(m_hexagons[m_col - 1].getColor() == m_hexagons[m_row * m_col - m_col].getColor())
	{
		m_hexagons[COMPUTER_INDEX].get().setFillColor(Resources::instance().getColorArray()[Cyan]);
		m_hexagons[PLAYER_INDEX].get().setFillColor(Resources::instance().getColorArray()[Blue]);
	}
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

void Board::connectHexagonNeighbors(const int dir[6][2], const int row, const int col, Hexagon& hexagon)
{
	for (int index = 0 ; index < 6 ; index++)
	{
		int newRow = row + dir[index][0];
		int newCol = col + dir[index][1];

		if (newRow >= 0 && newRow < m_row && newCol >= 0 && newCol < m_col) 
		{
			int neighborIndex = newRow * m_col + newCol;
			m_graph.addNeighbor(hexagon.getIndex(), &m_hexagons[neighborIndex]);
		}
	}
}

void Board::locateObjects()
{
	m_back.setTexture(Resources::instance().getTexture((Textures)Back));
	m_back.scale(sf::Vector2f(WINDOW_WIDTH * 0.12 / m_back.getTextureRect().width,
		WINDOW_WIDTH * 0.12 / m_back.getTextureRect().width));
	m_back.setPosition(sf::Vector2f(WINDOW_WIDTH * 0.85, WINDOW_HEIGHT * 0.88));
}

void Board::createGridFrame()
{
	//up
	m_grid_frame[0].setSize(sf::Vector2f(GRID_WIDTH+RADIUS, 3/2*RADIUS));
	m_grid_frame[0].setFillColor(WINDOW_COLOR);
	m_grid_frame[0].setPosition(sf::Vector2f((WINDOW_WIDTH / 2) - (GRID_WIDTH / 2) - RADIUS,
		(WINDOW_HEIGHT / 2) - (GRID_HEGHT / 2)-2*RADIUS +2*OUTLINE) );
	//down
	m_grid_frame[1].setSize(sf::Vector2f(GRID_WIDTH + RADIUS, 3/2 *RADIUS));
	m_grid_frame[1].setFillColor(WINDOW_COLOR);
	m_grid_frame[1].setPosition(sf::Vector2f((WINDOW_WIDTH / 2) - (GRID_WIDTH / 2) - RADIUS,
		(WINDOW_HEIGHT / 2) + (GRID_HEGHT / 2) - 2 * RADIUS - 2 * OUTLINE));
	//right
	m_grid_frame[2].setSize(sf::Vector2f(2 * RADIUS, GRID_HEGHT + RADIUS - 4 * OUTLINE));
	m_grid_frame[2].setFillColor(WINDOW_COLOR);
	m_grid_frame[2].setPosition(sf::Vector2f((WINDOW_WIDTH / 2) + (GRID_WIDTH / 2) - RADIUS - (HEX_WIDTH / 2) + 3 * OUTLINE + RADIUS,
		(WINDOW_HEIGHT / 2) - (GRID_HEGHT / 2) - 2 * RADIUS + 2 * OUTLINE));
	//lrft
	m_grid_frame[3].setSize(sf::Vector2f(2 * RADIUS, GRID_HEGHT + RADIUS - 4 * OUTLINE));
	m_grid_frame[3].setFillColor(WINDOW_COLOR);
	m_grid_frame[3].setPosition(sf::Vector2f((WINDOW_WIDTH / 2) - (GRID_WIDTH / 2) - 2*(RADIUS+2*OUTLINE) +HEX_WIDTH/2 - 4*OUTLINE,
		(WINDOW_HEIGHT / 2) - (GRID_HEGHT / 2) - 2 * RADIUS + 2*OUTLINE));
}

const sf::RectangleShape Board::createRectangle(const int index) const
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

const Colors Board::color2Enum(const sf::Color color)
{
	if (color == sf::Color::Cyan)
		return Cyan;
	else if (color == sf::Color::Blue)
		return Blue;
	else if (color == sf::Color::Green)
		return Green;
	else if (color == sf::Color::Red)
		return Red;
	else if (color == sf::Color::Yellow)
		return Yellow;
	else if (color == sf::Color::Color(255, 119, 0))
		return Orange;
}


void Board::drawBoard(sf::RenderWindow& window)
{
	window.draw(m_backgroung);
	for (int hexagon = 0; hexagon < m_hexagons.size(); hexagon++)
	{
		window.draw(m_hexagons[hexagon].get());
	}
	for (int rectangle = 0; rectangle < 4; rectangle++)
	{
		window.draw(m_grid_frame[rectangle]);
	}
	for (int rectangle = 0; rectangle < m_rectangles.size(); rectangle++)
	{
		window.draw(m_rectangles[rectangle]);
	}

	window.draw(m_PlayerX->get());
	window.draw(m_ComputerX->get());
	window.draw(m_back);

}

void Board::setPlayerX(const Colors color)
{
	m_PlayerX = std::make_unique<X>(m_rectangles[color].getPosition());
}

void Board::setComputerX(const Colors color)
{
	m_ComputerX = std::make_unique<X>(m_rectangles[color].getPosition());

}

const sf::RectangleShape Board::getRectangle(Colors const color) const
{
	return m_rectangles[color];
}

const sf::Sprite Board::getBackButton()const
{
	return m_back;
}

void Board::backPress()
{
	m_back.setColor(sf::Color::Color(255, 255, 255, 150));
}

void Board::backRelease()
{
	m_back.setColor(sf::Color::Color(255, 255, 255));
}


const Colors Board::getComputerColor() 
{
	return color2Enum(m_hexagons[COMPUTER_INDEX].getColor());
}

const Colors Board::getPlayerColor() 
{
	return color2Enum(m_hexagons[PLAYER_INDEX].getColor());
}

void Board::playTurn(const bool player_turn, const Colors color)
{
	std::vector<bool> index_to_paint;
	if (player_turn)
		index_to_paint = m_graph.BFS(PLAYER_INDEX, m_hexagons[PLAYER_INDEX].getColor());
	else
		index_to_paint = m_graph.BFS(COMPUTER_INDEX, m_hexagons[COMPUTER_INDEX].getColor());

	for (int index = 0; index < m_hexagons.size(); index++)
	{
		if (index_to_paint[index])
		{
			m_hexagons[index].setColor(color);
		}
	}
}

void Board::init()
{
	m_hexagons.clear();
	m_graph.clear();
	createBoard();
	connectNeighbors();
	m_ComputerX = std::make_unique<X>(m_rectangles[color2Enum(m_hexagons[COMPUTER_INDEX].getColor())].getPosition());
	m_PlayerX = std::make_unique<X>(m_rectangles[color2Enum(m_hexagons[PLAYER_INDEX].getColor())].getPosition());
}

const int Board::size()const
{
	return m_hexagons.size();
}

const int Board::playerArea()
{
	std::vector<bool> currTree = m_graph.BFS(PLAYER_INDEX, m_hexagons[PLAYER_INDEX].getColor());
	int counter = countArea(currTree);
	return counter;
}

const int Board::computerArea()
{
	std::vector<bool> currTree = m_graph.BFS(COMPUTER_INDEX, m_hexagons[COMPUTER_INDEX].getColor());
	int counter = countArea(currTree);
	return counter;
}

const int Board::countArea(std::vector<bool> vec)const
{
	int counter = 0;
	for (int index = 0; index < vec.size(); index++)
	{
		if (vec[index])
		{
			counter++;
		}
	}
	return counter;
}

const Graph<Hexagon> Board::getGraph()const
{
	return m_graph;
}

const std::vector<Hexagon> Board::getBoard()const
{
	return m_hexagons;
}

void Board::rectanglePress(Colors color)
{
	m_rectangles[color].setOutlineColor(sf::Color::Red);
}

void Board::rectangleRelease(Colors color)
{
	m_rectangles[color].setOutlineColor(sf::Color::White);
}
