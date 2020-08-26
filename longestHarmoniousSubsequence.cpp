class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int& n : nums)
            freq[n]++;
        int res = 0;
        for (int& n : nums)
        {
            if (freq.find(n + 1) != freq.end())
                res = max(res, freq[n] + freq[n + 1]);
        }
        return res;
    }
};