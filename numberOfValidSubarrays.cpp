#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int count = nums.size();
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[i])   
                    break;
                count++;
            }
        }
        return count;
    }
};