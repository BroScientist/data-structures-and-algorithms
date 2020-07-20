#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
        {        
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int num = matrix[i][j];
                for (int row = i, col = j; row < matrix.size() && col < matrix[0].size(); row++, col++)
                {
                    if (matrix[row][col] != num)
                        return false;
                    // cout << mat[row][col];
                }
            }
        }
        return true;
    }
};

int main() {

    return 0;
}