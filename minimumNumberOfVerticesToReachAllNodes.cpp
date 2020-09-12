class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n);
        for (vector<int>& edge : edges)
            indegrees[edge[1]]++;
        vector<int> res;
        for (int i = 0; i < indegrees.size(); i++)
            if (indegrees[i] == 0)
                res.push_back(i);
        return res;
    }
};