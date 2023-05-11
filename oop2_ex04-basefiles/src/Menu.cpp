#pragma once

#include "Menu.h"

Menu::Menu()
{
	m_backgroung.setTexture(Resources::instance().getTexture(Background));
	m_backgroung.scale(0.8f, 0.8f);

	for (int button = Eazy; button <= Hard; button++)
	{
		m_buttons[button].setTexture(Resources::instance().getButton((Button)button));
	}

	m_buttons[Eazy].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[Eazy].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[Eazy].getTextureRect().height * 1.5 * 3));

	m_buttons[Medium].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[Medium].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[Medium].getTextureRect().height * 1.5 * 2));

	m_buttons[Hard].setPosition(sf::Vector2f((WINDOW_WIDTH - m_buttons[Hard].getTextureRect().width) * 0.5,
		WINDOW_HEIGHT - m_buttons[Hard].getTextureRect().height * 1.5 * 1));
}

sf::Sprite Menu::getButton(const Button button) const
{
	return m_buttons[button];
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(m_backgroung);
	for (int button = Eazy; button <= Hard; button++)
	{
		window.draw(m_buttons[button]);
	}
}
