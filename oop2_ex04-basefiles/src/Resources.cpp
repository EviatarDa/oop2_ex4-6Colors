#pragma once

#include "Resources.h"

Resources::Resources()
{
	LoadFromFile();
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

sf::Texture& Resources::getButton(Button button)
{
	return m_Buttons[button];
}

void Resources::LoadFromFile()
{
	m_textures[X_texture].loadFromFile("X.png");
	m_textures[Background].loadFromFile("Background.png");
	m_textures[Background].setSmooth(true);

	m_Buttons[0].loadFromFile("Play.png");
	m_Buttons[1].loadFromFile("Help.png");
	m_Buttons[2].loadFromFile("Exit.png");
}
