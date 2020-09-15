class Solution {
public:
    int getGap(char first, char second)
    {
        return second > first ? second - first : 26 + second - first;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<vector<int>, vector<string>> map;
        for (string& str : strings)
        {
            vector<int> seq;
            for (int i = 1; i < str.size(); i++)
                seq.push_back(getGap(str[i - 1], str[i]));
            map[seq].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto& [key, value] : map)
            res.push_back(value);
        return res;
    }
};