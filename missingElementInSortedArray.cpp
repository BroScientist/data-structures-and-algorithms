#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int prev = nums[0]; // don't forget special case: first is missing
        int missing = -1, i = 1;
        while (1)
        {
            if (nums[i] != prev + 1)
            {
                k--;
                if (k == 0)
                    return prev + 1;
                prev++;
            }
            else
            {
                prev = nums[i];
                i++;
            }
        }
        return 0;
    }
};