#pragma once

#include "Game.h"
#include "EasyAlgorithm.h"
#include "MediumAlgorithm.h"
#include "HardAlgorithm.h"

Game::Game()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Colors"), m_board(ROW, COL), m_game_over(false), m_player_turn(true),
    m_algorithm(std::make_unique<EasyAlgorithm>())
{
    m_window.setFramerateLimit(60);
}

void Game::run()
{
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        m_menu.drawMenu(this->m_window);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;

            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleMenuClick(location);
                break;
            }

            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                handleMenuMouseMoved(location);
            }

            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}

void Game::playerTurn(sf::Vector2f locaion)
{
	for (int color = Cyan; color <= Orange; color++)
	{
		if (m_board.getRectangle((Colors)color).getGlobalBounds().contains(locaion))
		{
			if (color != m_board.getPlayerColor() && color != m_board.getComputerColor())
			{
				m_board.setPlayerX((Colors)color);
				m_board.playTurn(m_player_turn, (Colors)color);
				m_player_turn = false;
			}
		}
	}
    if (m_board.getBackButton().getGlobalBounds().contains(locaion))
    {
        m_game_over = true;
    }
}

void Game::handleMenuClick(sf::Vector2f location)
{
    if (m_menu.getButton(Easy).getGlobalBounds().contains(location))
    {
        m_algorithm.reset(new EasyAlgorithm);
        startGame();
    }
    else if (m_menu.getButton(Medium).getGlobalBounds().contains(location))
    {
        m_algorithm.reset(new MediumAlgorithm);
        startGame();
    }
    if (m_menu.getButton(Hard).getGlobalBounds().contains(location))
    {
        m_algorithm.reset(new HardAlgorithm);
        startGame();
    }

}

void Game::handleMenuMouseMoved(sf::Vector2f location)
{
    for (int button = Easy; button <= Hard; button++)
    {
        if ((m_menu.getButton((Button)button).getGlobalBounds().contains(location)))
        {
            m_menu.ButtonPress((Button)button);
        }
        else
        {
            m_menu.ButtonRelease((Button)button);
        }
    }
}

void Game::handleGameMouseMoved(sf::Vector2f location)
{
    if (m_board.getBackButton().getGlobalBounds().contains(location))
    {
        m_board.backPress();
    }
    else
    {
        m_board.backRelease();
    }
}

void Game::startGame()
{
    init();
    while (m_window.isOpen() && !m_game_over)
    {
        m_window.clear(WINDOW_COLOR);
        m_board.drawBoard(this->m_window);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event) )
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });

                if (m_player_turn)
                {
                    playerTurn(location);
                    computerTurn(m_algorithm->getNextColor());
                }
                //m_board.Check();
                break;
            }
            case sf::Event::MouseMoved:
            {
                auto location = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
                handleGameMouseMoved(location);
                break;
            }

            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}

void Game::init()
{
    m_game_over = false;
    m_player_turn = true;
    m_board.init();
}

void Game::computerTurn(Colors color)
{
    if(!m_player_turn)
    {
        while ((color == m_board.getPlayerColor() || color == m_board.getComputerColor()))
        {
            color = m_algorithm->getNextColor();
        }
        m_board.setComputerX(color);
        m_board.playTurn(m_player_turn, color);
        m_player_turn = true;
    }
}
