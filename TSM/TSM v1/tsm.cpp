#include "tsm.h"

//Traveling Salesman
string Traveling(int graph[20][20], int numVertices, char startVertex) {    //
    int start = startVertex - 65; // chỉ số đỉnh bắt đầu
    

    vector<int> vertices;
    for (int i = 0; i < numVertices; i++) {
        if (i != (startVertex - 'A')) {
            vertices.push_back(i);
        }
    }

    int min_path = INT_MAX;
    vector<int> best_path;

    do {
        int current_weight = 0;
        int k = startVertex - 'A';
        for (int i = 0; i < vertices.size(); i++) {
            current_weight += graph[k][vertices[i]];
            k = vertices[i];
        }
        current_weight += graph[k][startVertex - 'A'];

        if (current_weight < min_path) {
            min_path = current_weight;
            best_path = vertices;
        }
    } while (next_permutation(vertices.begin(), vertices.end()));

    stringstream path_stream;
    path_stream << startVertex << " ";
    for (int i : best_path) {
        path_stream << static_cast<char>('A' + i) << " ";
    }
    path_stream << startVertex;

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
