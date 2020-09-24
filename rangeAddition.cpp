class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length);
        for (vector<int>& update : updates)
        {
            int start = update[0], end = update[1], val = update[2];
            res[start] += val;
            if (end < length - 1)
                res[end + 1] -= val;
        }
        
        partial_sum(begin(res), end(res), begin(res));
        return res;
    }
};