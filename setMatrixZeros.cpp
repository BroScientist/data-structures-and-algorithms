#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // traverse the matrix and record where the 0s are
        // store these as pairs of row and col
        vector<pair<int,int>> indexes;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0)
                    indexes.push_back(make_pair(i, j));
        // for (auto& item : indexes)
        //     cout << item.first << ", " << item.second << endl;

        // go through these pairs and change the corresponding rows and cols of the matrix
        for (auto& index : indexes)
        {
            int row = index.first, col = index.second;
            for (int j = 0; j < matrix[row].size(); j++)
                matrix[row][j] = 0;
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][col] = 0;
        }

    }
};

int main() {

    return 0;
}