#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Algorithm.h"
#include "Resources.h"
#include "Board.h"
#include "Menu.h"


class Game
{
public:
	Game();
	void run();
	void playerTurn(sf::Vector2f);
	void handleMenuClick(sf::Vector2f);
	void handleMenuMouseMoved(sf::Vector2f);
	void handleGameMouseMoved(sf::Vector2f);

private:
	sf::RenderWindow m_window;
	Resources& m_resource = Resources::instance();
	Menu m_menu;
	Board m_board;
	bool m_game_over;
	bool m_player_turn;
	std::unique_ptr<Algorithm> m_algorithm;

	void startGame();
	void init();
	void computerTurn(Colors);
	void winLoop();
	void loseLoop();
};