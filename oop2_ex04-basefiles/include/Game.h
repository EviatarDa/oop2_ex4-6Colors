#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Resources.h"
#include "Board.h"
#include "Menu.h"


class Game
{
public:
	Game();
	void run();
	void handleGameClick(sf::Vector2f);
	void handleMenuClick(sf::Vector2f);

private:
	sf::RenderWindow m_window;
	Resources& m_resource = Resources::instance();
	Menu m_menu;
	Board m_board;
	bool m_game_over;

	void startGame();
	void init();
};