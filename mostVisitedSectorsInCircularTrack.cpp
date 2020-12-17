class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        
        unordered_map<int,int> freq;
        freq[rounds[0]]++;
        vector<int> res;
        int maxFreq = 0;
        
        for (int i = 0; i < rounds.size() - 1; i++)
        {
            int start = rounds[i], finish = rounds[i + 1];
            // case start < finish
            if (start < finish)
                for (int j = start + 1; j <= finish; j++)
                    freq[j]++;
            // case start >= finish (loops around)
            else
            {
                for (int j = start + 1; j <= n; j++)
                    freq[j]++;
                for (int j = 1; j <= finish; j++)
                    freq[j]++;
            }
        }
        
        for (auto& [key, val] : freq)
            if (val > maxFreq)
                maxFreq = val;
        
        for (auto& [key, val] : freq)
            if (val == maxFreq)
                res.push_back(key);
        
        sort(begin(res), end(res));
        return res;
    }
};