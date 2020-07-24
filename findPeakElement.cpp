#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        // traverse the array, check last and next element
        for (int i = 0; i < nums.size(); i++)
        {
            int prev = i == 0 ? INT_MIN : nums[i-1];
            int next = i == nums.size() - 1 ? INT_MIN : nums[i+1];
            if (nums[i] > prev && nums[i] > next)
                return i;            
        }
        return -1;
    }
};
