#pragma once

#include <SFML/Graphics.hpp>
#include "Hexagon.h"
#include "X.h"
#include "Graph.h"

class Board
{
public:
	Board(int, int);
	void drawBoard(sf::RenderWindow&);
	void setPlayerX(Colors);
	sf::RectangleShape getRectangle(Colors);
	sf::Sprite getBackButton();
	void backPress();
	void backRelease();
	void Check();

private:
	int m_row;
	int m_col;
	std::vector<Hexagon> m_hexagons;
	std::vector<sf::RectangleShape> m_rectangles;
	std::unique_ptr<X> m_PlayerX;
	std::unique_ptr<X> m_ComputerX;
	sf::Sprite m_back;
	Graph<Hexagon> m_graph;

	void createBoard();
	void createRectangles();
	void connectNeighbors();
	void connectHexagonNeighbors(int directions[6][2], int, int, Hexagon&);
	void locateObjects();
	sf::RectangleShape createRectangle(const int) const;

};