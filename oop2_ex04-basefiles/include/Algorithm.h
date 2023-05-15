#pragma once

#include "Resources.h"
#include <random>
#include "Graph.h"
#include "Hexagon.h"

class Algorithm
{
public:
	virtual Colors getNextColor(Graph<Hexagon>) = 0;

private:	
};