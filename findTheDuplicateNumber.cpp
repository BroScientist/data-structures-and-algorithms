#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int start, int end, int target)
    {
        if (end <= start)
            return false;
        for (int j = start; j <= end; j++)
            if (nums[j] == target)
                return true;
        return false;
    }
    
    int findDuplicate(vector<int>& nums) {
        // for every number, search its left and right for duplicates
        // if found, return number
        if (nums[0] == nums[1])
            return nums[0];
        int dup = 0;
        bool found;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0)
                found = search(nums, 0, i - 1, nums[i]);
            if (!found)
                found = search(nums, i + 1, nums.size() - 1, nums[i]);
            if (found)
            {
                dup = nums[i];
                break;
            }
        }
        return dup;
    }
};

int main() {

    return 0;
}