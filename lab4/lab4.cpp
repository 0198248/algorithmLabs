#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 5;

void fillMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void traverseRows(int matrix[N][N]) {
    cout << "Row traversal:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}

void traverseCols(int matrix[N][N]) {
    cout << "Column traversal:" << endl;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;
}

void spiralTraversal(int matrix[N][N]) {
    cout << "Spiral traversal:" << endl;

    int top = 0;
    int bottom = N - 1;
    int left = 0;
    int right = N - 1;

    while (top <= bottom && left <= right) {

        for (int j = left; j <= right; j++) {
            cout << matrix[top][j] << " ";
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            cout << matrix[i][right] << " ";
        }
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                cout << matrix[bottom][j] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl;
}


int main() {
    srand(time(NULL));

    int matrix[N][N];

    fillMatrix(matrix);

    cout << "Matrix:" << endl;
    printMatrix(matrix);
    cout << endl;

    traverseRows(matrix);
    traverseCols(matrix);
    spiralTraversal(matrix);

    return 0;
}