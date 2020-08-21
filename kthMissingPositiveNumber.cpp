class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> set;
        for (int& n : arr)
            set.insert(n);
        int missing;
        for (int n = 1; n <= arr.back(); n++)
        {
            if (set.find(n) == set.end())
                k--,missing = n;
            if (k == 0)
                return missing;
        }
        return arr.back() + k;
    }
};