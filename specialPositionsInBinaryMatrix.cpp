class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // unordered_map<int, int> colOnes, rowOnes;
        vector<int> colOnes(mat[0].size()), rowOnes(mat.size());
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                    rowOnes[i]++;
            }
        }
        
        for (int j = 0; j < mat[0].size(); j++)
        {
            for (int i = 0; i < mat.size(); i++)
            {
                if (mat[i][j] == 1)
                    colOnes[j]++;
            }
        }
        
        int count = 0;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                if (mat[i][j] == 1 && rowOnes[i] == 1 && colOnes[j] == 1)
                    count++;
        return count;
    }
};