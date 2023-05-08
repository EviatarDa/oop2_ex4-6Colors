#pragma once

#include "Hexagon.h"

Hexagon::Hexagon(int row, int col)
	:m_hexagon(15,6)
{
	m_hexagon.setPosition((float)((1400 - col * 50.f) / 2 + (col * 50.f)),
		(float)((800 - row * 50.f) / 2 + (row * 50.f)));
	m_hexagon.setFillColor(sf::Color::Red);
	m_hexagon.setOutlineThickness(2);
	m_hexagon.setOutlineColor(sf::Color::Black);
}

sf::CircleShape Hexagon::get()
{
	return m_hexagon;
}
