#ifndef TSM_H
#define TSM_H

#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

string Traveling(int graph[20][20], int numVertices, char startVertex);
int pathlength(int graph[20][20], int numVertices, const string &path);

#endif // TSM_H
