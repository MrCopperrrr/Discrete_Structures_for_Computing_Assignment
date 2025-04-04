#ifndef BELLMAN_H // include guard
#define BELLMAN_H

// Include thư viện cần thiết
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <climits>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Hàm khai báo
void BF(int graph[20][20], int numVertices, char startVertex, int BFValue[], int BFPrev[]);
string BF_Path(int graph[20][20], int numVertices, char startVertex, char goalVertex);

#endif
