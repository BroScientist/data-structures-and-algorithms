#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // vector<vector<int>> res;
        for (int i = 0; i < mat.size(); i++)
        {        
            for (int j = 0; j < mat[0].size(); j++)
            {
                vector<int> nums;
                for (int row = i, col = j; row < mat.size() && col < mat[0].size(); row++, col++)
                {
                    nums.push_back(mat[row][col]);
                    // cout << mat[row][col];
                }
                sort(begin(nums), end(nums));
                int index = 0;
                for (int row = i, col = j; row < mat.size() && col < mat[0].size(); row++, col++)
                {
                    mat[row][col] = nums[index++];
                }
                // cout << endl;
            }
        }
        return mat;
    }
};

int main() {

    return 0;
}