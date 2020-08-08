#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findInflection(vector<int>& nums)
    {
        int low = 0, high = nums.size() - 1;
        if (nums[high] > nums[0])
            return 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid + 1] < nums[mid])
                return mid + 1;
            if (nums[mid - 1] > nums[mid])
                return mid;
            if (nums[mid] > nums[0])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int target, int left, int right)
    {
        int low = left, high = right;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        // edge cases where array is empty or has only 1 element
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        
        // start by finding the inflection index in the rotated array
        int inflection = findInflection(nums);
        
        // if this index is -1, it means the array is already sorted and we can just do a normal binary search
        if (inflection == -1)
            return binarySearch(nums, target, 0, nums.size() - 1);
        
        // otherwise, search from start to inflection index - 1 and inflection index to end
        // this works because the these are two sorted subarrays
        int leftSearch = binarySearch(nums, target, 0, inflection - 1);
        if (leftSearch != -1)
            return leftSearch;
        int rightSearch = binarySearch(nums, target, inflection, nums.size() - 1);
        if (rightSearch != -1)
            return rightSearch;
        
        return -1;
    }
};
