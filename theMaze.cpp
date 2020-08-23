class Solution {
public:
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, vector<vector<bool>>& visited)
    {
        if (visited[start[0]][start[1]])
            return false;
        if (start[0] == destination[0] && start[1] == destination[1])
            return true;
        visited[start[0]][start[1]] = true;
        
        int right = start[1] + 1, left = start[1] - 1, up = start[0] - 1, down = start[0] + 1;
        while (right < maze[0].size() && maze[start[0]][right] == 0)
            right++;
        if (dfs(maze, vector<int>() = {start[0], right - 1}, destination, visited))
            return true;
        
        while (left >= 0 && maze[start[0]][left] == 0)
            left--;
        if (dfs(maze, vector<int>() = {start[0], left + 1}, destination, visited))
                return true;

        while (down < maze.size() && maze[down][start[1]] == 0)
            down++;
        if (dfs(maze, vector<int>() = {down - 1, start[1]}, destination, visited))
            return true;
        
        while (up >= 0 && maze[up][start[1]] == 0)
            up--;
        if (dfs(maze, vector<int>() = {up + 1, start[1]}, destination, visited))
            return true;

        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size()));
        return dfs(maze, start, destination, visited);
    }
};

