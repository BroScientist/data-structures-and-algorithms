#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (r * c > nums.size() * nums[0].size())
            return nums;

        vector<vector<int>> res(r, vector<int>(c));
        vector<int> flattened;
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < nums[0].size(); j++)
                flattened.push_back(nums[i][j]);

        int index = 0;
        for (int i = 0; i < res.size(); i++)
            for (int j = 0; j < res[0].size(); j++)
                res[i][j] = flattened[index++];
                
        return res;
    }
};

int main() {

    return 0;
}