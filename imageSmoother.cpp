class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res = M;
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                int sum = M[i][j], count = 1;
                // up
                if (i > 0)
                {
                    sum += M[i - 1][j];
                    count++;
                    // upper left
                    if (j > 0)
                    {
                        sum += M[i - 1][j - 1];
                        count++;
                    }
                }
                // down
                if (i < M.size() - 1)
                {
                    sum += M[i + 1][j];
                    count++;
                    // lower right
                    if (j < M[0].size() - 1)
                    {
                        sum += M[i + 1][j + 1];
                        count++;
                    }
                }
                // left
                if (j > 0)
                {
                    sum += M[i][j - 1];
                    count++;
                    // lower left
                    if (i < M.size() - 1)
                    {
                        sum += M[i + 1][j - 1];
                        count++;
                    }
                }
                if (j < M[0].size() - 1)
                {
                    sum += M[i][j + 1];
                    count++;
                    // upper right
                    if (i > 0)
                    {
                        sum += M[i - 1][j + 1];
                        count++;
                    }
                }
                
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};