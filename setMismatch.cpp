class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> res(2);
        int max = 0;
        // insert all nums into set, if num is already in the set, it is the dup value
        for (int& n : nums)
        {
            if (n > max)
                max = n;
            if (set.find(n) != set.end())
                res[0] = n;
            set.insert(n);
        }
        // loop to max + 1 in case the input is something like [1,2,2]
        for (int i = 1; i <= max + 1; i++)
        {
            if (set.find(i) == set.end())
            {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};