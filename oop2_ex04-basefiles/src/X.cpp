#pragma once

#include "X.h"

X::X(sf::Vector2f origin)
{
	m_sprite.setTexture(Resources::instance().getTexture((Textures)X_texture));
	m_sprite.setPosition(origin);
	m_sprite.setScale(sf::Vector2f(0.0426, 0.0426));
}

sf::Sprite X::get()
{
	return m_sprite;
}
