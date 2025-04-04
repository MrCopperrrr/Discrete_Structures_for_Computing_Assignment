// Đây là file chính của chương trình
#include "bellman.h"

//Hàm main làm giống hàm main trên bkel
int main() {
    int G[20][20] = {0}; // Khởi tạo ma trận 20x20 với giá trị 0
    int BFValue[20];
    int BFPrev[20];
    ifstream fin;

    // Đọc ma trận đầu tiên từ inMat1.txt
    fin.open("inMat1.txt");                             //có thể thay đổi thành inMat2.txt 
    int n = 8;                                          // Số lượng đỉnh có thể thay đổi

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
        BF(G, n,'D', BFValue, BFPrev);                   //Có thể đổi đỉnh bắt đầu

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
    int numVertices = 5;                        // Số lượng đỉnh có thể thay đổi
    char startVertex = 'A';                     // Đỉnh bắt đầu
    char goalVertex = 'C';                      // Đỉnh kết thúc
    string path = BF_Path(G, numVertices, startVertex, goalVertex);
    cout << "Shortest path from " << startVertex << " to " << goalVertex << ": " << path << endl;

    return 0;
}