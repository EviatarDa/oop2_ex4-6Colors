#pragma once

#include "Hexagon.h"


Hexagon::Hexagon(int row, int col)
	:m_hexagon(RADIUS,6), m_owner(None)
{
	std::random_device rd;                       // Obtain a random seed from the hardware
	std::mt19937 generator(rd());                 // Initialize the random number generator
	std::uniform_int_distribution<int> distribution(0, 99);  // Define the range of the random numbers

	int randomNumber = distribution(generator);  // Generate a random number

	m_hexagon.setOrigin(0, 0);
	m_color = Resources::instance().getColorArray()[randomNumber % 6];
	m_hexagon.setOrigin(25, 25);
	m_hexagon.setPosition((col % 2 ? 3 * RADIUS + OUTLINE : 2 * RADIUS + OUTLINE) + row * 2 * RADIUS,
		2 * RADIUS + col * 1.5 * RADIUS + OUTLINE);
	m_hexagon.setFillColor(m_color);
	m_hexagon.setOutlineThickness(OUTLINE);
	m_hexagon.setOutlineColor(sf::Color::Black);

}

sf::CircleShape Hexagon::get()
{
	return m_hexagon;

}

void Hexagon::setOwner(Owner owner)
{
	m_owner = owner;
}
