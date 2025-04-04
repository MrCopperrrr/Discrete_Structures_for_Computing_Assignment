
#include "tsm.h"

int main() {
    int G[20][20];
    ifstream fin("inMat4.txt");
    int n = 12; // Number of vertices

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> G[i][j];
        }
    }
    

    string output = Traveling(G, n, 'A');
    int cost = pathlength(G, n, output);
    double partile = 0.1;

    if ((354 - 354 * partile) <= cost && cost <= (354 + 354 * partile)) {
        cout << "your output is at least 90% correct" << endl;
    }
    fin.close();
    return 0;
}
