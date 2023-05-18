#pragma once

#include "MediumAlgorithm.h"



Colors MediumAlgorithm::getNextColor( Graph<Hexagon> graph, std::vector<Hexagon> board, const int curr_size)
{
    int sum = 0;
    Colors best_color;
    for (int color = Cyan; color <= Orange; color++)
    {
        sf::Color check_color = Resources::instance().getColorArray()[color];
      
        if (check_color == board[COMPUTER_INDEX].getColor() || check_color == board[PLAYER_INDEX].getColor())
        {
            continue;
        }

        int new_size = graph.BFS_Medium(board[COMPUTER_INDEX].getColor(), check_color) + curr_size;

        if (new_size > sum)
        {
            sum = new_size;
            best_color = (Colors)color;
        }
    }
    return best_color;
}
