#include "EasyAlgorithm.h"
#pragma once

Colors EasyAlgorithm::getNextColor( Graph<Hexagon> graph,  std::vector<Hexagon> board, const  int curr_size) 
{
	std::random_device rd;                      
	std::mt19937 generator(rd());             
	std::uniform_int_distribution<int> distribution(0, 5);  
	int randomNumber = distribution(generator);  

	return (Colors)randomNumber;
}
