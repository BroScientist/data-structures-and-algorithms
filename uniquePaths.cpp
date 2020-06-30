#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    // initialize a m by n 2d vector with default value of 1
    vector<vector<int>> matrix;
    matrix.resize(m, vector<int>(n, 1));
    // starting from the second row and second column (index of 1), loop over every matrix cell
    // set cell[row][col] equal to cell[row-1][col] + cell[row][col-1]
    for (int row = 1; row < matrix.size(); row++)
    {
        for (int col = 1; col < matrix[0].size(); col++)
        {
            matrix[row][col] = matrix[row-1][col] + matrix[row][col-1];
        }
    }
    return matrix[m-1][n-1];
}

int main() {
    uniquePaths(3, 2);
    uniquePaths(13, 15);
    
    return 0;
}