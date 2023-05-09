#pragma once

#include "X.h"

X::X(sf::Vector2f origin)
	:m_line1(sf::Vector2f(70.7, 5)), m_line2(sf::Vector2f(70.7, 5))
{
	m_sprite.setTexture(Resources::instance().getTexture((Textures)X_texture));
	m_sprite.setPosition(origin);
	m_sprite.setScale(sf::Vector2f(0.25, 0.25));
}

sf::RectangleShape X::getLine1()
{
	return m_line1;
}

sf::RectangleShape X::getLine2()
{
	return m_line2;
}

sf::Sprite X::get()
{
	return m_sprite;
}
