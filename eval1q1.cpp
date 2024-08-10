#include <bits/stdc++.h>
using namespace std;


int determinant2x2(const vector<vector<int>>& mat) {
    return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}

int determinant3x3(const vector<vector<int>>& mat) {
    return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
         - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
         + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

vector<vector<int>> getMinor(const vector<vector<int>>& mat, int row, int col) {
    vector<vector<int>> minor(mat.size() - 1, vector<int>(mat.size() - 1));
    int minorRow = 0, minorCol = 0;
    for (int i = 0; i < mat.size(); ++i) {
        if (i == row) continue;
        minorCol = 0;
        for (int j = 0; j < mat.size(); ++j) {
            if (j == col) continue;
            minor[minorRow][minorCol++] = mat[i][j];
        }
        ++minorRow;
    }
    return minor;
}

int determinant(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 2) return determinant2x2(mat);
    if (n == 3) return determinant3x3(mat);

    int det = 0;
    for (int j = 0; j < n; ++j) {
        vector<vector<int>> minor = getMinor(mat, 0, j);
        det += (j % 2 == 0 ? 1 : -1) * mat[0][j] * determinant(minor);
    }
    return det;
}

int main() {
    int size;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> size;
    vector<vector<int>> matrix(size, vector<int>(size));
    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }
    int det = determinant(matrix);
    cout << "The determinant of the matrix is: " << det << endl;

    return 0;
}
