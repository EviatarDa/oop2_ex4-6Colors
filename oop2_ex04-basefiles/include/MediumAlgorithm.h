#pragma once
#include "Algorithm.h"
#include "Resources.h"

class MediumAlgorithm :public Algorithm
{
public:
	Colors getNextColor(Graph<Hexagon>, std::vector<Hexagon>, int curr_size);

private:

};

