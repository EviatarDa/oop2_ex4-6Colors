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
	m_color = Resources::instance().getColorArray()[randomNumber % 6];
	m_hexagon.setOrigin(25, 25);
	m_hexagon.setPosition(getPosition());
	m_hexagon.setFillColor(m_color);
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
	return m_color;
}

std::vector<Hexagon*> Hexagon::getNeighbors()
{
	return m_neighbors;
}

sf::Vector2f Hexagon::getPosition()
{
	float x = m_col * HEX_WIDTH + ((m_row % 2 == 0) ? HEX_WIDTH / 2.f : 0.f)+10;
	float y = m_row * (HEX_HEIGHT * 3.f / 4.f) +10;
	return sf::Vector2f(x, y);
}