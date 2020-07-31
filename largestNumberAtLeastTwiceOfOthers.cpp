#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        pair<int,int> maxNum = make_pair(INT_MIN, 0);
        pair<int,int> secondMax = make_pair(INT_MIN, 0);
        
        // find the largest and second largest number in the array
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxNum.first)
            {
                secondMax = make_pair(maxNum.first, maxNum.second);
                maxNum = make_pair(nums[i], i);
            }
            else if (nums[i] > secondMax.first)
                secondMax = make_pair(nums[i], i);
        }
        
        // if max number is at least twice as large as second largest, return the index of max, else return -1
        return maxNum.first >= secondMax.first * 2 ? maxNum.second : -1;
    }
};
