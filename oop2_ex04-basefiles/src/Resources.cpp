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

sf::Font& Resources::getFont()
{
	return m_font;
}

void Resources::LoadFromFile()
{
	m_textures[X_texture].loadFromFile("X.png");
	m_textures[Background].loadFromFile("Background.png");
	m_textures[Background].setSmooth(true);
	m_textures[Back].loadFromFile("Back.png");
	m_textures[Six_colors].loadFromFile("Six_colors.png");
	m_textures[GameBackground].loadFromFile("GameBackground.png");
	m_textures[GameBackground].setSmooth(true);
	m_textures[YouWin].loadFromFile("YouWin.png");
	m_textures[YouLose].loadFromFile("YouLose.png");

	m_Buttons[Easy].loadFromFile("Easy.png");
	m_Buttons[Medium].loadFromFile("Medium.png");
	m_Buttons[Hard].loadFromFile("Hard.png");

	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
}
