class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // there are only 2 edge cases for this question: when size is 1 and when the single element is at the beginning or end
        // I decided to just manually check for these two types of cases to simplify the binary search code
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() >= 3)
        {
            if (nums[0] != nums[1])
                return nums[0];
            if (nums.end()[-1] != nums.end()[-2])
                return nums.end()[-1];
        }
        
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + ((right - left) / 2);
            if (nums[mid - 1] != nums[mid] && nums[mid + 1] != nums[mid])
                return nums[mid];
            int leftLen = mid, rightLen = right - mid;
            if (nums[mid - 1] == nums[mid])
                leftLen--;
            if (nums[mid + 1] == nums[mid])
                rightLen--;
            if (leftLen % 2 != 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return -1;
    }
};