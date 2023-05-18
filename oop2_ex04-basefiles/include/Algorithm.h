#pragma once

#include "Resources.h"
#include <random>
#include "Graph.h"
#include "Hexagon.h"

class Algorithm
{
public:
	virtual Colors getNextColor(Graph<Hexagon>, std::vector<Hexagon>, const int curr_size) = 0;

private:	
};