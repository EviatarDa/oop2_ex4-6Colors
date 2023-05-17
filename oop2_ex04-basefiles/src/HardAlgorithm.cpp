#pragma once

#include "HardAlgorithm.h"

Colors HardAlgorithm::getNextColor(Graph<Hexagon> graph, std::vector<Hexagon> board, int curr_size)
{
  

    int sum = 0;
    Colors best_color;
    for (int color = Cyan; color <= Orange; color++)
    {
        sf::Color my_color = Resources::instance().getColorArray()[color];

        if (my_color == board[COMPUTER_INDEX].getColor() || my_color == board[PLAYER_INDEX].getColor())
        {
            continue;
        }

        int new_size = graph.BFS_Medium(board[COMPUTER_INDEX].getColor(), my_color) + curr_size;

        if (new_size > sum)
        {
            sum = new_size;
            best_color = (Colors)color;
        }
    }
    return best_color;
}
