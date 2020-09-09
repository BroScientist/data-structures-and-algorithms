class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<pair<vector<char>, vector<char>>> seen;
        int count = 0;
        for (string& s : A)
        {
            pair<vector<char>, vector<char>> pair;
            for (int i = 0; i < s.size(); i += 2)
                pair.first.push_back(s[i]);
            for (int i = 1; i < s.size(); i += 2)
                pair.second.push_back(s[i]);
            sort(begin(pair.first), end(pair.first));
            sort(begin(pair.second), end(pair.second));

            if (seen.find(pair) == seen.end())
                count++, seen.insert(pair);
        }
        return count;
    }
};