#pragma once

#include "Resources.h"

Resources::Resources()
{
	//LoadFromFile();
}

Resources& Resources::instance()
{
	static Resources Resource;
	return Resource;
}

sf::Color* Resources::getColorArray()
{
	return m_colorArray;
}
