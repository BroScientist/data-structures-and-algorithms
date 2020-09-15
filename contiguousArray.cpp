class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, vector<int>> balance;
        vector<vector<int>> points(nums.size());
        vector<int> vec = {0, 0};
        int longest = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                vec[0]++;
            else
                vec[1]++;
            
            int bal = vec[1] - vec[0];
            if (bal == 0 && i == nums.size() - 1)
                return nums.size();
            if (bal == 0)
                longest = max(longest, vec[0] * 2);
            
            balance[bal] = vec;
            points[i] = vec;
        }
        
        for (int i = 0; i < points.size(); i++)
        {
            int bal = points[i][1] - points[i][0];
            if (balance.find(bal) != balance.end())
            {
                vector<int> endPoint = balance[bal];
                int len = (endPoint[1] - points[i][1]) * 2;
                longest = max(longest, len);
            }
        }
        
        return longest;
    }
};