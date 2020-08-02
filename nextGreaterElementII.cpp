#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        // this stack stores indexes, not numbers
        stack<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            while (!s.empty() && curr > nums[s.top()])
            {
                res[s.top()] = curr;
                s.pop();
            }
            s.push(i);
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.size() == 1)
                break;
            int curr = nums[i];
            while (!s.empty() && curr > nums[s.top()])
            {
                res[s.top()] = curr;
                s.pop();
            }
        }

        return res;
    }
};

