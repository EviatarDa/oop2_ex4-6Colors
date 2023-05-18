#pragma once

#include "X.h"

X::X(const sf::Vector2f origin)
{
	m_sprite.setTexture(Resources::instance().getTexture((Textures)X_texture));
	m_sprite.setPosition(origin);
	m_sprite.setScale(sf::Vector2f(0.0426, 0.0426));
}

const sf::Sprite X::get()const
{
	return m_sprite;
}
