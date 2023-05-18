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
    m_YouWin.setTexture(Resources::instance().getTexture(YouWin));
    m_YouLose.setTexture(Resources::instance().getTexture(YouLose));

    for(int index = Player ; index <= Computer ; index++)
    {
        m_score[index].setFont(Resources::instance().getFont());
        m_score[index].setCharacterSize(30);
        m_score[index].setOutlineThickness(2);
        m_score[index].setOutlineColor(sf::Color::Red);
    }
    int number = 0;
    m_score[Player].setString("Player:\n" + std::to_string(number) + "%");
    m_score[Computer].setString("Computer:\n" + std::to_string(number) + "%");

    m_score[Player].setPosition(WINDOW_WIDTH * 0.05, WINDOW_HEIGHT * 0.88);
    m_score[Computer].setPosition(WINDOW_WIDTH * 0.15, WINDOW_HEIGHT * 0.88);

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

            double playerPercentage = (m_board.playerArea() / (double)(ROW * COL)) * 100;
            std::stringstream ss;
            ss << "Player:\n" << std::fixed << std::setprecision(2) << playerPercentage << "%";
            m_score[Player].setString(ss.str());

            if (m_board.playerArea() > m_board.size() / 2)
            {
                winLoop();
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
        m_window.draw(m_score[0]);
        m_window.draw(m_score[1]);
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
                    computerTurn(m_algorithm->getNextColor(m_board.getGraph(), m_board.getBoard(), m_board.computerArea()));
                }
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
    int number = 0;
    m_score[Player].setString("Player:\n" + std::to_string(number) + "%");
    m_score[Computer].setString("Computer:\n" + std::to_string(number) + "%");
    m_board.init();
}

void Game::computerTurn(Colors color)
{
    if(!m_player_turn)
    {
        while ((color == m_board.getPlayerColor() || color == m_board.getComputerColor()))
        {
            color = m_algorithm->getNextColor(m_board.getGraph(), m_board.getBoard(), m_board.computerArea());
        }
        m_board.setComputerX(color);
        m_board.playTurn(m_player_turn, color);
        m_player_turn = true;

        double computer_percentage = (m_board.computerArea() / (double)(ROW * COL)) * 100;
        std::stringstream ss;
        ss << "Computer:\n" << std::fixed << std::setprecision(2) << computer_percentage << "%";
        m_score[Computer].setString(ss.str());

        if (m_board.computerArea() > m_board.size() / 2)
        {
            loseLoop();
        }
    }
}

void Game::winLoop()
{
    m_game_over = true;
    bool click = false;

    while (!click)
    {
        m_window.clear(WINDOW_COLOR);
        m_board.drawBoard(this->m_window);
        m_window.draw(m_score[0]);
        m_window.draw(m_score[1]);
        m_window.draw(m_YouWin);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                click = true;
                break;
            }
            case sf::Event::Closed:
                m_window.close();
                break;
            }
            
        }
    }
}

void Game::loseLoop()
{
    m_game_over = true;
    bool click = false;

    while (!click)
    {
        m_window.clear(WINDOW_COLOR);
        m_board.drawBoard(this->m_window);
        m_window.draw(m_score[Player]);
        m_window.draw(m_score[Computer]);
        m_window.draw(m_YouLose);
        m_window.display();

        if (auto event = sf::Event{}; m_window.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::MouseButtonReleased:
            {
                click = true;
                break;
            }
            case sf::Event::Closed:
                m_window.close();
                break;
            }

        }
    }
}
