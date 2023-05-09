#pragma once

#include "Hexagon.h"

Hexagon::Hexagon(int row, int col)
	:m_hexagon(RADIUS,6)
{
	//srand(time(NULL));
	m_hexagon.setOrigin(0, 0);
	m_color = Resources::instance().getColorArray()[rand() % 6];
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