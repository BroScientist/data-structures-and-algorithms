#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        // initialize a matrix with n rows and m columns with default value of 0
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (vector<int>& vec : indices)
        {
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[vec[0]][j]++;
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][vec[1]]++;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << matrix[i][j];
        //     }
        //     cout << endl;
        // }
        int count = 0;
        for (int row = 0; row < matrix.size(); row++)
            for (int col = 0; col < matrix[0].size(); col++)
                if (matrix[row][col] % 2 != 0)
                    count++;
        return count;
    }
};