#pragma once

#include <queue>
#include <SFML/Graphics.hpp>

template <class Shape>
class Graph
{
public:
	Graph(int);
	void BFS(int);
    //void add();

private:
	std::vector<std::vector<std::shared_ptr<Shape>>> m_neighbors;
	int m_size;

};

template<class Shape>
inline Graph<Shape>::Graph(int size)
	:m_size(size)
{
    m_neighbors.resize(m_size);
}

template<class Shape>
inline void Graph<Shape>::BFS(int start_node) {
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
        //std::cout << node << " ";
        q.pop();

        // Get the neighbors of the dequeued vertex
        std::vector<std::shared_ptr<Shape>> neighbors = m_neighbors[node];

        // For each neighbor, if it hasn't been visited yet, mark it as visited
        // and enqueue it
        for (int i = 0; i < neighbors.size(); i++) {
            int neighbor_node = neighbors[i]->get_id();  // assuming the Shape class has a method called get_id() that returns the node ID
            if (!visited[neighbor_node]) {
                visited[neighbor_node] = true;
                q.push(neighbor_node);
            }
        }
    }
}

