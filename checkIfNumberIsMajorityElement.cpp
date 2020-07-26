#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int findFirst(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return res;
    }
    
    int findLast(vector<int>& nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        int res = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                res = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return res;
    }
    bool isMajorityElement(vector<int>& nums, int target) {
        int firstIndex = findFirst(nums, target);
        if (firstIndex == -1)
            return false;
        int lastIndex = findLast(nums, target);
        return lastIndex - firstIndex + 1 > nums.size() / 2;
    }
};