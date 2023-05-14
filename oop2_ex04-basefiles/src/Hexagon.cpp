#pragma once

#include "Hexagon.h"


Hexagon::Hexagon(int row, int col)
	:m_row(row), m_col(col), m_hexagon(RADIUS, 6), m_owner(None)
{
	std::random_device rd;                       // Obtain a random seed from the hardware
	std::mt19937 generator(rd());                 // Initialize the random number generator
	std::uniform_int_distribution<int> distribution(0, 99);  // Define the range of the random numbers

	int randomNumber = distribution(generator);  // Generate a random number

	m_hexagon.setOrigin(0, 0);
	m_hexagon.setOrigin(25, 25);
	m_hexagon.setPosition(getPosition());
	m_hexagon.setFillColor(Resources::instance().getColorArray()[randomNumber % 6]);
	m_hexagon.setOutlineThickness(OUTLINE);
	m_hexagon.setOutlineColor(sf::Color::Black);

}

sf::CircleShape& Hexagon::get()
{
	return m_hexagon;
}

void Hexagon::setOwner(Owner owner)
{
	m_owner = owner;
}

int Hexagon::getRow()
{
	return m_row;
}

int Hexagon::getCol()
{
	return m_col;
}

void Hexagon::addNeighbor(Hexagon* hexagon)
{
	m_neighbors.push_back(hexagon);
}

sf::Color Hexagon::getColor()
{
	return m_hexagon.getFillColor();
}

std::vector<Hexagon*> Hexagon::getNeighbors()
{
	return m_neighbors;
}

sf::Vector2f Hexagon::getPosition()
{
	float x = m_col * HEX_WIDTH + ((m_row % 2 == 0) ? HEX_WIDTH / 2.f : 0.f) + (WINDOW_WIDTH/2)- (GRID_WIDTH/2);
	float y = (m_row * (HEX_HEIGHT * 3.f / 4.f) + (WINDOW_HEIGHT / 2) - (GRID_HEGHT / 2));

	return sf::Vector2f(x, y);
}

int Hexagon::getIndex()
{
	return COL * m_row + m_col;
}

void Hexagon::setColor(Colors color)
{
	m_hexagon.setFillColor(Resources::instance().getColorArray()[color]);
}
