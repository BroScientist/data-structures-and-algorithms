class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size())
            return false;
        unordered_map<string, unordered_set<string>> dict;
        for (vector<string>& pair : pairs)
        {
            dict[pair[0]].insert(pair[1]);
            dict[pair[1]].insert(pair[0]);
        }
        for (int i = 0; i < words1.size(); i++)
        {
            if (words1[i] != words2[i])
            {
                if (dict.find(words1[i]) != dict.end() && dict[words1[i]].count(words2[i]) == 0)
                    return false;
                if (dict.find(words2[i]) != dict.end() && dict[words2[i]].count(words1[i]) == 0)
                    return false;
            }
        }
        return true;
    }
};