#pragma once

#include "Hexagon.h"

Hexagon::Hexagon(int row, int col)
	:m_hexagon(20,6)
{
	m_hexagon.setPosition(row, col);
	m_hexagon.setFillColor(sf::Color::Red);
}

sf::CircleShape Hexagon::get()
{
	return m_hexagon;
}
