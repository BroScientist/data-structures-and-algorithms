class Solution {
public:
    unordered_set<int> seen;
    unordered_map<int, list<int>> graph;
    bool dfs(int from, int target)
    {
        // if current node has not been visited, mark it as visited and call dfs with it
        if (seen.find(from) == seen.end())
        {
            seen.insert(from);
            if (from == target)
                return true;
            for (int& nei : graph[from])
                if (dfs(nei, target))
                    return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> redun;
        for (vector<int>& edge : edges)
        {
            seen.clear();
            if (dfs(edge[0], edge[1]))
                redun.push_back(edge);
            else
                graph[edge[0]].push_back(edge[1]), graph[edge[1]].push_back(edge[0]);
        }
        return redun.back();
    }
};