# Smart Route Finder

A C++ DSA project that models locations as a weighted graph and finds the shortest route between two locations.

## Why this project?

This project demonstrates practical use of core Data Structures and Algorithms rather than implementing isolated problems.

## DSA Concepts Used

- **Graph** - represents locations and routes
- **Adjacency List** - stores connected locations efficiently
- **Dijkstra's Algorithm** - finds the minimum-distance route
- **Priority Queue / Min Heap** - efficiently selects the next closest location
- **BFS** - calculates the minimum number of connections
- **Hash Map (`unordered_map`)** - provides fast location lookup
- **Path Reconstruction** - rebuilds the actual shortest route using parent pointers
- **Sorting** - makes network output easier to read

## Features

1. Find the shortest route between two locations
2. Display total distance
3. Display the route step-by-step
4. Display number of connections
5. Add custom routes while the program is running
6. Display the complete network

## Example

For:

`College -> Railway Station`

The program may produce:

```text
Distance: 12 km
Route: College -> Hostel -> Sports Ground -> Main Gate -> Bus Stop -> Railway Station
Connections: 5
```

## Complexity

For Dijkstra using an adjacency list and binary min-heap:

- Time: **O((V + E) log V)**
- Space: **O(V + E)**

Where:
- `V` = number of locations
- `E` = number of routes

BFS:

- Time: **O(V + E)**
- Space: **O(V)**

## How to Run

### Windows with MinGW

Open a terminal inside the project folder:

```bash
g++ -std=c++17 src/main.cpp -o SmartRouteFinder
SmartRouteFinder.exe
```

### Linux / macOS

```bash
g++ -std=c++17 src/main.cpp -o SmartRouteFinder
./SmartRouteFinder
```

## Suggested GitHub Repository Name

`smart-route-finder-dsa`

## CV Description

**Smart Route Finder — C++ / Data Structures & Algorithms**

- Built a graph-based route optimization system using adjacency lists and Dijkstra's shortest-path algorithm.
- Implemented a priority queue, hash maps, BFS, and path reconstruction to efficiently calculate and display optimal routes.
- Added dynamic route creation and network visualization through a command-line interface.
- Applied time and space complexity analysis to evaluate algorithm performance.

## Future Improvements

- Add a graphical map interface
- Import locations from CSV/JSON
- Add traffic weights
- Add A* pathfinding
- Compare Dijkstra vs BFS vs A*
- Store route history
