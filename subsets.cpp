class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    int n;

    void backtrack(vector<int>& curr, int first, int k)
    {
        if (curr.size() == k)
        {
            res.push_back(curr);
            return;
        }
        
        for (int i = first; i < n; i++)
        {
            curr.push_back(nums[i]);
            backtrack(curr, i + 1, k);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        this->nums = nums;
        this->n = nums.size();
        // generate subsets of length from 0 to n
        for (int k = 0; k <= n; k++)
            backtrack(curr, 0, k);
        return res;
    }
};