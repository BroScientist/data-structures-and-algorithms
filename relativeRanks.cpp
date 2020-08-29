class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> res(nums.size());
        vector<int> copy = nums;
        sort(begin(copy), end(copy), greater<int>());
        unordered_map<int,int> numToRank;
        for (int i = 0; i < copy.size(); i++)
            numToRank[copy[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            int rank = numToRank[nums[i]] + 1;
            if (rank == 1)
                res[i] = "Gold Medal";
            else if (rank == 2)
                res[i] = "Silver Medal";
            else if (rank == 3)
                res[i] = "Bronze Medal";
            else
                res[i] = to_string(rank);
        }
        return res;
    }
};