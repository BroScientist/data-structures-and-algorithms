class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;
        
        set<pair<int,int>> seen;
        multiset<int> complements;
        for (int& n : nums)
            complements.insert(n);
        
        int threshold = k == 0 ? 1 : 0;

        for (int& n : nums)
        {
            if (complements.count(n + k) > threshold)
                seen.insert(make_pair(n, n + k));
            if (complements.count(n - k) > threshold)
                seen.insert(make_pair(n - k, n));
        }
            
        return seen.size();
    }
};