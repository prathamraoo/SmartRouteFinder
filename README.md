# Smart Route Finder

A simple C++ project that uses Data Structures and Algorithms to find routes between different locations.

The project represents locations as a graph and uses Dijkstra's Algorithm to find the shortest route based on distance. It also uses BFS to find a route with the minimum number of connections.

I built this project to understand how graph algorithms can be used in a practical problem instead of only solving individual DSA questions.

## Features

- Find the shortest route between two locations
- Calculate the total distance
- Show the complete route step-by-step
- Show the number of connections/stops
- Add new locations while the program is running
- Add new routes with custom distances
- Display the complete network
- Compare BFS and Dijkstra
- Display network statistics
- Reconstruct and display the actual path taken

## DSA Concepts Used

### Graph

Locations are represented as vertices and routes between them are represented as edges.

### Adjacency List

An adjacency list is used to store the routes connected to each location.

### Dijkstra's Algorithm

Dijkstra's Algorithm is used to find the route with the minimum total distance.

### Priority Queue

A min-heap priority queue is used by Dijkstra's Algorithm to process the closest location first.

### BFS

Breadth-First Search is used to find a route with the minimum number of connections.

### Hash Map

`unordered_map` is used for storing and quickly finding locations in the graph.

### Path Reconstruction

Parent information is stored while searching so the program can rebuild the complete route from the destination back to the starting location.

## Example

For example, if we search for a route from:

```text
College
