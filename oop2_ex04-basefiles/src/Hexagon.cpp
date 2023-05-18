#pragma once

#include "Hexagon.h"


Hexagon::Hexagon(const int row, const int col)
	:m_row(row), m_col(col), m_hexagon(RADIUS, 6)
{
	std::random_device rd;                       // Obtain a random seed from the hardware
	std::mt19937 generator(rd());                 // Initialize the random number generator
	std::uniform_int_distribution<int> distribution(0, 5);  // Define the range of the random numbers

	int randomNumber = distribution(generator);  // Generate a random number

	m_hexagon.setOrigin(0, 0);
	m_hexagon.setOrigin(25, 25);
	m_hexagon.setPosition(getPosition());
	m_hexagon.setFillColor(Resources::instance().getColorArray()[randomNumber]);
	m_hexagon.setOutlineThickness(OUTLINE);
	m_hexagon.setOutlineColor(sf::Color::Black);
}

sf::CircleShape& Hexagon::get() 
{
	return m_hexagon;
}



const int Hexagon::getRow()const
{
	return m_row;
}

const int Hexagon::getCol()const
{
	return m_col;
}




const sf::Color Hexagon::getColor()const
{
	return m_hexagon.getFillColor();
}



const sf::Vector2f Hexagon::getPosition()const
{
	float x = m_col * HEX_WIDTH + ((m_row % 2 == 0) ? HEX_WIDTH / 2.f : 0.f) + (WINDOW_WIDTH/2)- (GRID_WIDTH/2) + RADIUS;
	float y = (m_row * (HEX_HEIGHT * 3.f / 4.f) + (WINDOW_HEIGHT / 2) - (GRID_HEGHT / 2));

	return sf::Vector2f(x, y);
}

const int Hexagon::getIndex()const
{
	return COL * m_row + m_col;
}

void Hexagon::setColor(const Colors color)
{
	m_hexagon.setFillColor(Resources::instance().getColorArray()[color]);
}
