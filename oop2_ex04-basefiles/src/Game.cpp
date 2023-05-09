#pragma once

#include "Game.h"

Game::Game()
    :m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Colors"), m_board(ROW, COL)
{
    m_window.setFramerateLimit(60);
}

void Game::run()
{
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::Color(0, 0, 0));
        //DrawMenu();
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
                //handleClick(location);
                startGame();
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
}

void Game::startGame()
{
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::Color(0, 102, 105));
        m_board.drawBoard(this->m_window);
        m_window.display();

        for (auto event = sf::Event{}; m_window.waitEvent(event); )
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                auto location = m_window.mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                handleGameClick(location);
                startGame();
                break;
            }

            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        //{
        //    m_window.close();
        //}
    }
}
