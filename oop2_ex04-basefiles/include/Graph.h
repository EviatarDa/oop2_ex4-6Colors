#pragma once

#include <queue>
#include<iostream>
#include <SFML/Graphics.hpp>

template <class Shape>
class Graph
{
public:
	Graph(int);
	std::vector<bool> BFS(int);
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
inline std::vector<bool> Graph<Shape>::BFS(int start_node) {
    // Initialize the visited array and the queue
    std::vector<bool> visited(m_size, false);
    std::queue<int> q;

    // Mark the starting node as visited and enqueue it
    visited[start_node] = true;
    q.push(start_node);

    // Perform BFS
    while (!q.empty()) {
        // Dequeue a vertex from the queue and print it
        int node = q.front();
        
        q.pop();

        // Get the neighbors of the dequeued vertex
        std::vector<Shape*> neighbors = m_neighbors[node];
      

        // For each neighbor, if it hasn't been visited yet, mark it as visited
        // and enqueue it
        for (int i = 0; i < neighbors.size(); i++) {
            int neighbor_node = neighbors[i]->getIndex();  // assuming the Shape class has a method called get_id() that returns the node ID
            if (!visited[neighbor_node]) {
                visited[neighbor_node] = true;
                q.push(neighbor_node);
            }
        }
    }
    return visited;
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

//template<class Shape>
//inline void Graph<Shape>::rePaint(int node_index, Colors color)
//{
//    std::vector<bool> shapes_to_paint = BFS(node_index);
//    for (int index = 0; index < shapes_to_paint.size(); index++)
//    {
//        if(shapes_to_paint[index] == true)
//            hexagons[index]->setColor(color);
//    }
//}

