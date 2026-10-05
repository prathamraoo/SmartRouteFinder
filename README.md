# Smart Route Finder

Smart Route Finder is a small C++ project I built to practice Data Structures and Algorithms by putting them into a working application.

The idea is simple: different places are connected by routes, and the program helps find the best way to travel between them.

I mainly used Dijkstra's Algorithm to find the shortest route based on distance. I also added BFS so I could compare the two approaches when looking for a route.

## What the Program Can Do

- Find the shortest route between two locations
- Show the total distance
- Show the complete route
- Show the number of connections
- Add new locations
- Add routes and distances
- Display the current network
- Compare BFS and Dijkstra
- Show basic network statistics

## How I Built It

The project represents the locations and routes as a **weighted graph**.

Some of the main concepts I used are:

- Graphs
- Adjacency Lists
- Dijkstra's Algorithm
- Breadth-First Search (BFS)
- Priority Queue / Min Heap
- `unordered_map`
- Path reconstruction

I used an adjacency list because each location only needs to store the locations directly connected to it.

## Example

For example, if I ask the program to find a route from:

```text
College
to:

Railway Station

it finds:

Distance: 14 km
Stops: 4
Route: College -> Library -> Main Gate -> Bus Stop -> Railway Station

The program can also compare BFS and Dijkstra for the same locations.

In this example, both algorithms find the same path, but they are solving slightly different problems:

BFS focuses on the number of connections.
Dijkstra focuses on the total distance.
Locations in the Example Network

The starting network contains:

College
Library
Hostel
Cafeteria
Sports Ground
Main Gate
Bus Stop
Railway Station

I also made it possible to add new locations and routes while the program is running.

Program Menu
1. Find Shortest Route
2. Add Location
3. Add Route
4. View Network
5. Compare BFS vs Dijkstra
6. View Network Statistics
7. Exit
Complexity

For Dijkstra using an adjacency list and a min-heap:

Time:  O((V + E) log V)
Space: O(V + E)

For BFS:

Time:  O(V + E)
Space: O(V)

Here:

V = number of locations
E = number of routes

The program also shows the execution time of BFS and Dijkstra. Since this project uses a small graph, those timings are mainly useful for seeing the comparison rather than for serious performance testing.

Running the Project

I used C++17 for this project.

Windows / MSYS2
g++ -std=c++17 src/main.cpp -o SmartRouteFinder.exe
./SmartRouteFinder.exe
Linux / macOS
g++ -std=c++17 src/main.cpp -o SmartRouteFinder
./SmartRouteFinder
Project Structure
SmartRouteFinder/
├── src/
│   └── main.cpp
├── README.md
├── sample_output.txt
├── route-comparison.png
└── .gitignore
<img width="831" height="524" alt="route-comparison png" src="https://github.com/user-attachments/assets/9ce797ab-e900-423c-8c09-ed60ac9a9ca1" />

What I Learned

This project helped me understand graphs much better because I could actually see the algorithms working instead of only solving questions on paper.

While building it, I practiced:

Creating and working with graphs
Using adjacency lists
Implementing Dijkstra
Implementing BFS
Working with priority queues
Reconstructing paths
Comparing algorithms
Thinking about time and space complexity
Handling user input in C++
Future Ideas

If I continue working on this project, I would like to add:

A graphical map
A* pathfinding
Traffic-based route distances
Saving routes to a file
CSV or JSON input
Route history
