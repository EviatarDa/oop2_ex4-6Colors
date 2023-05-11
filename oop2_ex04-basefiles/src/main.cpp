#pragma once

#include "Game.h"

int main()
{
	Game game;
	game.run();
}


//
//#include <iostream>
//#include <vector>
//
// //Hexagon class representing a hexagonal shape
//class Hexagon {
//public:
//    int row;
//    int col;
//    std::vector<Hexagon*> neighbors;
//
//    Hexagon(int row, int col) : row(row), col(col) {}
//};
//
// //Function to generate a hexagonal grid
//std::vector<Hexagon> generateHexagonalGrid(int numRows, int numCols) 
//{
//    std::vector<Hexagon> hexagons;
//
//    for (int row = 0; row < numRows; ++row) {
//        for (int col = 0; col < numCols; ++col) {
//             //Compute the position of the hexagon based on the grid layout
//            int x = col * 2;
//            int y = row * 2;
//            if (col % 2 == 1) 
//            {
//                y += 1;
//            }
//
//            Hexagon hexagon(row, col);
//            hexagons.push_back(hexagon);
//        }
//    }
//
//    return hexagons;
//}
//
// //Function to connect neighboring hexagons
//void connectNeighbors(std::vector<Hexagon>& hexagons, int numRows, int numCols) {
//    int directions[6][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1} };
//
//    for (int i = 0; i < hexagons.size(); ++i) {
//        Hexagon& hex = hexagons[i];
//        int row = hex.row;
//        int col = hex.col;
//
//        for (const auto& dir : directions) {
//            int newRow = row + dir[0];
//            int newCol = col + dir[1];
//
//            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols)
//            {
//                int neighborIndex = newRow * numCols + newCol;
//                hex.neighbors.push_back(&hexagons[neighborIndex]);
//            }
//        }
//    }
//}
//
//int main() {
//    int numRows = 4;
//    int numCols = 5;
//
//    std::vector<Hexagon> grid = generateHexagonalGrid(numRows, numCols);
//    connectNeighbors(grid, numRows, numCols);
//
//     //Print the neighbors of each hexagon in the grid
//    for (const Hexagon& hex : grid) {
//        std::cout << "Hexagon at (" << hex.row << ", " << hex.col << ") - Neighbors: ";
//        for (const Hexagon* neighbor : hex.neighbors) {
//            std::cout << "(" << neighbor->row << ", " << neighbor->col << ") ";
//        }
//        std::cout << std::endl;
//    }
//
//    return 0;
//}
