#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFirst(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int index = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                // if target has been found, try to look to the left of the array for a smaller index
                index = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return index;
    }

    int findLast(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int index = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                // if target has been found, try to look to the left of the array for a larger index
                index = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0] = findFirst(nums, target);
        res[1] = findLast(nums, target);
        return res;
    }
};