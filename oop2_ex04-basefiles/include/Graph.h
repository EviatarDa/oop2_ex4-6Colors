#pragma once

#include <queue>
#include<iostream>
#include <SFML/Graphics.hpp>

template <class Shape>
class Graph
{
public:
	Graph(int);
	std::vector<bool> BFS(int, sf::Color);
    int BFS_Medium(sf::Color, sf::Color);
    int BFS_Hard(sf::Color, sf::Color);
    void addNeighbor(int, Shape*);
    void clear();

private:
	int m_size;
    std::vector<std::vector<Shape*>> m_neighbors;
};

template<class Shape>
inline Graph<Shape>::Graph(int size)
	:m_size(size)
{
    m_neighbors.resize(m_size);
}

template<class Shape>
inline std::vector<bool> Graph<Shape>::BFS(int start_node, sf::Color color )
{
    std::vector<bool> visited(m_size, false);
    std::queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        std::vector<Shape*> neighbors = m_neighbors[node];
      
        for (int i = 0; i < neighbors.size(); i++) 
        {
            int neighbor_node = neighbors[i]->getIndex();
            if ((!visited[neighbor_node])&& (neighbors[i]->getColor() == color))
            {
                visited[neighbor_node] = true;
                q.push(neighbor_node);
            }
        }
    }
    return visited;
}



template<class Shape>
inline int Graph<Shape>::BFS_Medium(sf::Color my_color, sf::Color desired_color)
{
    int start_node = COMPUTER_INDEX;
    int counter = 0;
    std::vector<bool> visited(m_size, false);
    std::queue<int> q;

    visited[start_node] = true;
    q.push(start_node);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        std::vector<Shape*> neighbors = m_neighbors[node];

        for (int i = 0; i < neighbors.size(); i++)
        {
            int neighbor_node = neighbors[i]->getIndex();
            if ((!visited[neighbor_node]) && (neighbors[i]->getColor() == my_color))
            {
                visited[neighbor_node] = true;
                q.push(neighbor_node);
            }
            else if ((!visited[neighbor_node]) && (neighbors[i]->getColor() == desired_color))
            {
                visited[neighbor_node] = true;
                counter++;
            }
        }
    }
    return counter;
}

template<class Shape>
inline int Graph<Shape>::BFS_Hard(sf::Color my_color, sf::Color desired_color)
{
    int start_node = COMPUTER_INDEX;
    int counter = 0;
    std::vector<bool> visited(m_size, false);
    std::queue<int> q;
    std::queue<int> q2;

    visited[start_node] = true;
    q.push(start_node);
    q2.push(start_node);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        std::vector<Shape*> neighbors = m_neighbors[node];

        for (int i = 0; i < neighbors.size(); i++)
        {
            int neighbor_node = neighbors[i]->getIndex();
            if ((!visited[neighbor_node]) && (neighbors[i]->getColor() == my_color))
            {
                visited[neighbor_node] = true;
                q.push(neighbor_node);
                q2.push(neighbor_node);
                counter++;
            }
        }
    }

    while (!q2.empty())
    {
        int node = q2.front();
        q2.pop();

        std::vector<Shape*> neighbors = m_neighbors[node];

        for (int i = 0; i < neighbors.size(); i++)
        {
            int neighbor_node = neighbors[i]->getIndex();
            if ((!visited[neighbor_node]) && (neighbors[i]->getColor() == desired_color))
            {
                visited[neighbor_node] = true;
                q2.push(neighbor_node);
                counter++;
            }
        }
    }
    return counter;
}

template<class Shape>
inline void Graph<Shape>::addNeighbor(int index, Shape* shape)
{
    m_neighbors[index].push_back(shape);
}

template<class Shape>
inline void Graph<Shape>::clear()
{
    for (int index = 0; index < m_neighbors.size(); index++)
    {
        m_neighbors[index].clear();
    }
    m_neighbors.clear();
    m_neighbors.resize(m_size);
}


