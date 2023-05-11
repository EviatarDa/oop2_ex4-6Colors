#pragma once

#include <SFML/Graphics.hpp>

template <class Shape>
class Graph
{
public:
	Graph(int);


private:
	std::vector<std::shared_ptr<Shape>> m_neigbers;
	int m_size;

};

template<class Shape>
inline Graph<Shape>::Graph(int size)
	:m_size(size)
{
	m_neigbers.resize(m_size);
}
