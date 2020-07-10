#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // for each element in nums, apply the 2 pointer technique for 2 sum
    // skip that element when encountered in loop            
    vector<vector<int>> solution;
    if (nums.size() < 3)
        return solution;
    vector<int> seen;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        // if num has already been seen, skip it to avoid duplicate solutions
        if (find(seen.begin(), seen.end(), nums[i]) != seen.end())
            continue;
        seen.push_back(nums[i]);
        vector<int> currRes;
        int start = 0, end = nums.size() - 1;
        int target = -nums[i]; // if the element is 5, we want to find two sum = -5 to make it zero

        while (start < end)
        {
            if (start == i)
                start++;
            if (end == i)
                end--;
            if (start >= end)
                break;
            if (nums[start] + nums[end] == target)
            {
                currRes.push_back(nums[i]);
                currRes.push_back(nums[start]);
                currRes.push_back(nums[end]);
                sort(currRes.begin(), currRes.end());
                if (find(solution.begin(), solution.end(), currRes) == solution.end())
                {
                    // for (int& n : currRes)
                    //     cout << n << " ";
                    // cout << endl;
                    solution.push_back(currRes);
                }
                currRes.clear();
            }
            if (nums[start] + nums[end] > target)
                end--;
            else
                start++;
        }
    }
    return solution;
}


int main() {
    vector<int> n = {-1, 0, 1, 2, -1, -4};
    threeSum(n);
    return 0;
}