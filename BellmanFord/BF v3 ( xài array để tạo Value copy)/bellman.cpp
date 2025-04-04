
#include "bellman.h"

//Bellman-Ford (1 step)
void BF(int graph[20][20], int numVertices, char startVertex,  int BFValue[], int BFPrev[]) {
    // Khởi tạo giá trị của đỉnh startVertex là 0
    int start = startVertex - 'A';
    BFValue[start] = 0;
    
    // Copy giá trị của BFValue để thực hiện bài toán
    int copyBFValue[numVertices];
    for (int i = 0; i < numVertices; i++) {     // Copy giá trị của BFValue
        copyBFValue[i] = BFValue[i];
    }

    for (int u = 0; u < numVertices; ++u) {     // Duyệt qua tất cả các đỉnh
        if (copyBFValue[u] != -1) {             // Nếu đỉnh u đã được gán giá trị
            //cout << "u: " << u << endl;

            for (int v = 0; v < numVertices; ++v) { // Duyệt qua tất cả các đỉnh kề của u
                //cout << "   v: " << v ;
                if (graph[u][v] != 0 && BFValue[v] == -1) {     // Có cạnh
                    BFValue[v] = copyBFValue[u] + graph[u][v];
                        //cout << "       BFValue[v]: " << BFValue[v];

                    BFPrev[v] = u;
                        //cout << "       BFPrev[v]: " << BFPrev[v] << endl;  
                }
                else if(graph[u][v] != 0 && BFValue[v] > copyBFValue[u] + graph[u][v]){     // Có cạnh và có giá trị nhỏ hơn
                    BFValue[v] = copyBFValue[u] + graph[u][v];
                        //cout << "       BFValue[v]: " << BFValue[v];

                    BFPrev[v] = u;
                        //cout << "       BFPrev[v]: " << BFPrev[v] << endl;  
                }
            }
        }  
    }
}

//Bellman-Ford Path
string BF_Path(int graph[20][20], int numVertices, char startVertex, char goalVertex) { // Tìm đường đi ngắn nhất từ startVertex đến goalVertex
    int BFValue[20];    // Mảng lưu giá trị ngắn nhất từ startVertex đến các đỉnh khác
    int BFPrev[20];    // Mảng lưu đỉnh trước đỉnh hiện tại trên đường đi ngắn nhất
    memset(BFValue, -1, sizeof(BFValue)); // Khởi tạo giá trị của BFValue là -1
    memset(BFPrev, -1, sizeof(BFPrev)); // Khởi tạo giá trị của BFPrev là -1
    //memset(void *ptr, int value, size_t num); //Đặt 1 giá trị cho 1 phần của bộ nhớ

    // Thực hiện thuật toán Bellman-Ford từ startVertex đến tất cả các đỉnh còn lại
    for (int i = 0; i < numVertices; ++i) {
        BF(graph, numVertices, startVertex, BFValue, BFPrev);
    }

    // Tạo đường đi ngắn nhất từ goalVertex về startVertex
    vector<char> path;  // Lưu đường đi ngắn nhất từ startVertex đến goalVertex
    int current = goalVertex - 'A'; // Đỉnh hiện tại trên đường đi ngắn nhất
    while (current != -1) { // Duyệt từ goalVertex về startVertex
        path.push_back(current + 'A');  // Thêm đỉnh hiện tại vào đường đi
        current = BFPrev[current];
    }

    // Đảo ngược đường đi để có đường đi từ startVertex đến goalVertex
    if (path.back() != startVertex) {
        return "No path"; // Không có đường đi từ startVertex đến goalVertex
    }

    string result;
    for (int i = path.size() - 1; i >= 0; --i) {    // In ra đường đi ngắn nhất từ startVertex đến goalVertex
        result += path[i];
        if (i > 0) result += " ";
    }

    return result;
}

int main() {
    int G[20][20] = {0}; // Khởi tạo ma trận 20x20 với giá trị 0
    int BFValue[20];
    int BFPrev[20];
    ifstream fin;

    // Đọc ma trận đầu tiên từ inMat1.txt
    fin.open("inMat1.txt");     //có thể thay đổi thành inMat2.txt 
    int n = 8;      // Số lượng đỉnh có thể thay đổi

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
        BF(G, n,'D', BFValue, BFPrev);      //Có thể đổi đỉnh bắt đầu

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
