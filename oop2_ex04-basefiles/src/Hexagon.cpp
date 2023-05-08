#pragma once

#include "Hexagon.h"

Hexagon::Hexagon(int row, int col)
	:m_hexagon(25,6)
{
	m_hexagon.setOrigin(25, 25);
	m_hexagon.setPosition((col % 2 ? 75 : 50) + row * 50.f, 50 + col * 40.f);
	m_hexagon.setFillColor(sf::Color(row * 25, col * 25, 0));
	//m_hexagon.setPosition((float)((1400 - col * 50.f) / 2 + (col * 50.f)),
	//	(float)((800 - row * 50.f) / 2 + (row * 50.f)));
	//m_hexagon.setFillColor(sf::Color::Red);
	m_hexagon.setOutlineThickness(5);
	m_hexagon.setOutlineColor(sf::Color::Black);

}

sf::CircleShape Hexagon::get()
{
	return m_hexagon;
}
