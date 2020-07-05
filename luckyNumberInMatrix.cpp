#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            int colMax = INT_MIN, rowOfMax = 0;
            for (int i = 0; i < matrix.size(); i++)
            {
                if (matrix[i][j] > colMax)
                {
                    colMax = matrix[i][j];
                    rowOfMax = i;
                }
            }
            if (colMax == *min_element(matrix[rowOfMax].begin(), matrix[rowOfMax].end()))
                result.push_back(colMax);
        }
        return result;
    }
};