class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, n = nums.size();
        // start from index 0, expand until a second zero is reached
        int lastZeroIndex = -1, zeroCount = 0;

        for (int start = lastZeroIndex + 1; start < n; start++)
        {
            int len = 0, i = start;
            while (zeroCount != 2 && i != n)
            {
                if (nums[i] == 0)
                {
                    // if this is the first zero encountered, set lastZeroIndex and increment len
                    if (zeroCount == 0)
                        lastZeroIndex = i, len++;
                    zeroCount++;
                }
                // otherwise just increment len
                else
                    len++;
                i++;
            }
            maxLen = max(maxLen, len);
            // if the last index is ever reached, terminate the search immediately
            if (i >= n - 1)
                return maxLen;
            zeroCount = 0;
        }
        return maxLen;
    }
};