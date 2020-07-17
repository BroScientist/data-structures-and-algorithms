#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        vector<vector<int>> matrix(A[0].size(), vector<int>(A.size()));
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                matrix[j][i] = A[i][j];
            }
        }
        return matrix;
    }
};

int main() {

    return 0;
}