#include "tsm.h"

const int INF = INT_MAX;

int tsp(int graph[20][20], int pos, int visited, vector<vector<int>>& dp, vector<vector<int>>& parent, int numVertices) {
    if (visited == ((1 << numVertices) - 1)) {
        return graph[pos][0] == 0 ? INF : graph[pos][0]; // Return to start point
    }

    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }

    int ans = INF;
    for (int city = 0; city < numVertices; city++) {
        if ((visited & (1 << city)) == 0 && graph[pos][city] != 0) { // Chỉ đi qua các cạnh có hướng (có trọng số)
            int newAns = graph[pos][city] + tsp(graph, city, visited | (1 << city), dp, parent, numVertices);
            if (newAns < ans) {
                ans = newAns;
                parent[pos][visited] = city; // Save the parent (next city) in the path
            }
        }
    }

    return dp[pos][visited] = ans;
}

string Traveling(int graph[20][20], int numVertices, char startVertex) {
    vector<vector<int>> dp(numVertices, vector<int>(1 << numVertices, -1));
    vector<vector<int>> parent(numVertices, vector<int>(1 << numVertices, -1));
    int start = startVertex - 'A';
    int cost = tsp(graph, start, 1 << start, dp, parent, numVertices);

    // Reconstruct the path from the parent table
    vector<int> path;
    int visited = 1 << start;
    int pos = start;
    path.push_back(pos);

    while (true) {
        int nextPos = parent[pos][visited];
        if (nextPos == -1) break;
        pos = nextPos;
        visited |= (1 << pos);
        path.push_back(pos);
    }
    path.push_back(start); // Complete the cycle

    // Convert the path to a string
    stringstream path_stream;
    for (int i : path) {
        path_stream << static_cast<char>('A' + i) << " ";
    }

    return path_stream.str();
}

int pathlength(int graph[20][20], int numVertices, const string &path) {
    istringstream path_stream(path);
    vector<char> vertices;
    char vertex;
    while (path_stream >> vertex) {
        vertices.push_back(vertex);
    }

    int total_length = 0;
    for (size_t i = 0; i < vertices.size() - 1; ++i) {
        int u = vertices[i] - 'A';
        int v = vertices[i + 1] - 'A';
        total_length += graph[u][v];
    }
    return total_length;
}
