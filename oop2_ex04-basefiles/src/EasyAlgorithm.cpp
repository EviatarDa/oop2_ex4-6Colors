#include "EasyAlgorithm.h"
#pragma once

sf::Color EasyAlgorithm::getNextColor()
{
	std::random_device rd;                       // Obtain a random seed from the hardware
	std::mt19937 generator(rd());                 // Initialize the random number generator
	std::uniform_int_distribution<int> distribution(0, 5);  // Define the range of the random numbers

	int randomNumber = distribution(generator);  // Generate a random number

	return Resources::instance().getColorArray()[randomNumber];
}
