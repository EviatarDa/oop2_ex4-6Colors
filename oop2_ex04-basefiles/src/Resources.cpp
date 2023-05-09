#pragma once

#include "Resources.h"

Resources::Resources()
{
	//LoadFromFile();
	m_textures[0].loadFromFile("X.png");
}

Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}

sf::Color* Resources::getColorArray()
{
	return m_colorArray;
}

sf::Texture& Resources::getTexture(Textures texture)
{
	return m_textures[texture];
}
