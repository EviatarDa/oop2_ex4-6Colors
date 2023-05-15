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
	void setComputerX(Colors);
	sf::RectangleShape getRectangle(Colors);
	sf::Sprite getBackButton();
	void backPress();
	void backRelease();
	Colors getComputerColor();
	Colors getPlayerColor();
	void playTurn(bool, Colors);
	void init();
	int size();
	int playerArea();
	int computerArea();
	int countArea(std::vector<bool>);
	Graph<Hexagon> getGraph();

private:
	int m_row;
	int m_col;
	std::vector<Hexagon> m_hexagons;
	sf::RectangleShape m_grid_frame[4];
	std::vector<sf::RectangleShape> m_rectangles;
	std::unique_ptr<X> m_PlayerX;
	std::unique_ptr<X> m_ComputerX;
	sf::Sprite m_back;
	Graph<Hexagon> m_graph;
	sf::Sprite m_backgroung;



	void createBoard();
	void createRectangles();
	void connectNeighbors();
	void connectHexagonNeighbors(int directions[6][2], int, int, Hexagon&);
	void locateObjects();
	void createGridFrame();
	sf::RectangleShape createRectangle(const int) const;
	Colors color2Enum(sf::Color);
};