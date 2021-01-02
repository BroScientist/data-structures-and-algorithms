class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size(), m = votes[0].size();
        // res[i] = score sheet of the ith team (A, B, C...)
        // res[i][j] = number of votes for the jth place
        // the last place is for the character itself
        vector<vector<int>> res(m, vector<int>(27));
        unordered_map<char,int> charToIndex;
        int i = 0;
        for (char c : votes[0])
            charToIndex[c] = i++;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c = votes[i][j];
                res[charToIndex[c]][j]++;
            }
        }
        
        // make the last entry in each row the numerical representation of the letter
        for (int i = 0; i < m; i++)
            res[i][26] = votes[0][i] - 'A';
        
        sort(begin(res), end(res), [] (vector<int> a, vector<int> b)
             {
                // compare the score array of two letters until there's no longer a tie
                for (int i = 0; i < 26; i++)
                {
                    if (a[i] != b[i])
                        return a[i] > b[i];
                }
                // in the worst case two letters are tied after all the looping
                // in this case the larger letter wins
                return a[26] < b[26];
             });
        
        // convert the final element of each matrix (a number from 0~25) into a char, and add it to the final string
        string str = "";
        for (int i = 0; i < res.size(); i++)
            str += res[i][26] + 'A';
        return str;
    }
};