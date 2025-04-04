
#include "bellman.h"

// Hàm thực hiện một bước của thuật toán Bellman-Ford
void BF(int graph[20][20], int numVertices,char startVertex,  int BFValue[], int BFPrev[]) {
    // Khởi tạo giá trị ban đầu cho đỉnh A (index 0)
    switch (startVertex)
    {
    case 'A':
        BFValue[0] = 0;
        BFPrev[0] = -1;
        break;
    case 'B':
        BFValue[1] = 0;
        BFPrev[1] = -1;
        break;
    case 'C':
        BFValue[2] = 0;
        BFPrev[2] = -1;
        break;
    case 'D':
        BFValue[3] = 0;
        BFPrev[3] = -1;
        break;
    case 'E':
        BFValue[4] = 0;
        BFPrev[4] = -1;
        break;
    case 'F':
        BFValue[5] = 0;
        BFPrev[5] = -1;
        break;
    case 'G':
        BFValue[6] = 0;
        BFPrev[6] = -1;
        break;
    case 'H':
        BFValue[7] = 0;
        BFPrev[7] = -1;
        break;
    }
    
    for (int u = 0; u < numVertices; ++u) {
        //if (BFValue[u] == -1) continue; // Bỏ qua nếu chưa được ghé thăm
        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] != 0) { // Có cạnh
                if (BFValue[v] == -1 || BFValue[u] + graph[u][v] < BFValue[v]) {
                    BFValue[v] = BFValue[u] + graph[u][v];
                    BFPrev[v] = u;
                }
            }
        }
    }
}
string BF_Path(int graph[20][20], int numVertices, char startVertex, char goalVertex) {
    int BFValue[20];
    int BFPrev[20];
    memset(BFValue, -1, sizeof(BFValue));
    memset(BFPrev, -1, sizeof(BFPrev));

    // Thực hiện thuật toán Bellman-Ford cho tất cả các đỉnh
    for (int i = 0; i < numVertices; ++i) {
        BF(graph, numVertices, startVertex, BFValue, BFPrev);
    }

    // Tạo đường đi ngắn nhất từ goalVertex về startVertex
    vector<char> path;
    int current = goalVertex - 'A';
    while (current != -1) {
        path.push_back(current + 'A');
        current = BFPrev[current];
    }

    // Đảo ngược đường đi để có đường đi từ startVertex đến goalVertex
    if (path.back() != startVertex) {
        return "No path"; // Không có đường đi từ startVertex đến goalVertex
    }

    string result;
    for (int i = path.size() - 1; i >= 0; --i) {
        result += path[i];
        if (i > 0) result += " -> ";
    }

    return result;
}

int main() {
    int G[20][20] = {0}; // Khởi tạo ma trận 20x20 với giá trị 0
    int BFValue[20];
    int BFPrev[20];
    ifstream fin;

    // Đọc ma trận đầu tiên từ inMat1.txt
    fin.open("inMat1.txt");
    int n = 8; // Số lượng đỉnh


    for (int i = 0; i < n; i++) {
        BFValue[i] = -1;
        BFPrev[i] = -1;
        for (int j = 0; j < n; j++) {
            fin >> G[i][j];
        }
    }
    fin.close();

    

    // Thực hiện các bước của thuật toán Bellman-Ford
    for (int i = 0; i < n; i++) {
        BF(G, n,'D', BFValue, BFPrev);

        cout << "step" << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            cout << BFValue[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < n; j++) {
            cout << BFPrev[j] << " ";
        }
        cout << endl;
    }
    int numVertices = 5;
    char startVertex = 'A';
    char goalVertex = 'C';
    string path = BF_Path(G, numVertices, startVertex, goalVertex);
    cout << "Shortest path from " << startVertex << " to " << goalVertex << ": " << path << endl;

    return 0;
}
