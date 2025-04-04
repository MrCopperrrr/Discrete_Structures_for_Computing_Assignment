#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>
#include <algorithm>
#include "bellman.h"
#include "tsm.h"

using namespace std;

// Ma trận Bellman-Ford
int G1[20][20] = {
    {0, 72, 89, 77, 2, 58, 13, 69},
    {77, 0, 69, 31, 57, 93, 83, 48},
    {52, 21, 0, 62, 8, 77, 32, 14},
    {33, 1, 40, 0, 72, 99, 72, 59},
    {89, 24, 1, 61, 0, 12, 78, 63},
    {36, 91, 98, 79, 26, 0, 28, 1},
    {18, 77, 49, 36, 98, 77, 0, 45},
    {75, 9, 59, 7, 77, 65, 45, 0}
};

// Ma trận Traveling Salesman
int G2[20][20] = {
    {0, 17, 40, 100, 32, 11, 29, 77, 73, 53, 52, 72},
    {48, 0, 23, 42, 81, 5, 12, 37, 31, 55, 18, 66},
    {48, 97, 0, 74, 21, 43, 8, 37, 48, 13, 55, 88},
    {79, 53, 66, 0, 8, 97, 38, 61, 48, 76, 75, 71},
    {18, 56, 42, 97, 0, 59, 40, 51, 77, 5, 65, 39},
    {45, 86, 82, 20, 23, 0, 96, 100, 44, 84, 45, 97},
    {15, 53, 93, 53, 80, 7, 0, 29, 21, 78, 13, 43},
    {87, 9, 1, 26, 26, 44, 98, 0, 92, 49, 9, 77},
    {30, 29, 66, 93, 28, 9, 76, 73, 0, 73, 91, 92},
    {31, 9, 38, 38, 38, 25, 83, 17, 68, 0, 69, 93},
    {35, 61, 19, 45, 24, 10, 94, 33, 53, 90, 0, 62},
    {19, 82, 57, 95, 57, 96, 67, 13, 54, 65, 90, 0}
};



int main() {
    cout << "Bellman-Ford Algorithm:" << endl;
    {
        int numVertices = 8;
        int BFValue[20];
        int BFPrev[20];
    
        // Initialize BFValue and BFPrev
        for (int i = 0; i < numVertices; i++) {
            BFValue[i] = -1;
            BFPrev[i] = -1;
        }

        // Perform Bellman-Ford algorithm
        for (int i = 0; i < numVertices; i++) {
            BF(G1, numVertices, 'D', BFValue, BFPrev);

            cout << "Step " << i + 1 << ":" << endl;
            for (int j = 0; j < numVertices; j++) {
                cout << BFValue[j] << " ";
            }
            cout << endl;
            for (int j = 0; j < numVertices; j++) {
                cout << BFPrev[j] << " ";
            }
            cout << endl;
        }

        int numVerticesPath = 5;
        char startVertex = 'A';
        char goalVertex = 'C';
        string path = BF_Path(G1, numVerticesPath, startVertex, goalVertex);
        cout << "Shortest path from " << startVertex << " to " << goalVertex << ": " << path << endl;
    }

    cout << "Traveling Salesman Algorithm:" << endl;
    {
        int numVertices = 12;
        string output = Traveling(G2, numVertices, 'A');
        int cost = pathlength(G2, numVertices, output);
        double partile = 0.00;

        if ((204 - 204 * partile) <= cost && cost <= (204 + 204 * partile)) {
            cout << "Your output is correct" << endl;
        }
    }

    return 0;
}
