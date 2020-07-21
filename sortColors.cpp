#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int zeros = 0, ones = 0, twos = 0;
    for (int& n : nums)
    {
        if (n == 0)
            zeros++;
        else if (n == 1)
            ones++;
        else
            twos++;
    }
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (zeros != 0)
        {
            nums[i] = 0;
            zeros--;
        }
        else if (ones != 0)
        {
            nums[i] = 1;
            ones--;
        }
        else
        {
            nums[i] = 2;
            twos--;
        }
    }
}