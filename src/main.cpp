#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>
#include <chrono>
#include <iomanip>

using namespace std;

class Graph {
private:
    unordered_map<string, vector<pair<string, int>>> adj;

    void addLocationSilently(const string& name) {
        if (!adj.count(name)) {
            adj[name] = {};
        }
    }

public:

    // Add a new location
    void addLocation(const string& name) {
        if (adj.count(name)) {
            cout << "Location already exists.\n";
        }
        else {
            adj[name] = {};
            cout << "Location added successfully.\n";
        }
    }

    // Add a two-way route
    void addRoute(const string& from, const string& to, int distance) {

        if (distance <= 0) {
            cout << "Distance must be greater than 0.\n";
            return;
        }

        addLocationSilently(from);
        addLocationSilently(to);

        adj[from].push_back({to, distance});
        adj[to].push_back({from, distance});

        cout << "Route added successfully.\n";
    }

    bool hasLocation(const string& name) const {
        return adj.count(name) > 0;
    }

    int locationCount() const {
        return (int)adj.size();
    }

    int routeCount() const {
        int total = 0;

        for (const auto& location : adj) {
            total += (int)location.second.size();
        }

        return total / 2;
    }

    int totalNetworkDistance() const {
        int total = 0;

        for (const auto& location : adj) {
            for (const auto& route : location.second) {
                total += route.second;
            }
        }

        return total / 2;
    }

    // BFS finds the path with the fewest connections
    pair<int, vector<string>> bfsPath(
        const string& start,
        const string& target
    ) const {

        if (!hasLocation(start) || !hasLocation(target)) {
            return {-1, {}};
        }

        queue<string> q;

        unordered_map<string, bool> visited;
        unordered_map<string, string> parent;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {

            string current = q.front();
            q.pop();

            if (current == target) {
                break;
            }

            for (const auto& edge : adj.at(current)) {

                const string& next = edge.first;

                if (!visited[next]) {

                    visited[next] = true;
                    parent[next] = current;

                    q.push(next);
                }
            }
        }

        if (!visited[target]) {
            return {-1, {}};
        }

        vector<string> path;

        string current = target;

        while (current != start) {

            path.push_back(current);
            current = parent[current];
        }

        path.push_back(start);

        reverse(path.begin(), path.end());

        return {(int)path.size() - 1, path};
    }

    // Dijkstra finds the shortest distance
    pair<int, vector<string>> dijkstra(
        const string& start,
        const string& target
    ) const {

        const int INF = numeric_limits<int>::max();

        unordered_map<string, int> distance;
        unordered_map<string, string> parent;

        if (!hasLocation(start) || !hasLocation(target)) {
            return {-1, {}};
        }

        for (const auto& location : adj) {
            distance[location.first] = INF;
        }

        using Node = pair<int, string>;

        priority_queue<
            Node,
            vector<Node>,
            greater<Node>
        > pq;

        distance[start] = 0;

        pq.push({0, start});

        while (!pq.empty()) {

            auto [currentDistance, current] = pq.top();
            pq.pop();

            if (currentDistance != distance[current]) {
                continue;
            }

            if (current == target) {
                break;
            }

            for (const auto& edge : adj.at(current)) {

                const string& next = edge.first;
                int weight = edge.second;

                int newDistance =
                    currentDistance + weight;

                if (newDistance < distance[next]) {

                    distance[next] = newDistance;
                    parent[next] = current;

                    pq.push({
                        newDistance,
                        next
                    });
                }
            }
        }

        if (distance[target] == INF) {
            return {-1, {}};
        }

        vector<string> path;

        string current = target;

        while (current != start) {

            path.push_back(current);
            current = parent[current];
        }

        path.push_back(start);

        reverse(path.begin(), path.end());

        return {distance[target], path};
    }

    // Display complete graph
    void displayNetwork() const {

        cout << "\n========== NETWORK ==========\n";

        vector<string> locations;

        for (const auto& location : adj) {
            locations.push_back(location.first);
        }

        sort(locations.begin(), locations.end());

        for (const string& location : locations) {

            cout << "\n" << location << " -> ";

            auto routes = adj.at(location);

            sort(routes.begin(), routes.end());

            for (const auto& route : routes) {

                cout << route.first
                     << " (" << route.second << " km)  ";
            }

            cout << '\n';
        }

        cout << "=============================\n";
    }
};


// Load the starting network
void loadSampleNetwork(Graph& graph) {

    graph.addRoute("College", "Library", 2);
    graph.addRoute("College", "Hostel", 4);

    graph.addRoute("Library", "Cafeteria", 1);
    graph.addRoute("Library", "Main Gate", 5);

    graph.addRoute("Hostel", "Cafeteria", 2);
    graph.addRoute("Hostel", "Sports Ground", 3);

    graph.addRoute("Cafeteria", "Main Gate", 4);

    graph.addRoute("Sports Ground", "Main Gate", 2);

    graph.addRoute("Main Gate", "Bus Stop", 1);

    graph.addRoute("Bus Stop", "Railway Station", 6);
}


