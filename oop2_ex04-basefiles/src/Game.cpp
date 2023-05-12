#pragma once

#include "Game.h"

Game::Game()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Colors"), m_board(ROW, COL), m_game_over(false)
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
                //handleMouseMoved(location, PLAY, EXIT);
            }

            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_window.close();
        }
    }
}

void Game::handleGameClick(sf::Vector2f locaion)
{
    for(int color = Cyan ; color <= Orange ; color++)
    {
        if (m_board.getRectangle((Colors)color).getGlobalBounds().contains(locaion))
        {
            m_board.setPlayerX((Colors)color);
        }
    }
    if (m_board.getBackButton().getGlobalBounds().contains(locaion))
    {
        m_game_over = true;
    }
}

void Game::handleMenuClick(sf::Vector2f location)
{
    for (int button = Easy ; button <= Hard; button++)
    {
        if (m_menu.getButton((Button)button).getGlobalBounds().contains(location))
        {
            startGame();
        }
    }
}

void Game::startGame()
{
    init();
    while (m_window.isOpen() && !m_game_over)
    {
        m_window.clear(sf::Color::Color(0, 102, 105));
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
                handleGameClick(location);
                m_board.Check();
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
}
