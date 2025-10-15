/*
 * CSC-301
 * project2.cpp
 * Fall 2025
 *
 * Partner 1: Khanh Do
 * Partner 2: Mia Hoffmann Kamrat
 * Date: Oct 15, 2025
 */

#include "project2.hpp"

using namespace std;

/*
 * Depth First Search: Use a stack to find a path from start to exit.
 *
 * Args:
 *  adjList: The adjacency list of the graph.
 *  start: The starting vertex.
 *  exit: The exit vertex.
 * 
 * Returns:
 *  A vector of ints representing the path from start to exit. If no path is found, 
 * return an empty vector.
 */
vector<int> DFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    vector<int> path;
    return path;
}

/*
 * Breadth First Search: Use a queue to find a path from start to exit. Should
 * find the shortest path.
 * 
 * Args:
 *  adjList: The adjacency list of the graph.
 *  start: The starting vertex.
 *  exit: The exit vertex.
 * 
 * Returns:
 *  A vector of ints representing the path from start to exit. If no path is found
 * return an empty vector.
 */
vector<int> BFS(vector<Vertex> &adjList, Vertex &start, Vertex &exit) {
    // Lazy return when start is exit.
    if (start == exit) {
        return {start.label, exit.label};
    }

    vector<int> path;

    // Initialize the queue with the start vertex.
    queue<Vertex> queue;
    queue.push(start);
    start.visited = true;
    start.previous = -1;

    // Process the queue until it's empty or we find the exit.
    while (!queue.empty()) {
        Vertex curr = queue.front();
        queue.pop();

        // Check if we found the exit.
        if (curr == exit) {
            // Backtrack to find the path.
            while (curr.previous != -1) {
                path.push_back(curr.label);
                curr = adjList[curr.previous];
            }
            path.push_back(start.label);
            reverse(path.begin(), path.end());
            return path;
        };

        // Explore neighbors.
        for (int neighborLabel : curr.neighbors) {
            // Only add unvisited neighbors to the queue.
            if (adjList[neighborLabel].visited == false) {
                adjList[neighborLabel].visited = true;
                adjList[neighborLabel].previous = curr.label;
                queue.push(adjList[neighborLabel]);
            };
        };
    };

    return path;
};