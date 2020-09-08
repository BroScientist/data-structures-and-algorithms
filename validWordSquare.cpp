class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        string word = "";
        for (int col = 0; col < words.size(); col++)
        {
            word = "";
            for (int i = 0; i < words[col].size(); i++)
            {
                if (i == words.size())
                    return false;
                word += words[i][col];
            }
            if (word != words[col])
                return false;
        }
        return true;
    }
};