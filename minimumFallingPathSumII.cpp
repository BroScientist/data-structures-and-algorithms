class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>> dp = arr;
        int m = arr.size(), n = arr[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int minFall = INT_MAX;
                for (int k = 0; k < n; k++)
                    if (k != j && dp[i - 1][k] < minFall)
                        minFall = dp[i - 1][k];
                dp[i][j] = minFall + arr[i][j];
            }
        
        return *min_element(begin(dp.back()), end(dp.back()));
        
    }
};