// Print a path nicely
void printPath(const vector<string>& path) {

    for (size_t i = 0; i < path.size(); i++) {

        cout << path[i];

        if (i + 1 < path.size()) {
            cout << " -> ";
        }
    }
}


// Find shortest route using Dijkstra
void findShortestRoute(const Graph& graph) {

    string start;
    string target;

    cout << "\nEnter starting location: ";
    getline(cin >> ws, start);

    cout << "Enter destination: ";
    getline(cin, target);

    if (!graph.hasLocation(start) ||
        !graph.hasLocation(target)) {

        cout << "\nLocation not found.\n";
        return;
    }

    auto result =
        graph.dijkstra(start, target);

    if (result.first == -1) {

        cout << "\nNo route exists.\n";
        return;
    }

    cout << "\n========== SHORTEST ROUTE ==========\n";

    cout << "Algorithm: Dijkstra's Algorithm\n";

    cout << "Distance: "
         << result.first
         << " km\n";

    cout << "Stops: "
         << result.second.size() - 1
         << "\n";

    cout << "Route: ";

    printPath(result.second);

    cout << "\n=====================================\n";
}


// Compare BFS and Dijkstra
void compareAlgorithms(const Graph& graph) {

    string start;
    string target;

    cout << "\nEnter starting location: ";
    getline(cin >> ws, start);

    cout << "Enter destination: ";
    getline(cin, target);

    if (!graph.hasLocation(start) ||
        !graph.hasLocation(target)) {

        cout << "\nLocation not found.\n";
        return;
    }

    auto startBFS =
        chrono::high_resolution_clock::now();

    auto bfs =
        graph.bfsPath(start, target);

    auto endBFS =
        chrono::high_resolution_clock::now();


    auto startDijkstra =
        chrono::high_resolution_clock::now();

    auto dijkstra =
        graph.dijkstra(start, target);

    auto endDijkstra =
        chrono::high_resolution_clock::now();


    double bfsTime =
        chrono::duration<double, micro>(
            endBFS - startBFS
        ).count();


    double dijkstraTime =
        chrono::duration<double, micro>(
            endDijkstra - startDijkstra
        ).count();


    cout << "\n========== ALGORITHM COMPARISON ==========\n";


    cout << "\nBFS";

    cout << "\nConnections: "
         << bfs.first;

    cout << "\nPath: ";

    printPath(bfs.second);

    cout << "\nTime: "
         << fixed
         << setprecision(3)
         << bfsTime
         << " microseconds\n";


    cout << "\nDijkstra";

    cout << "\nDistance: "
         << dijkstra.first
         << " km";

    cout << "\nPath: ";

    printPath(dijkstra.second);

    cout << "\nTime: "
         << fixed
         << setprecision(3)
         << dijkstraTime
         << " microseconds\n";


    cout << "\n\nBFS minimizes the number of edges.";

    cout << "\nDijkstra minimizes total positive edge weight.";

    cout << "\n==========================================\n";
}


// Show graph statistics
void showStatistics(const Graph& graph) {

    cout << "\n========== NETWORK STATISTICS ==========\n";

    cout << "Locations: "
         << graph.locationCount()
         << '\n';

    cout << "Routes: "
         << graph.routeCount()
         << '\n';

    cout << "Total route distance: "
         << graph.totalNetworkDistance()
         << " km\n";


    cout << "\nDijkstra: O((V + E) log V) time, O(V + E) space";

    cout << "\nBFS:      O(V + E) time, O(V) space\n";

    cout << "=========================================\n";
}


int main() {

    Graph graph;

    loadSampleNetwork(graph);


    int choice;


    cout << "========================================\n";

    cout << "        SMART ROUTE FINDER V2           \n";

    cout << "       DSA Route Optimization Tool       \n";

    cout << "========================================\n";


    while (true) {

        cout << "\n1. Find Shortest Route";

        cout << "\n2. Add Location";

        cout << "\n3. Add Route";

        cout << "\n4. View Network";

        cout << "\n5. Compare BFS vs Dijkstra";

        cout << "\n6. View Network Statistics";

        cout << "\n7. Exit";


        cout << "\n\nEnter choice: ";

        cin >> choice;


        if (choice == 1) {

            findShortestRoute(graph);

        }

        else if (choice == 2) {

            string name;

            cout << "\nEnter new location name: ";

            getline(cin >> ws, name);

            graph.addLocation(name);

        }

        else if (choice == 3) {

            string from;
            string to;
            int distance;


            cout << "\nFrom: ";

            getline(cin >> ws, from);


            cout << "To: ";

            getline(cin, to);


            cout << "Distance (km): ";

            cin >> distance;


            graph.addRoute(
                from,
                to,
                distance
            );
        }

        else if (choice == 4) {

            graph.displayNetwork();

        }

        else if (choice == 5) {

            compareAlgorithms(graph);

        }

        else if (choice == 6) {

            showStatistics(graph);

        }

        else if (choice == 7) {

            cout << "\nThank you for using Smart Route Finder V2!\n";

            return 0;
        }

        else {

            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}