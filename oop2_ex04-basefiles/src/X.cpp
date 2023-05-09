#pragma once

#include "X.h"

X::X(sf::Vector2f origin)
	:m_line1(sf::Vector2f(70.7, 5)), m_line2(sf::Vector2f(70.7, 5))
{
	m_line1.rotate(45);
	m_line1.setPosition(origin);
	m_line1.setFillColor(sf::Color::Black);

	m_line2.rotate(-45);
	m_line2.setPosition(origin.x, origin.y+50);
	m_line2.setFillColor(sf::Color::Black);
}

sf::RectangleShape X::getLine1()
{
	return m_line1;
}

sf::RectangleShape X::getLine2()
{
	return m_line2;
}
