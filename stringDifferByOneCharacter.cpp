class Solution {
public:
    int diffByOne(string& s1, string& s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }
    
    bool differByOne(vector<string>& dict)
    {
        for (int i = 0; i < dict.size() - 1; i++)
            for (int j = i + 1; j < dict.size(); j++)
                if (diffByOne(dict[i], dict[j]))
                    return true;
        return false;
    }
};